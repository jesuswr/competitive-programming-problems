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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e6 + 2; // CAMBIAR ESTE

// GJNM
// no me hackeen

int n;
int h;
unordered_map<int,int> mp;
int order[maxN];
int parents[102];
int g[102][102];
int visited[101];
int start, endg;
vii ans;


void floydWarshall()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i!=k && g[i][k]!=INF)
			for (int j = 1; j <= n; ++j)
			{
				g[i][j] = min (g[i][j], g[i][k]+g[k][j]);
			}
		}
	}
}


int main()
{
	ri(n);
	for (int i = 0; i < n; ++i)
	{
		visited[i+1] = 0;
		parents[i+1] = -1;
		for (int j = 0; j < n; ++j)
		{
			scanf("%1d", &g[i+1][j+1]);
			if (g[i+1][j+1] == 0) g[i+1][j+1] = INF;
			if (i==j) g[i+1][j+1] = 0;
		}
	}
	ri(h);
	int aux2;
	for (int i = 0; i < h; ++i)
	{
		ri(aux2);
		order[i] = aux2;
	}
	floydWarshall();
	ans.push_back({order[0],0});
	pii aux;
	for (int i = 1; i < h; ++i)
	{

		aux = ans[ans.size()-1];
		if ( g[aux.first][order[i]] < i - aux.second )
		{
			ans.push_back({order[i-1],i-1});
		}
	}
	ans.push_back({order[h-1],0});

	printf("%lu\n", ans.size());
	for (pii p: ans) printf("%d ", p.first);
	printf("\n");
	


	return 0;
}