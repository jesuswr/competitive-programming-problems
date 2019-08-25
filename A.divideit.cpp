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

int main()
{
	int q;
	ri(q)
	ll n;
	while(q--) 
	{
	    rl(n);
	    ll ans = 0;
	    while(n % 5 == 0) 
	    {
	        ans ++;
	        n = 4*n/5;
	    }
	    while ( n % 3 == 0)
	    {
	    	ans ++;
	    	n = 2*n/3;
	    }
	    while(n % 2 == 0) 
	    {
	        ans++;
	        n = n/2;
	    }
	    if ( n != 1) printf("-1\n");
	    else printf("%lld\n", ans);
	}
	return 0;
}