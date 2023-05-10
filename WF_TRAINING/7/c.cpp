#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof (obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second 
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 3e3+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int dp[MAXN][MAXN];
int dpr[MAXN][MAXN];
int w[MAXN][15];
int p[MAXN];
int n, K;

int f(int i, int k) {
	if (i >= n) return k == 0 ? 0 : -INF;
	if (k < 0) return -INF;
	if (dp[i][k] != -1) return dp[i][k];
	return dp[i][k] = max(w[i][p[i]] + f(i+1, k-p[i]), f(i+1, k));
}

int fr(int i, int k) {
	if (i < 0) return k == 0 ? 0 : -INF;
	if (k < 0) return -INF;
	if (dpr[i][k] != -1) return dpr[i][k];
	return dpr[i][k] = max(w[i][p[i]] + f(i-1, k-p[i]), f(i-1, k));
}

int main() {
	ms(dp, -1); ms(dpr, -1);

	rii(n, K);

	FOR(i,0,n) { ri(p[i]); FOR(j,0,p[i]) ri(w[i][j]); }

	int ans = 0;
	FOR(i,0,n) {
		FOR(j,0,p[i]) {
			FOR(k,0,K-j) {
				ans = max(ans, w[i][j] + f(i+1, k) + fr(i-1, K-j-1 - k));
			}
		}
	}


	printf("%d\n", ans);



	return 0;
}
