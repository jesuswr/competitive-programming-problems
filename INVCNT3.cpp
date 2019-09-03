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
const int maxN = 200000 + 5; // CAMBIAR ESTE

// GJNM
pii arr[maxN];
ll bit[maxN];
ll cont;
int n;

ll get_sum( int ind )
{
	ll s = 0;
	while( ind > 0 ) 
	{
	    s += bit[ind];
	    ind -= ( ind & -ind );
	}
	return s;
}

void update_val( int ind )
{
	while( ind <= n) 
	{
	    bit[ind]++;
	    ind += ( ind & -ind );
	}
}


int main()
{
	int t;
	ri(t);
	while(t--) 
	{
	    n;
	    ri(n);
	    for (int i = 0; i <= n; ++i)
	    {
	    	bit[i] = 0;
	    }
	    for (int i = 1; i <= n; ++i)
	    {
	    	ri(arr[i].first);
	    	arr[i].second = i;
	    }
	    sort(arr+1,arr+n+1,greater<pii>());
	    cont = 0;
	    for (int i = 1; i <= n; ++i)
	    {
	    	cont += get_sum( arr[i].second - 1  );
	    	update_val(  arr[i].second );
	    }
	    printf("%lld\n", cont);


	}

	return 0;
}