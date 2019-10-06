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
const int maxN = 101; // CAMBIAR ESTE

// GJNM
int mat[maxN+2][maxN+2];
int n , m;
int mx = 0;

bool valid ( int i , int j , int x)
{
	if ( mat[i][j] == -1 && ( mat[i+1][j] == x-1 || mat[i-1][j] == x-1 || mat[i][j-1] == x-1 || mat[i][j+1] ==x-1) ) return true;
	return false;
}

bool sett ( int x )
{
	bool ret = false;
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if ( valid(i+1,1+j,x) )
			{
				mat[i+1][1+j] = x;
				ret = true;
				mx = max(mx,x);
			}
		}
	}
	return ret;

}


int main()
{
	rii(n,m);
	char c;
	FOR(i,0,n)
	{
		scanf("%*c");
		FOR(j,0,m)
		{
			scanf("%c",&c);
			if ( c == '.' ) mat[1+i][1+j] = 0;
			else mat[1+i][1+j] = -1;
		}
		//printf("\n");
	}
	int currentplacing = 1;
	bool change = true;
	while ( change )
	{
		change = sett( currentplacing );
		currentplacing++;
	}
	if ( mx >= 10)
	{
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if ( mat[i+1][j+1] == 0 ) printf("...");
				else if ( mat[1+i][j+1] >= 10)  printf(".%d", mat[i+1][j+1]);
				else printf("..%d", mat[i+1][j+1]);
			}
			printf("\n");
		}
	}
	else
	{
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if ( mat[i+1][j+1] == 0 ) printf("..");
 				else printf(".%d", mat[i+1][j+1]);

			}
			printf("\n");
		}
	}
	return 0;
}