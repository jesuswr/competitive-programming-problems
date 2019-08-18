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
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM

int arr[maxN];

int main()
{
	int n;
	ri(n);
	for (int i = 0; i < n; ++i)
	{
		ri(arr[i]);
	}
	int neg = 0;
	int zeros = 0;
	ll coins = 0;
	for (int i = 0; i < n; ++i)
	{
		if ( arr[i] > 0) 
		{
			coins += arr[i] - 1;
		}
		else if ( arr[i] < 0)
		{
			coins += -1 -arr[i];
			neg++;
		}
		if ( arr[i] == 0) zeros++;
	}
	if ( neg % 2 == 0 )
	{
		coins += zeros;
	}
	else
	{
		if ( zeros > 0)
		{
			coins += zeros;
		}
		else
		{
			coins += 2;
		}
	}
	printf("%lld\n", coins);
	return 0;
}