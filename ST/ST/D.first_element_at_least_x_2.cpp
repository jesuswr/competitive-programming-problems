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
	int mx;
	void merge(STN& L, STN& R) {
		mx = max(L.mx, R.mx);
	}
	void operator=(int a) {
		mx = a;
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
int STQ(int k, int pos, int id = 1, int l = 0, int r = N) {
	if (pos >= r || ST[id].mx < k)
		return -1;
	if (r - l < 2)
		return (ST[id].mx >= k ? l : -1);
	int m = (l + r) >> 1, L = id << 1, R = L | 1;

	int ret = -1;
	if (ST[L].mx >= k)
		ret = STQ(k, pos, L, l, m);
	if (ret == -1)
		ret = STQ(k, pos, R, m, r);
	return ret;


	//if (r - l < 2 ) {
	//	return (ST[id].mx >= k ? l : -1);
	//}
	//int m = (l + r) >> 1, L = id << 1, R = L | 1;
	//if (ST[L].mx >= k)
	//	return STQ(k, L, l, m);
	//else if ( ST[R].mx >= k)
	//	return STQ(k, R, m, r);
	//else
	//	return -1;
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
	FOR(_, 0, q) {
		int t;
		ri(t);
		if ( t == 1 ) {
			int i, v;
			rii(i, v);
			STU(i, v);
		}
		else {
			int k, l;
			rii(k, l);
			printf("%d\n", STQ(k, l));
		}
	}

	return 0;
}