#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
vi G[MAXN];

ii dfs(int u) {
	ii r = {1, 0};
	for (int v : G[u]) {
		ii rv = dfs(v);
		r.S += max(rv.S, rv.F);
		r.F = max(r.F, rv.F + 1);
	}
	return r;
}

int main() {
	ri(N);
	FOR(i, 1, N) {
		int pi; ri(pi);
		G[pi - 1].pb(i);
	}
	printf("%d\n", max(dfs(0).F, dfs(0).S));
	return 0;
}