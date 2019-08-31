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
int arr[11];

int main()
{
	int q;
	ll n,m;
	ri(q);
	while(q--) 
	{
	    rll(n,m);
	    for (int i = 1; i < 11; ++i)
	    {
	    	arr[i] = (m*i)%10;
	    }
	    ll div = n/m;
	    ll cont = 0;
	    if ( div >= 10)
	    {
	    	for (int i = 1; i < 11; ++i)
	   	 	{
	    		cont += arr[i] * (div/10);
	    	}
	    }
	    for (int i = 1; i <= div%10; ++i)
	    {
	    	cont += arr[i];
	    }
	    printf("%lld\n", cont);
	}
	return 0;
}