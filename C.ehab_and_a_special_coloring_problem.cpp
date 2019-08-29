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

bool is_prime( int x )
{
	for (int i = 2; i*i <= x; ++i)
	{
		if ( x % i == 0 ) return false;
	}
	return true;
}



int main()
{
	int n;
	ri(n);
	int current = 1;
	for (int i = 2; i < n+1; ++i)
	{
		if ( is_prime(i) )
		{
			arr[i] = current;
			int mult = 2;
			while ( mult*i <= n)
			{
				arr[mult*i] = current;
				mult++;
			}
			current++;
		}
	}
	for (int i = 2; i < n+1; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}