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
const int maxN = 102; // CAMBIAR ESTE

// GJNM

ll heights[maxN];

int main()
{
	int t;
	ll n, m, k;
	ri(t);
	while ( t-- )
	{
		rll(n,m);
		rl(k);
		for (int i = 0; i < n; i++ ) rl(heights[i]);
		int i = 0;
		if (n==1)
		{
			printf("YES\n");
			continue;
		}
		while( i < n - 1) 
		{
		 	if ( heights[i] >= heights[i+1] - k)
		 	{
		 		m += min(heights[i] - ( heights[i+1] - k), heights[i]);
		 		i++;
		 	}
		 	else
		 	{
		 		if ( heights[i + 1] - k - heights[i] <= m )
		 		{
		 			m -= heights[i + 1] - k - heights[i];
		 			i++;
		 		}
		 		else break;
		 	}   
		}

		i == n-1 ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}