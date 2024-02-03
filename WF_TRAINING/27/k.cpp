#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ii deg[MAXN];
ii ndeg[MAXN];

vi G[MAXN];

int sumD, nsumD;
int n, m;

int main() {
	rii(n,m);
	FOR(i,0,n) deg[i] = ndeg[i] = {0, i};
	FOR(i,0,m) {
		int u, v;
		rii(u, v);
		deg[u].F++, deg[v].F++;
	}

	sumD = 2*m;
	nsumD = 2*(n-1);

	sort(deg, deg+n, greater<ii>());
	int ans = 0;
	FOR(i,0,n) {
		if (sumD - nsumD > deg[i].F-1) {
			sumD -= deg[i].F - 1;deg[i].F = 1; 
		}
		else {
			deg[i].F -= sumD - nsumD;
			ans = i + (sumD - nsumD > 0);
			sumD = nsumD;
			break;
		}
	}

	sort(deg, deg+n, greater<ii>());

	queue<int> open;
	FOR(i,0,deg[0].F) open.push(deg[0].S);

	FOR(i,1,n) {
		int v = open.front(); open.pop();
		// printf("%d %d\n", v, deg[i].S);
		G[v].pb(deg[i].S);

		FOR(j,1,deg[i].F) open.push(deg[i].S);
	}

	printf("%d\n", ans);
	printf("%d %d\n", n, n-1);
	FOR(i,0,n) for (auto u : G[i]) printf("%d %d\n", i, u);









	return 0;
}
