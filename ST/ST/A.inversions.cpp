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
int N;
pii A[MAXN];
int B[MAXN];
struct STN {
	int sum;
	void merge(STN& L, STN& R) {
		sum = L.sum + R.sum;
	}
	void operator=(int a) {
		sum = a;
	}
};
STN ST[4 * MAXN];
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
	if (x == l && y == r) return ST[id];
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (x >= m) return STQ(x, y, R, m, r);
	if (y <= m) return STQ(x, y, L, l, m);
	STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
	return res.merge(ln, rn), res;
}
void STU(int p, int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = 1;
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (p < m) STU(p, L, l, m);
	else STU(p, R, m, r);
	ST[id].merge(ST[L], ST[R]);
}

int main() {
	ri(N);
	FOR(i, 0, N) {
		ri(A[i].F);
		A[i].S = i;
	}
	ll ans = 0;
	sort(A, A + N, greater<pii>());
	FOR(i, 0, N) {
		B[A[i].S] = STQ(0, A[i].S + 1).sum;
		STU(A[i].S);
	}
	FOR(i, 0, N) {
		printf("%d ", B[i]);
	}
	printf("\n");
	return 0;
}