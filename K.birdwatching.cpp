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
#include <bitset>

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
const int maxN = 100006; // CAMBIAR ESTE

// GJNM
int v,e,start;
vi G[maxN];
vi pos_ans;

int t;
int low[maxN], disc[maxN], comp[maxN];
bool vis[maxN];
vi COMP[maxN];
stack<int> st;
set<int> g[maxN];

void tarjan(int u){
	low[u] = disc[u] = t++;
	vis[u] = true;
	st.push(u);

	for(auto v : G[u]){
		if ( low[v] == -1 )
			tarjan(v);
		if ( vis[v] )
			low[u] = min(low[u], low[v]);
	}

	if ( low[u] == disc[u] ){
		while(1){ // Los que salgan de la pila en este ciclo son de la misma comp
			int v = st.top();
			st.pop();
			vis[v] = false;
			comp[v] = u;
			if ( u == v )
				break;
		}
	}
}

int dp[maxN];

bool dfs(int x, int mode = 1){
	if ( mode == 1 ){
		if ( COMP[x].size() >= 1 )
			return true;
		if ( dp[x] == 1 )
			return true;
		if ( dp[x] == -1 )
			return false;
		for(auto y : g[x])
			if ( dfs(y) ){
				dp[x] = 1;
				return true;
			}
		dp[x] = -1;
		return false;
	}
	else{
		for(auto y : g[x])
			if ( dfs(y) )
				return true;
		return false;
	}
}

int main(){
	riii(v, e, start);
	FOR(i,0,v)
		disc[i] = low[i] = -1;
	FOR(i,0,e){
		int a,b;
		rii(a,b);
		if ( b == start ){
			pos_ans.pb(a);
			continue;
		}
		G[a].pb(b);
	}
	
	FOR(i,0,v){
		if ( low[i] == -1 )
			tarjan(i);
	}

	for(auto x : pos_ans)
		COMP[comp[x]].pb(x);

	FOR(i,0,v){
		for(auto y : G[i]){
			if ( comp[i] != comp[y] )
				g[comp[i]].insert(comp[y]);
		}
	}

	vector<int> ans;
	for( auto x : pos_ans ){
		if ( COMP[comp[x]].size() > 1 )
			continue;
		if ( dfs(comp[x], 0) )
			continue;
		ans.pb(x);
	}
	printf("%d\n",(int)ans.size() );
	for(auto x : ans)
		printf("%d\n", x);	
	return 0;
}