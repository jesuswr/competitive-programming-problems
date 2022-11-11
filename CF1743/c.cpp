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



void solve() {
	int n; ri(n);
	string s; cin >> s;
	s = "0" + s;
	vi a(n + 1);
	FOR(i, 0, n) ri(a[i + 1]);

	ll ans = 0;
	n++;
	int l = 0, r = 0;
	while (69) {
		// printf("%d %c\n", l, s[l]);
		// cout << s << endl;
		while (s[l] == '0' && l + 1 < n) ++l;
		if (s[l] == '0') break;
		r = max(l, r);
		ll sm = a[l] + a[l - 1];
		int mn = min(a[l], a[l - 1]);
		while (r + 1 < n && s[r + 1] == '1') {
			++r;
			sm += a[r];
			mn = min(mn, a[r]);
		}
		ans += sm - mn;
		while (s[l] == '1' && l + 1 < n) ++l;
		if (s[l] == '1') break;
	}

	printf("%lld\n", ans);
}


int main() {
	int n; ri(n);
	while (n-- ) solve();
	return 0;
}