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

#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);
#define rl(a) scanf("%lld", &a);
#define rll(a,b) scanf("%lld %lld", &a, &b);

const int INF = 2e9;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
ll l, w;
ll total;
vector<ll> vec;

bool valid ( int val )
{
	for (ll i = l; i <= w; ++i)
	{
		//printf("%lld %lld\n", i,i-l);
		if ( vec[i] - vec[i-l] < val ) return false;
	}
		
	return true;
}

int main()
{
	rll( w , l );
	ll aux;
	vec.push_back(1);
	for (int i = 1; i < w; ++i)
	{
		rl(aux);
		vec.push_back(aux+vec[i-1]);
	}
	vec.push_back(INF+vec[vec.size()-1]);
	ll start = 0;
	ll end = INF;
	ll ans = 0;
	while(start <= end) 
	{
	  	ll mid = ( start + end ) / 2;
	  	//printf("%lld %lld %lld\n", start, mid, end);
	  	if ( valid(mid) )
	  	{
	  		//printf("subio\n");
	  		start = mid + 1;
	  		ans = mid;
	  	}
	  	else end = mid - 1;
	}
	printf("%lld\n", ans);

}