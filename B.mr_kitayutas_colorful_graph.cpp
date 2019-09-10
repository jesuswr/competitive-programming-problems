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

struct node
{
	int to, color;
};

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
vector<node> g[105];
bool visited[105];

bool dfs ( int t , int f , int c )
{
	stack<int> st;
	st.push(t);
	visited[t] = true;
	int aux;
	while(!st.empty()) 
	{
	    aux = st.top();
	    st.pop();
	    if ( aux == f ) return true;
	    for ( node x : g[aux] )
	    {
	    	if ( x.color == c && !visited[x.to] )
	    	{
	    		st.push(x.to);
	    		visited[x.to] = true;
	    	}
	    }
	}
	return false;
}

int main()
{
	int v , e;
	rii(v,e);
	int a, b , c;
	for (int i = 0; i < e; ++i)
	{
		riii(a,b,c);
		g[a].pb({b,c});
		g[b].pb({a,c});
	}
	int q;
	ri(q);
	unordered_map<int,bool> mp;
	for (int i = 0; i < q; ++i)
	{
		mp.clear();
		rii(a,b);
		int ans = 0;
		for ( node x : g[a] )
		{
			if ( mp.find(x.color) != mp.end()) continue;	
			//printf("VA A PROBAR CON %d Y %d Y %d\n",a,b,x.color);
			FOR(j,1,101) visited[j] = false;
			if ( dfs(a,b,x.color) )
			{
				ans++;
				mp[x.color] = true;
				//printf("con ese color sumo %x\n", x.color);
			}

		}
		printf("%d\n", ans);
	}
	return 0;
}