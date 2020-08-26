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
ll a[3], b[3];
void solve() {
	rll(a[0], a[1]), rl(a[2]);
	rll(b[0], b[1]), rl(b[2]);

	ll ans = 0;
	ll move = min(a[2], b[1]);
	ans += 2ll * move;
	a[2] -= move;
	b[1] -= move;

	move = min(a[2], b[2]);
	a[2] -= move;
	b[2] -= move;

	move = min(a[0], b[2]);
	a[0] -= move;
	b[2] -= move;

	move = min(a[1], b[2]);
	ans -= 2ll * move;
	a[1] -= move;
	b[2] -= move;

	printf("%lld\n", ans);


}


int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}