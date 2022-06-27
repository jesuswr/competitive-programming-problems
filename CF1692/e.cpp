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
	int n, s; rii(n, s);
	vector<int> a(n);
	FOR(i, 0, n) ri(a[i]);
	int act_sm = 0;
	FOR(i, 0, n) act_sm += a[i];
	if (act_sm < s) {
		printf("-1\n");
		return;
	}
	if (act_sm == s) {
		printf("0\n");
		return;
	}
	vi lft, rgt;
	FOR(i, 0, n) if (a[i] == 1) {
		lft.pb(i);
		rgt.pb(i);
	}
	s = act_sm - s;
	reverse(rgt.begin(), rgt.end());
	int mn = INF;
	mn = min(mn, min(lft[s - 1] + 1, n - rgt[s - 1]));
	FOR(l, 1, s) {
		mn = min(mn, (lft[l - 1] + 1 + (n - rgt[s - l - 1])));
		// printf("%d %d\n", lft[l - 1], rgt[s - l - 1]);
		// printf("\t%d %d\n", l - 1, s - l - 1);
	}
	printf("%d\n", mn);
}


int main() {
	int t; ri(t);
	while (t--) {
		solve();
	}
	return 0;
}