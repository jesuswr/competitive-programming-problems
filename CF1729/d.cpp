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
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
ll X[MAXN], Y[MAXN], Z[MAXN];

void solve() {
	ri(N);
	FOR(i, 0, N) lri(X[i]);
	FOR(i, 0, N) lri(Y[i]);
	FOR(i, 0, N) Z[i] = Y[i] - X[i];
	sort(Z, Z + N);
	int ans = 0;
	// FOR(i,0,N) printf("%lld\n", Z[i]);
	int l = 0, r = N - 1;
	while (l < r) {
		if (Z[l] + Z[r] >= 0) {
			ans++;
			l += 1;
			r -= 1;
		}
		else {
			l += 1;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}