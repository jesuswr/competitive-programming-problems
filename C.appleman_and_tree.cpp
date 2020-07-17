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
const int maxN = 2e5; // CAMBIAR ESTE
const ll MOD = 1000000007;

// GJNM
int V, ROOT = -1;
vi G[maxN];
int BLACK[maxN];
ll LEN[maxN];


void dfs(int v, int l, int f = -1){
	LEN[v] = l;
	if ( BLACK[v] )
		l = 0;

	for(auto w : G[v]){
		if ( f == w )
			continue;
		dfs(w,l+1,v);
	}
}

int main() {
	ri(V);
	FOR(i, 1, V ) {
		int a; ri(a);
		G[a].pb(i), G[i].pb(a);
	}
	FOR(i, 0, V) {
		ri(BLACK[i]);
		if ( BLACK[i] ){
			ROOT = i;
		}
	}

	dfs(ROOT,0);
	ll ans = 1;

	FOR(i,0,V){
		if ( BLACK[i] && i != ROOT ){
			ans = ans*LEN[i] %MOD;
		}
	}
	printf("%lld\n", ans);

	return 0;

}