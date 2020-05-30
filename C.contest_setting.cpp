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
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE
const ll MOD = 998244353;

// GJNM
int n,k;
map<int,ll> mp;
vector<ll> cnt;
ll dp[1015][1015];

ll f(int ind, int rem){
	if ( ind == n && rem == 0 )
		return 1LL;
	if ( ind >= n || rem < 0 )
		return 0;

	if ( dp[ind][rem] != -1LL )
		return dp[ind][rem];

	return dp[ind][rem] = ( f(ind+1, rem) + ( cnt[ind]*f(ind+1,rem-1) )%MOD  )%MOD;
}

int main(){
	rii(n,k);
	FOR(i,0,n){
		int aux;
		ri(aux);
		if ( mp.find(aux) == mp.end() )
			mp[aux] = 0;

		mp[aux]++;
	}

	FOR(i,0,n+1){
		FOR(j,0,n+1){
			dp[i][j] = -1LL;
		}
	}

	for(auto p : mp)
		cnt.pb(p.S);

	n = cnt.size();

	if ( k > n ){
		printf("0\n");
		return 0;
	}

	ll ans = f(0,k);
	printf("%lld\n", ans%MOD);
	return 0;
}