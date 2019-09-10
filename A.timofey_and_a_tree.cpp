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
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
vi g[maxN];
int color[maxN];
int v;
bool visited[maxN];

bool dfs( int a )
{
	stack<int> st;
	visited[a] = true;
	st.push(a);
	int col = color[a];
	int aux;
	while(!st.empty()) 
	{
	    aux = st.top();
	    st.pop();
	    if ( color[aux] != col ) return false;
	    for ( int y : g[aux] )
	    {
	    	if (!visited[y])
	    	{
	    		visited[y] = true;
	    		st.push(y);
	    	}
	    }
	}
	return true;
}


bool valid ( int a )
{
	FOR(i,1,v+1) visited[i] = false;
	for ( int x : g[a] )
	{
		visited[a] = true;
		if ( !dfs(x) ) return false;
	}
	return true;
}

int main()
{	
	ri(v);
	int a, b;
	int c = -1, d = -1;
	FOR(i,0,v-1)
	{
		rii(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}
	FOR(i,0,v) ri(color[i+1]);
	FOR(i,1,v+1)
	{
		for ( int x : g[i])
		{
			if ( color[i] != color[x]) 
			{
				c = i;
				d = x;
			}
		}
		if (c==i) break;
	}
	if (c == d) printf("YES\n1\n");
	else
	{
		if ( valid(c) )
		{
			printf("YES\n%d\n",c);
		}
		else if ( valid(d) )
		{
			printf("YES\n%d\n",d);
		}
		else printf("NO\n");
	}


	return 0;
}