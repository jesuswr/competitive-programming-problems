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
int v , e , s , t;
vi g[101];
ll mat[101][11];
set<int> created[11];

ll expand ( int x , int ti )
{
	ll ret = 0;
	for ( int y : g[x] )
	{
		mat[y][ti] += mat[x][ti-1];
		ret += mat[x][ti-1];
		created[ti].insert(y);
	}
	return ret;
}

int main()
{
	rii(v,e);rii(s,t);
	int a , b;
	FOR(i,0,e)
	{
		rii(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}
	mat[s][0] = 1;
	created[0].insert(s);
	if ( t == 0 ) printf("1\n");
	FOR(i,1,t+1)
	{
		ll ans = 0;
		for ( int x : created[i-1] )
		{
			ans += expand( x , i );
		}
		if ( i == t ) printf("%lld\n", ans);
	}

	return 0;
}