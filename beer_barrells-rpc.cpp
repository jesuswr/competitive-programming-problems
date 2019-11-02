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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
ll fact[2000];

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2)%MOD;
    if (b % 2)
        return (((res * res)%MOD) * a)%MOD;
    else
        return (res * res)%MOD;
}
  

int main()
{
	ll a , b , k , c;
	rll(a,b);
	rll(k,c);
	fact[0] = 1;
	FOR(i,1,k+1){
		fact[i] = (fact[i-1]*i)%MOD;
	}
	if ( c != a && c != b ){
		printf("0\n");
	}
	else if ( a != b )
	{
		ll ans = 0;
		FOR(i,1,k+1){
			ll div = binpow( (fact[i] * fact[k-i])%MOD , MOD-2 );
			ll s = (fact[k]*div)%MOD;
			ans += (i*s);
			ans = ans %MOD;
		}
		printf("%lld\n", ans);
	}
	else if ( a == b )
	{
		printf("%lld\n", k);
	}
	return 0;
}