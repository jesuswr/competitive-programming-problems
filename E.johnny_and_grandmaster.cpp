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
const int maxN = 1e6+10; // CAMBIAR ESTE
const ll MOD = 1000000007;

// GJNM
ll A[maxN];
ll n,p;

ll pw(ll x){
	if ( x == 0 )
		return 1;
	if ( x == 1 )
		return p;
	if ( x & 1 )
		return ( ( ( pw(x/2)*pw(x/2) )%MOD ) *p )%MOD;
	else
		return (pw(x/2)*pw(x/2))%MOD;
}

ll pw2(ll x){
	if ( x == 0 )
		return 1;
	if ( x == 1 )
		return p;
	if ( x & 1 )
		return min(1000000LL, pw2(x/2)*pw2(x/2)*p);
	else
		return min(1000000LL, pw2(x/2)*pw2(x/2));
}


ll calc_need(ll old, ll dif){
	old = min(1000009LL, old*pw2(dif));
	return old;
}

int main(){
	int t;
	ri(t);
	while(t--){
		rll(n,p);
		FOR(i,0,n){
			rl(A[i]);
		}
		sort(A,A+n), reverse(A,A+n);
		ll ans = 0;
		ll cnt_need = 0, exp_need = 0;
		FOR(i,0,n){
			if ( cnt_need == 0 ){
				cnt_need++;
				exp_need = A[i];
				ans = ( ans + pw(A[i]) )%MOD;
			}
			else{
				cnt_need = min(calc_need(cnt_need, exp_need-A[i]), 1000009LL);
				exp_need = A[i];
				cnt_need--;
				ans = ( ans + MOD - pw(A[i])  )%MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}