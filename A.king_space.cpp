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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1001; // CAMBIAR ESTE

// GJNM
int n;
bool v[maxN][maxN];

bool valid ( int x , int y )
{
	if ( x == -1 || x == n) return false;
	if ( y == -1 || y == n) return false;
	return true;
}

void dfs1( int x , int y )
{
	FOR(i,0,n)
	{
		v[ x ][ i ] = 1;
		v[ i ][ y ] = 1;
	}
	int i = 1;
	while ( valid ( x +i, y + i ))
	{
		v[x+i][y+i] = 1;
		i++;
	}
	i = 1;
	while ( valid ( x -i, y + i ))
	{
		v[x-i][y+i] = 1;
		i++;
	}
	i = 1;
	while ( valid ( x +i, y - i ))
	{
		v[x+i][y-i] = 1;
		i++;
	}
	i = 1;
	while ( valid ( x -i, y - i ))
	{
		v[x-i][y-i] = 1;
		i++;
	}
}

bool dfs2( int x , int y , int X , int Y )
{
	stack<pii> st;
	st.push({x,y});
	while( !st.empty() )
	{
		x = st.top().f;
		y = st.top().s;
		st.pop();
		if ( v[x][y] ) continue;
		if ( x == X && y == Y ) return true;
		v[x][y] = 1;
		if (valid(x+1,y)) st.push({x+1,y});
		if (valid(x+1,y+1)) st.push({x+1,y+1});
		if (valid(x+1,y-1)) st.push({x+1,y-1});
		if (valid(x,y+1)) st.push({x,y+1});
		if (valid(x,y-1)) st.push({x,y-1});
		if (valid(x-1,y)) st.push({x-1,y});
		if (valid(x-1,y+1)) st.push({x-1,y+1});
		if (valid(x-1,y-1)) st.push({x-1,y-1});
	}
	return false;
}


int main()
{
	int ax, ay, bx, by, cx, cy;
	ri(n);
	rii(ax,ay);
	rii(bx,by);
	rii(cx,cy);


	dfs1(ax-1,ay-1);

	

	bool ans = dfs2(bx-1,by-1,cx-1,cy-1);
	
	

	ans ? printf("YES\n") : printf("NO\n");
	return 0;
}