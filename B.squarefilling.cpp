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
int mat[51][51];
int mat2[51][51];

bool checkChange( int a, int b )
{
	if ( mat[a][b] != 1 || mat[a+1][b] != 1 || mat[a][b+1] != 1 || mat[a+1][b+1] != 1 ) return false;
	mat2[a][b] = 1; 
	mat2[a+1][b] = 1; 
	mat2[a][b+1] = 1; 
	mat2[a+1][b+1] = 1; 
	return true;
}


int main()
{
	int n, m;
	rii(n,m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &mat[i][j]);
			mat2[i][j] = 0;
		}
	}
	queue<pii> q;
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < m-1; ++j)
		{
			if (  checkChange( i , j) ) q.push({i+1,j+1});
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if ( mat[i][j] != mat2[i][j] )
			{
				
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%lu\n", q.size());
	while(!q.empty()) 
	{
	    printf("%d %d\n", q.front().first, q.front().second);
	    q.pop();
	}
	return 0;
}