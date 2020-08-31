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

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
	int mn, mn_cnt;
	void merge(STN& L, STN& R) {
		mn = min(L.mn, R.mn);
		mn_cnt = 0;
		if ( mn == L.mn )
			mn_cnt += L.mn_cnt;
		if ( mn == R.mn )
			mn_cnt += R.mn_cnt;
	}
	void operator=(int a) {
		mn = a;
		mn_cnt = 1;
	}
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = A[l];
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STB(L, l, m); STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
	if (x == l && y == r) return ST[id];
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (x >= m) return STQ(x, y, R, m, r);
	if (y <= m) return STQ(x, y, L, l, m);
	STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
	return res.merge(ln, rn), res;
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
	int q;
	rii(N, q);
	FOR(i, 0, N) {
		ri(A[i]);
	}
	STB();
	FOR(i, 0, q) {
		int typ;
		ri(typ);
		if (typ == 1) {
			int ind;
			ll v;
			scanf("%d %lld", &ind, &v);
			STU(ind, v);
		}
		else {
			int l, r;
			rii(l, r);
			STN ans = STQ(l, r);
			printf("%d %d\n", ans.mn, ans.mn_cnt);

		}
	}

	return 0;
}