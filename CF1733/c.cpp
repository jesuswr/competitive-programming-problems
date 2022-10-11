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

void p(int l, int r) {
	printf("%d %d\n", l + 1, r + 1);
}

void solve() {
	int n; ri(n);
	vi a(n);
	FOR(i, 0, n) ri(a[i]);
	printf("%d\n", n - 1);
	if (n == 1) return;

	p(0, n - 1);
	if ((a[0] + a[n - 1]) & 1) {
		a[n - 1] = a[0];
	}
	else {
		a[0] = a[n - 1];
	}

	FOR(i, 1, n - 1) {
		if ((a[i] + a[0]) & 1) {
			p(0, i);
		}
		else {
			p(i, n - 1);
		}
	}
}

int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}