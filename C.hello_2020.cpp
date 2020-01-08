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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
ll fact[300000];

int main()
{
	ll n,MOD;
	rll(n,MOD);
	fact[0] = 1;
	FOR(i,1,250010)
		fact[i] = (i*fact[i-1])%MOD;

	ll ans = 0;
	FOR(i,1,n+1){
		ans += (((((n+1-i)*fact[i])%MOD)*fact[n-i])%MOD)*(n+1-i);
		ans = ans%MOD;
	}
	ans = (ans + MOD)%MOD;
	printf("%lld\n", ans);
	
	return 0;
}