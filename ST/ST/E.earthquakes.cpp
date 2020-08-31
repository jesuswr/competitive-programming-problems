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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN], ans;
struct STN {
	int mn;
	void merge(STN& L, STN& R) {
		mn = min(L.mn, R.mn);
	}
	void operator=(int a) {
		mn = a;
	}
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = 1e9 + 10;
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STB(L, l, m); STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
void STQ(int x, int y, int p, int id = 1, int l = 0, int r = N) {
	if (ST[id].mn > p || x >= r || y <= l)
		return;
	if (r - l < 2) {
		ST[id] = 1e9 + 10;
		ans++;
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (x >= m) STQ(x, y, p, R, m, r);
	else if (y <= m) STQ(x, y, p, L, l, m);
	else STQ(x, m, p, L, l, m), STQ(m, y, p, R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
void STU(int p, int x, int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = x;
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (p < m) STU(p, x, L, l, m);
	else STU(p, x, R, m, r);
	ST[id].merge(ST[L], ST[R]);
}

int main() {
	int m;
	rii(N, m);
	STB();
	FOR(_, 0, m) {
		int type; ri(type);
		if (type == 1) {
			int i, h; rii(i, h);
			STU(i, h);
		}
		else {
			int l, r, p;
			riii(l, r, p);
			ans = 0;
			STQ(l, r, p);
			printf("%d\n", ans);
		}
	}

	return 0;
}