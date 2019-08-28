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
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
int arr[maxN];

int main()
{
	int t;
	int n, k;
	ri(t);
	while(t--) 
	{
	    rii(n,k);
	    for (int i = 0; i < n; ++i)
	    {
	    	ri(arr[i]);
	    }
	    int mn = INF;
	    int ans;
	    for (int i = 0; i < n-k; ++i)
	    {
	    	if ( mn > arr[i+k] - arr[i])
	    	{
	    		mn = arr[i+k] - arr[i];
	    		ans = arr[i+k] + arr[i];
	    		ans /= 2;
	    	}
	    }
	    printf("%d\n", ans);
	}
	return 0;
}