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

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 7e6; // CAMBIAR ESTE

// GJNM
int n;
pii arr[20];
double dp[maxN];

double dist(int i, int j){
	return (arr[i].f - arr[j].f)*( arr[i].f - arr[j].f) + ( arr[i].s - arr[j].s)*( arr[i].s - arr[j].s);
}

double f(int bitmsk){
	if ( bitmsk == (1<<2*n)-1 )
		return 0;
	if ( dp[bitmsk] != -1 )
		return dp[bitmsk];

	double &ret = dp[bitmsk];
	ret = INF;
	FOR(i,0,2*n){
		FOR(j,i+1,2*n){
			if ( ( bitmsk & (1<<i) ) || ( bitmsk & (1<<j) ) )
				continue;
			ret = min(ret, f( bitmsk | (1<<i) | (1<<j) ) + sqrt(dist(i,j)) );

		}
	}

	return ret;
}

int main(){
	int t = 1;
	int e;
	while(true){
		e = ri(n);
		if ( n == 0 )
			return 0;

		FOR(i,0,2*n){
			e = scanf("%*s");
			e = rii(arr[i].f,arr[i].s);
		}

		FOR(i,0,1<<2*n)
			dp[i] = -1;
	
		printf("Case %d: %.2f\n", t++, f(0));
	}
	return 0;
}