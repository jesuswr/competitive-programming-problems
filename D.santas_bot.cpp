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
const int maxN = 1e6+10; // CAMBIAR ESTE
const ll MOD = 998244353;

vi k[maxN];
map<int,int> mp;

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
	int n;
	ri(n);
	FOR(i,0,n){
		int m;
		ri(m);
		FOR(j,0,m){
			int q;
			ri(q);
			k[i].pb(q);
			mp[q]++;
		}
	}
	ll ans = 0;
	FOR(i,0,n){
		ll act = 0;
		ll sum = 0;
		for( auto p : k[i] ){
			sum += mp[p]*binpow(n,MOD-2);
			sum = sum%MOD;
		}
		act = ((1*binpow(k[i].size(),MOD-2))*sum)%MOD;
		ans += act;
		ans = ans%MOD;
	}
	ans *= 1*binpow(n,MOD-2);
	ans = ans%MOD;
	printf("%lld\n", ans);
	return 0;
}