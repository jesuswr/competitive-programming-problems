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
const int MAXN = 1e6; // CAMBIAR ESTE

// GJNM
char a[MAXN], b[MAXN];


void solve() {
	int n;
	ri(n);
	scanf("%s", a);
	scanf("%s", b);
	vi ans;

	FOR(i, 0, n - 1) {
		if ( a[i] != a[i + 1] )
			ans.pb(i + 1);
	}
	if ( a[n - 1] == '1' )
		ans.pb(n);

	char act = '0';
	ROF(i, n - 1, -1) {
		if ( b[i] != act ) {
			ans.pb(i + 1);
			act = (act == '1' ? '0' : '1');
		}
	}
	printf("%d ", (int)ans.size());
	for (auto x : ans)
		printf("%d ", x);
	printf("\n");
}



int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}