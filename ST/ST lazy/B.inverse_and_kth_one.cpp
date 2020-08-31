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
const int MAXN = 1e5; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM

// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
	int val;
	void merge(STN& L, STN& R) {
		val = L.val + R.val;
	}
	void operator=(ll a) {}
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = A[l];
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STB(L, l, m); STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r) {
	lzy[id] = 1 - lzy[id];
	ST[id].val = (r - l) - ST[id].val;
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	upd(L, l, m);
	upd(R, m, r);
	lzy[id] = 0;
}
int STQ(int k, int id = 1, int l = 0, int r = N) {
	if (r - l < 2)
		return l;
	if (lzy[id])
		shift(id, l, r);
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	int l_cnt = ST[L].val;
	if (l_cnt >= k)
		return STQ(k, L, l, m);
	else
		return STQ(k - l_cnt, R, m, r);
}
void STU(int x, int y, int id = 1, int l = 0, int r = N) {
	if (x >= r || y <= l) return;
	if (x <= l && y >= r) {
		upd(id, l, r);
		return;
	}
	if (lzy[id])
		shift(id, l, r);
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STU(x, y, L, l, m);
	STU(x, y, R, m, r);
	ST[id].merge(ST[L], ST[R]);
}


int main() {
	int m;
	rii(N, m);
	STB();
	FOR(_, 0, m) {
		int type; ri(type);
		if (type == 1) {
			int l, r; rii(l, r);
			STU(l, r);
		}
		else {
			int k; ri(k);
			printf("%d\n", STQ(k + 1));
		}
	}
	return 0;
}