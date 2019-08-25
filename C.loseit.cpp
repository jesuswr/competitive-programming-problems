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
int arr[5*maxN+5];
int order[50];


int main()
{
	int n;
	ri(n);
	for (int i = 0; i < n; ++i)
	{
		ri(arr[i]);
	}
	if ( n < 6) printf("%d\n", n);
	else
	{
		int ans = 0;
		int aux = 0;
		int cont4 = 0, cont8 = 0, cont15 = 0, cont16 = 0, cont23 = 0, cont42 = 0;
		order[4] = order[8] = order[15] = order[16] = order[23] = order[42] = 0;
		for (int i = 0; i < n; ++i)
		{
			if ( arr[i] == 4) order[4]++;
			if ( arr[i] == 8) 
			{
				if ( order[4] > order[8]) order[8]++;
			}
			if ( arr[i] == 15)
			{
				if ( order[8] > order[15] )order[15]++;
			}
			if ( arr[i] == 16)
			{
				if ( order[15] > order[16] )order[16]++;
			}
			if ( arr[i] == 23)
			{
				if ( order[16] > order[23] )order[23]++;
			}
			if ( arr[i] == 42)
			{
				if ( order[23] > order[42] )order[42]++;
			}	
		}
		int mn = min( min ( min ( order[4],order[8] ) , min( order[15] , order[16]) ), min(order[23],order[42]) );
		printf("%d\n", n - 6*mn);

	}
	return 0;
}