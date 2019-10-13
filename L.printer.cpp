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
const int maxN = 1005; // CAMBIAR ESTE

// GJNM
char s1[maxN], s2[maxN];

int abs( int x )
{
	if ( x >= 0 ) return x;
	return -x;
}

int main()
{
	int n, k;
	rii(n,k);
	scanf("%s %s", s1 , s2);
	int min1, min2, max1, max2;
	min1 = min2 = max1 = max2 = -1;
	FOR(i,0,n)
	{
		if ( s1[i] == '1' )
		{
			if ( min1 == -1 ) min1 = i+1;
			max1 = max( max1, i+1);
		}
		if ( s2[i] == '1' )
		{
			if ( min2 == -1 ) min2 = i+1;
			max2 = max( max2, i+1);
		}
	}
	if ( min1 == -1 || min2 == -1 )
	{
		if ( min1 != -1)
		{
			int s = min1, e = max1;
			int ans = ( min1 + max1 ) / 2;
			int ans2 = max( abs(min1-ans) , abs(max1-ans) );
			printf("%d\n", ans2);
			printf("2 %d\n", ans);
		}
		else
		{
			int s = min2, e = max2;
			int ans = ( min2 + max2 ) / 2;
			int ans2 = max( abs(min2-ans) , abs(max2-ans) );
			printf("%d\n", ans2);
			printf("1 %d\n", ans);
		}
	}
	else
	{
		int minAns = INF;
		int floor, pos;
		FOR(i,0,n)
		{
			int q = max( abs( max1 - i-1) , abs( i+1 + max2 + k) );
			int q1 = max( abs( max2 - i-1) , abs( i+1 + max1 + k) );
			//if ( i == 2 ) printf("%d %d\n", q,q1);
			if ( q < minAns )
			{
				minAns = q;
				floor = 2;
				pos = i+1;
			}
			if ( q1 < minAns )
			{
				minAns = q1;
				floor = 1;
				pos = i+1;
			}
		}
		printf("%d\n%d %d\n",minAns, floor, pos );
	}
	//printf("%d %d %d %d \n", min1, min2 , max1, max2);
	return 0;
}