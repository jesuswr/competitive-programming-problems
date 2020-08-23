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
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
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
const int MAXN = 5e3 + 10; // CAMBIAR ESTE
const ll MOD = 1000000007;

// GJNM
ll n_div[MAXN];
ll fact[MAXN];

ll bpow(int x, ll e) {
	if ( e == 0 )
		return 1LL;

	ll res = bpow(x, e / 2LL);
	if ( e & 1LL )
		return (((res * res) % MOD) * x) % MOD;
	else
		return (res * res) % MOD;
}

ll dp[MAXN][MAXN];
ll dp2[MAXN][MAXN];


ll pick(ll n, ll k) {
	if ( dp[n][k] != 0 )
		return dp[n][k];
	ll num = fact[n];
	ll den;
	if ( dp2[k][n - k] == 0 ) {
		den = (fact[k] * fact[n - k]) % MOD;
		den = bpow(den, MOD - 2ll) % MOD;
		dp2[k][n - k] = den;
	}
	else {
		den = dp2[k][n - k];
	}
	return dp[n][k] = (num * den) % MOD;
}

ll ans1[MAXN][MAXN], ans2[MAXN][MAXN];

void aux_solve() {
	FOR(k, 0, MAXN) {
		ans1[0][k] = 0;
		ans2[0][k] = 1;
	}
	FOR(n, 1, MAXN) {
		FOR(k, 1, MAXN) {
			if ( n_div[n] > k ) {
				ans2[n][k] = pick(n_div[n], k);
			}
			else {
				ans2[n][k] = 1;
			}
			ans1[n][k] = min(n_div[n], (ll)k);

			ans1[n][k] = (ans1[n][k] + ans1[n - 1][k]) % MOD;
			ans2[n][k] = (ans2[n][k] * ans2[n - 1][k]) % MOD;
		}
	}
}


int main() {
	fact[0] = 1;
	FOR(i, 1, MAXN) {
		int aux = i + i;
		while (aux < MAXN) {
			n_div[aux]++;
			aux += i;
		}
		fact[i] = (i * fact[i - 1]) % MOD;
	}
	aux_solve();
	int t;
	ri(t);
	ll n, k;
	while (t--) {
		rll(n, k);
		printf("%lld %lld\n", ans1[n][k], ans2[n][k]);
	}

	return 0;
}