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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int a[maxN];


void solve() {
	int n, k, z;
	riii(n, k, z);
	FOR(i, 0, n) {
		ri(a[i]);
	}

	int ans = 0;
	FOR(i, 0, z + 1) {
		int pos = k - 2 * i;
		if ( pos < 0 )
			break;
		int mx = 0, sum = 0;
		FOR(j, 0, pos + 1) {
			if ( j < n - 1 )
				mx = max(mx, a[j] + a[j + 1]);
			sum += a[j];
		}
		ans = max(ans, sum + mx * i);
	}
	printf("%d\n", ans);
}


int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}