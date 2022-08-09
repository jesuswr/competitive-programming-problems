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

int N, M, K;


void solve() {
	vector< pair< ll, ll > > A, B;
	rii(N, M);
	FOR(i, 0, N) {
		ll a; lri(a);
		ll cnta = 1;
		while (a % M == 0) {
			a /= M;
			cnta *= M;
		}
		if (!A.empty() && A.back().F == a) {
			A.back().S += cnta;
		}
		else {
			A.pb({a, cnta});
		}
	}
	ri(K);
	FOR(i, 0, K) {
		ll a; lri(a);
		ll cnta = 1;
		while (a % M == 0) {
			a /= M;
			cnta *= M;
		}
		if (!B.empty() && B.back().F == a) {
			B.back().S += cnta;
		}
		else {
			B.pb({a, cnta});
		}
	}

	if (A == B) printf("Yes\n");
	else printf("No\n");
}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}