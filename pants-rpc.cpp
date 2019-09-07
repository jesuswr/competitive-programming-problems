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

#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);
#define rl(a) scanf("%lld", &a);
#define rll(a,b) scanf("%lld %lld", &a, &b);
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
map<string,int> mp;
int n, m;
vi g[200];
int visited[200];

bool dfs( int a , int b )
{
	if ( a == b ) return true;
	visited[a] = true;
	for ( int c : g[a] )
	{
		if ( !visited[c] )
		{
			if ( dfs(c,b) ) return true;
		}
	}
	return false;
}



int main()
{
	rii(n,m);
	int cont = 0;
	string aux1, aux2, aux3, aux4, aux5;
	for (int i = 0; i < n; ++i)
	{
		cin >> aux1 >> aux2 >> aux3 >> aux4 >> aux5;
		if ( mp.find(aux1) == mp.end() ) 
		{
			mp[aux1] = cont;
			cont++;
		}
		if ( mp.find(aux5) == mp.end() ) 
		{
			mp[aux5] = cont;
			cont++;
		}
		g[mp[aux1]].push_back(mp[aux5]);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> aux1 >> aux2 >> aux3 >> aux4 >> aux5;
		if ( mp.find(aux1) == mp.end() || mp.find(aux5) == mp.end()) 
		{
			printf("Pants on Fire\n" );
			continue;
		}
		int x = mp[aux1];
		int y = mp[aux5];
		for (int i = 0; i <= cont; ++i)
		{
			visited[i] = false;
		}
		if ( dfs ( x, y ) )
		{
			printf("Fact\n");
			continue;
		}
		for (int i = 0; i <= cont; ++i)
		{
			visited[i] = false;
		}
		if ( dfs ( y , x ) )
		{
			printf("Alternative Fact\n");
			continue;
		}
		printf("Pants on Fire\n");
	}

	return 0;
}