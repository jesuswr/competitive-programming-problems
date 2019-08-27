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
int mat[1001][1001];
     
int main()
{
    int n;
	ri(n);
   	int num = 0;
   	for (int i = 0; i < n/2; ++i)
   	{
   		for (int j = 0; j < n/2; ++j)
   		{
   			mat[i][j] = 4*num;
   			mat[n/2+i][j] = 4*num + 1;
   			mat[i][n/2+j] = 4*num + 2;
   			mat[n/2 + i][n/2 + j] = 4*num + 3;
   			num++;
   		}
   	}
   	for (int i = 0; i < n; ++i)
   	{
   		for (int j = 0; j < n; ++j)
   		{
   			printf("%d ",mat[i][j] );
   		}
   		printf("\n");
   	}
   	return 0;
}