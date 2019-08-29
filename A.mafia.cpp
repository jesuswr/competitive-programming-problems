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
const ll LLINF = 1e12;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
ll sum;
ll mx;
int n;

bool valid( ll games )
{
	if ( games < mx) return false;
	if ( sum <= (n-1)*games ) return true;
	return false;
}

int main()
{
	n;
	ri (n);
	ll aux;
	sum = 0;
	ll start = 1;
	for (int i = 0; i < n; ++i)
	{
		rl(aux);
		sum += aux;
		start = max(start,aux);
	}
	mx = start;
	ll end = LLINF;
	ll ans = 0;
	ll mid;
	while( start <= end) 
	{
	   	mid = ( start + end ) / 2;
		//printf("%lld %lld %lld\n",start,mid,end );
	   	if ( valid(mid) )
	   	{
	   		end = mid - 1;
	   		ans = mid;
	   	}
	   	else
	   	{
	   		start = mid + 1;
	   	}
	}
	printf("%lld\n", ans);
	return 0;
}