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

struct tree
{
	int x , h;
};

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
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
tree arr[maxN];
int l[maxN], r[maxN], u[maxN];

int main()
{
	int n;
	ri(n);
	for (int i = 0; i < n; ++i)
	{
		rii( arr[i].x , arr[i].h);
	}
	if ( n == 1 ) { printf("1\n"); return 0; }
	l[0] = 1;
	r[0] = arr[0].x+arr[0].h < arr[1].x ? 1 : 0;
	u[0] = 0;

	for (int i = 1; i < n; ++i)
	{
		if ( arr[i-1].x + arr[i-1].h < arr[i].x - arr[i].h )
		{
			l[i] = max ( l[i-1] , max( u[i-1], r[i-1] ) ) + 1;
		}
		else if ( arr[i-1].x < arr[i].x - arr[i].h )
		{
			l[i] = max ( l[i-1] , u[i-1] ) + 1;
		}
		else
		{
			l[i] = max ( l[i-1] , max( u[i-1], r[i-1] ) );
		}

		if ( i < n -1 && arr[i].x + arr[i].h < arr[i+1].x )
		{
			r[i] = max ( l[i-1] , max( u[i-1], r[i-1] ) ) + 1;
		}
		else if ( i == n-1 )
		{
			r[i] = max ( l[i-1] , max( u[i-1], r[i-1] ) ) + 1;
		}
		else
		{
			r[i] = max ( l[i-1] , max( u[i-1], r[i-1] ) );
		}

		u[i] = max ( l[i-1] , max( u[i-1], r[i-1] ) );
	}

	printf("%d\n", max ( l[n-1] , max( u[n-1], r[n-1] ) ));

	return 0;
}