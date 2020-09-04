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
const int MAXN = 2e5; // CAMBIAR ESTE
const int MAXK = 25;

// GJNM
int n, q;
int a[MAXN];
int st[MAXN][MAXK];

void precompute() {
	FOR(i, 0, n) {
		st[i][0] = a[i];
	}

	FOR(k, 1, MAXK) {
		for (int i = 0; i + (1 << k) - 1 < n; ++i) {
			st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
		}
	}
}

int query(int l, int r) {
	int ans = 1e9 + 10;
	ROF(k, MAXK - 1, -1) {
		if ( (1 << k) <= r - l + 1) {
			ans = min(ans, st[l][k]);
			l += (1 << k);
		}
	}
	return ans;
}



int main() {
	ri(n);
	FOR(i, 0, n) {
		ri(a[i]);
	}
	precompute();
	ri(q);
	while (q--) {
		int l, r; rii(l, r);
		printf("%d\n", query(l, r));
	}

	return 0;
}