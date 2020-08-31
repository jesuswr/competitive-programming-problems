#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM

// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
	int sum_black;
	int cnt_black;
	int left, right;
	void merge(STN& L, STN& R) {
		sum_black = L.sum_black + R.sum_black;
		cnt_black = L.cnt_black + R.cnt_black;
		left = L.left; right = R.right;
		if (L.right == R.left && L.right == 0)
			cnt_black--;
	}
	void operator=(ll a) {
		left = 1;
		right = 1;
		sum_black = 0;
		cnt_black = 0;
	}
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	lzy[id] = -1;
	if (r - l < 2) {
		ST[id] = 1;
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STB(L, l, m); STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, int x) {
	lzy[id] = x;
	if (x == 1) {
		ST[id].cnt_black = 0;
		ST[id].sum_black = 0;
		ST[id].left = 1;
		ST[id].right = 1;
	}
	else {
		ST[id].cnt_black = 1;
		ST[id].sum_black = (r - l);
		ST[id].left = 0;
		ST[id].right = 0;
	}
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	upd(L, l, m, lzy[id]);
	upd(R, m, r, lzy[id]);
	lzy[id] = -1;
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
	if (x == l && y == r) return ST[id];
	if (lzy[id] != -1)
		shift(id, l, r);
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (x >= m) return STQ(x, y, R, m, r);
	if (y <= m) return STQ(x, y, L, l, m);
	STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
	return res.merge(ln, rn), res;
}
void STU(int x, int y, int v, int id = 1, int l = 0, int r = N) {
	if (x >= r || y <= l) return;
	if (x <= l && y >= r) {
		upd(id, l, r, v);
		return;
	}
	if (lzy[id] != -1)
		shift(id, l, r);
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STU(x, y, v, L, l, m);
	STU(x, y, v, R, m, r);
	ST[id].merge(ST[L], ST[R]);
}

int main() {
	N = MAXN;
	STB();
	int n;
	ri(n);
	FOR(_, 0, n) {
		char c; int l, r;

		scanf("%*c%c %d %d", &c, &l, &r);
		l += 500000; r;
		if (c == 'W') {
			STU(l, l+r, 1);
		}
		else { // 1
			STU(l, l+r, 0);
		}
		auto ans = STQ(0, N);
		printf("%d %d\n", ans.cnt_black, ans.sum_black);
	}

	return 0;
}