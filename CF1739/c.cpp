#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 998244353;
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll DP[100][100];
ll f(int n, int k) {
	if (DP[n][k] >= 0) return DP[n][k];
	if (k == 0 || n == k) return DP[n][k] = 1;
	return DP[n][k] = (f(n - 1, k) + f(n - 1, k - 1)) % MOD;
}

tuple<ll, ll, ll> g(int n) {
	if (n == 2) return {1, 0, 1};
	auto [a, b, c] = g(n - 2);
	ll new_a = (f(n - 1, n / 2) + b) % MOD;
	ll new_b = (f(n - 2, n / 2) + a) % MOD;
	return {new_a, new_b, 1};
}



void solve() {
	int n; ri(n);

	auto [a, b, c] = g(n);
	printf("%lld %lld %lld\n", a, b, c);

}


int main() {
	FOR(i, 0, 100) FOR(j, 0, 100) DP[i][j] = -1;
	int t; ri(t);
	while (t--) solve();

	return 0;
}