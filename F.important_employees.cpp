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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e6+10; // CAMBIAR ESTE

// GJNM
int v,e,vis[maxN],low[maxN],t, parent[maxN],d[maxN];
vi g[maxN];
map<int,bool> ans;

void dfs( int x )
{
	vis[x] = 1;
	t++;
	low[x] = d[x] = t;
	int count = 0;
	for( int y : g[x] )
	{
		if ( !vis[y] )
		{
			count++;
			parent[y] = x;
			dfs(y);

			low[x] = min( low[x] , low[y] );
			if ( parent[x] != -1 && low[y] >= d[x] )
			{
				ans[x] = true;
			}
		}
		else if ( parent[x] != y )
		{
			low[x] = min( low[x] , d[y] );
		}
	}
	if ( parent[x] == -1 && count > 1 ) ans[x] = true;
}


int main()
{
	while (1){
		ri(v);
		if ( v == 0 ) break;
		int a,b;
		t = 0;
		FOR(i,0,v)
		{
			rii(a,b);
			g[a].pb(b);
			g[b].pb(a);
			parent[a] = parent[b] = -2;
			vis[a] = vis[b] = 0;
			ans[a] = ans[b] = false;
		}
		for ( auto l : ans )
		{
			if ( !vis[l.first] )
			{
				parent[l.first] = -1;
				dfs( l.first);
			}
		}
		for ( auto l : ans )
		{
			g[l.first].clear();
			printf("%d ", l.first);
			( l.second ? printf("y\n") : printf("n\n"));
		}
		ans.clear();
	}
	return 0;
}