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
const int maxN = 1e4+5; // CAMBIAR ESTE

// GJNM
vi g[maxN];
int vis[maxN];
bool ans;

void bfs( int a )
{
	queue<int> q;
	vis[a] = 0;
	q.push(a);
	while ( !q.empty() )
	{
		int x = q.front();
		q.pop();
		for ( int y : g[x] )
		{
			if ( vis[y] == -1 )
			{
				vis[y] = 1 - vis[x];
				q.push(y);
			}
			else 
			{
				if ( vis[y] == vis[x] )
				{
					ans = false;
					return;
				}
			}
		}
	}
}

int main()
{
	int w;
	while ( true )
	{
		ri(w);
		if ( w == 0 ) break;
		FOR(i,0,w)
		{
			int a,b;
			rii(a,b);
			vis[a] = vis[b] = -1;
			g[a].pb(b);
			g[b].pb(a);
		}
		ans = true;
		bfs(1);
		if (ans)printf("yes\n");
		else printf("no\n");
		FOR(i,1,maxN) g[i].clear();
	}
	return 0;
}