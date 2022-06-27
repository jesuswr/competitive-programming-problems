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
	int h, m, d;
	scanf("%d:%d %d\n", &h, &m, &d);
	vector< vector<bool> > VIS(30, vector<bool>(70));
	int ans = 0;
	while (!VIS[h][m]) {
		VIS[h][m] = 1;
		if (is_pal(h, m) && false) {
			printf("%d:%d\n", h, m);
			printf("\tnice\n");
		}
		ans += is_pal(h, m);
		m += d;
		h += m / 60;
		m %= 60;
		h %= 24;
	}
	printf("%d\n", ans);
}


int main() {
	int t; scanf("%d\n", &t);
	while (t--) {
		solve();
	}
	return 0;
}