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
const int maxN = 301; // CAMBIAR ESTE

int arr[maxN];
int dis[maxN];
vi g[maxN];

int main()
{
	int n, m;
	int ans;
	int aux1, aux2;
	n = m = 1;
	while (true)
	{
		rii(n,m);
		if (n==0 && m==0) break;
		ans = 0;
		for (int i = 0; i < n; ++i) ri(arr[i]);
		for (int i = 0; i < m; ++i)
		{
			rii(aux1,aux2);
			g[aux1].push_back(aux2);
			g[aux2].push_back(aux1);
			if (arr[aux1] != arr[aux2]) ans++;
		}

	}
}