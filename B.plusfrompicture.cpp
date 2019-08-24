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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

	int h,w;
char mat[501][501];

bool check( int a, int b)
{
	return mat[a][b+1] == '*' && mat[a][b-1] == '*' && mat[a+1][b] == '*' && mat[a-1][b] == '*';
}

void clean(int i, int j)
{
	int auxI, auxJ;
	mat[i][j] = '.';
	auxI = i-1;
	while(auxI >= 0 && (mat[auxI][j] =='*')) 
	{
	    mat[auxI][j]='.';
	    auxI--;
	}
	auxI = i+1;
	while(auxI < h && (mat[auxI][j] =='*'))
	{
	    mat[auxI][j]='.';
	    auxI++;
	}
	auxJ = j-1;
	while(auxJ >= 0 && (mat[i][auxJ] =='*'))
	{
	    mat[i][auxJ]='.';
	    auxJ--;
	}
	auxJ = j+1;
	while(auxJ < w && (mat[i][auxJ] =='*') )
	{
	    mat[i][auxJ]='.';
	    auxJ++;
	}
	
}

int main()
{
	rii(h,w);
	for (int i = 0; i < h; ++i)
	{
		scanf("%s",&mat[i][0]);
	}
	bool ans = false;
	int row, col;
	for (int i = 1; i < h-1 && !ans; ++i)
	{
		for (int j = 1; j < w-1 && !ans; ++j)
		{
			if ( mat[i][j] == '*')
			{
				if ( check(i,j) )
				{
					clean(i,j);
					ans = true;
					row = i;
					col = j;
				}
			}
		}
	}
	if ( ans )
	{
		for (int i = 0; i <= h-1 && ans; ++i)
		{
			
			for (int j = 0; j <= w-1 && ans; ++j)
			{
				
				if ( mat[i][j] == '*' ) ans = false;
			}
		}
	}
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}