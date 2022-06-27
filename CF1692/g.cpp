#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
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

string to_str(int x) {
	string a;
	while (x > 0) {
		a.pb('0' + x % 10);
		x /= 10;
	}
	if (sz(a) < 2) a.pb('0');
	if (sz(a) < 2) a.pb('0');
	reverse(all(a));
	return a;
}

bool is_pal(int a, int b) {
	string sa = to_str(a), sb = to_str(b);
	reverse(sa.begin(), sa.end());
	return sa == sb;
}

void solve() {
	int n, k; rii(n, k);
	vi a(n);
	vector<bool> good(n);
	FOR(i, 0, n) {
		ri(a[i]);
	}
	FOR(i, 0, n - 1) {
		good[i] = 2 * a[i + 1] > a[i];
	}
	int good_cnt = 0;
	FOR(i, 0, k) good_cnt += good[i];
	int ans = 0;
	ans += good_cnt == k;

	FOR(i, 1, n - k) {
		good_cnt -= good[i - 1];
		good_cnt += good[i + k - 1];
		ans += good_cnt == k;
	}
	printf("%d\n", ans);
}


int main() {
	int t; ri(t);
	while (t--) {
		solve();
	}
	return 0;
}