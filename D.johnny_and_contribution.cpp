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
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
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
const int maxN = 6e5; // CAMBIAR ESTE

// GJNM
int v, e;
vi G[maxN];
pii want[maxN];
int mn[maxN];
bool vis[maxN];

bool check(int i){
	int u = want[i].S; // nodo
	int c = want[i].F; // nro que quiere
	vis[u] = true;
	if ( mn[u] != c ){
		return false;
	}

	for(auto z : G[u]){
		if ( vis[z] )
			continue;
		if ( mn[z] == c )
			mn[z]++;
	}
	return true;
}

int main(){
	rii(v,e);
	FOR(i,0,e){
		int a,b;
		rii(a,b);
		a--,b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	FOR(i,0,v){
		ri(want[i].F);
		want[i].F--;
		want[i].S = i;
	}
	sort(want, want+v);
	vi ans;
	FOR(i,0,v){
		if ( check(i) )
			ans.pb(want[i].S);
		else{
			printf("-1\n");
			return 0;
		}
	}
	for(auto x : ans )
		printf("%d ",x+1 );
	printf("\n");
	return 0;
}