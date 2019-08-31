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
const int maxN = 150000 + 10; // CAMBIAR ESTE

// GJNM
int arr[maxN];
int mn[maxN];

int main()
{
	int t,n;
	ri(t);
	while(t--) 
	{
	    ri(n);
	    for (int i = 0; i < n; ++i)
	    {
	    	ri(arr[i]);
	    }
	    mn[n-1] = arr[n-1];
	    for (int i = n-2; i >= 0; --i)
	    {
	    	mn[i] = min(mn[i+1],arr[i]);
	    }
	    int count = 0;
	    for (int i = 0; i < n-1; ++i)
	    {
	    	if (arr[i]!=mn[i]) count++;
	    }
	    printf("%d\n", count);
	}
	return 0;
}