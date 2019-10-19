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
int mat[101][101];
int rows[101];
int col[101];

int main()
{
	int r,c;
	rii(r,c);
	FOR(i,0,r)
	{
		ri(rows[i]);
		FOR(j,0,c) mat[i][j] = rows[i];
	}
	FOR(i,0,c)
	{
		ri(col[i]);
		FOR(j,0,r) mat[j][i] = min( col[i] , mat[j][i]);
	}
	
	FOR(i,0,r)
	{
		bool eq = false;
		bool mor = false;
		FOR(j,0,c)
		{
			if ( mat[i][j] == rows[i] ) eq = true;
			else if ( mat[i][j] > rows[i] ) mor = true;
		}
		if ( !eq || mor )
		{
			printf("impossible\n");
			return 0;
		}
	}

	FOR(j,0,c)
	{
		bool eq = false;
		bool mor = false;
		FOR(i,0,r)
		{
			if ( mat[i][j] == col[j] ) eq = true;
			else if ( mat[i][j] > col[j] ) mor = true;
		}
		if ( !eq || mor )
		{
			printf("impossible\n");
			return 0;
		}
	}
	printf("possible\n");

	return 0;
}