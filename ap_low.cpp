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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int t = 0;
vi g[100];
int v, e;
int low[100];
int d[100];
bool vis[100];
int parent[100];
map<int,bool> mp;

void dfs( int x )
{
	vis[x] = true;
	int cont = 0;
	low[x] = d[x] = t;
	t++;
	for ( int y : g[x] )
	{
		if ( y == parent[x] ) continue;
		if ( !vis[y] )
		{
			cont++;
			d[y] = d[x] + 1;
			parent[y] = x;
			dfs(y);
			low[x] = min( low[x] , low[y] );
			if ( parent[x] != -1 && d[x] <= low[y] ) mp[x] = true;
		}
		else
		{
			low[x] = min( low[x] , d[y]);
		}
		
	}
	
	if ( x == 0 && cont >= 2 ) mp[x] = true;
}

int main()
{
	ri(v);
	FOR(i,0,v)
	{
		int a , b;
		rii( a,b );
		g[a].pb(b);
		g[b].pb(a);
		vis[a] = vis[b] = false;
		mp[a] = false;
		mp[b] = false;

	}
	low[0] = 0;
	d[0] = 0;
	parent[0] = -1;
	dfs(0);
	for ( auto h : mp )
	{
		if ( h.second )
		{
			printf("%d y\n", h.first);
		}
		else
		{
			printf("%d n\n", h.first);
		}
	}
	//FOR(i,0,v) printf("NODE = %d : LOW = %d : D = %d \n", i , low[i] , d[i]);
	//printf("\n");
	return 0;
}