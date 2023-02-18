#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

string get_chars(const string &a) {
	string ret;
	for(char c : a) {
		bool fnd = false;
		for(char x : ret) fnd |= c == x;
		if (!fnd) ret.pb(c);
	}
	return ret;
}

ll go(const string &a, const string &b, int msk, const string &cs) {
	vector<bool> h(26);
	for(int i = 0; i < sz(cs); ++i) if (msk & (1 << i)) h[cs[i] - 'a'] = 1;

	string new_a;
	FOR(i,0,sz(a)) {
		if (h[a[i] - 'a']) new_a.pb(b[i]);
		else new_a.pb(a[i]);
	}
	ll ret = 0;
	ll cnt = 0;
	FOR(i,0,sz(a)) {
		if (new_a[i] == b[i]) cnt++;
		else {
			ret += cnt * (cnt + 1) / 2;
			cnt = 0;
		}
	}
	ret += cnt * (cnt + 1) / 2;
	return ret;
}

int count_bits(int msk) {
	int a = 0;
	while(msk) {
		if (msk & 1) ++a;
		msk /= 2;
	}
	return a;
}

void solve() {
	int n, k; rii(n, k);
	string a, b; cin >> a >> b;
	auto cs = get_chars(a);
	ll ans = 0;
	FOR(msk, 0, 1 << sz(cs)) {
		if (count_bits(msk) > k) continue;
		ll val = go(a, b, msk, cs);
		ans = max(ans, val);
	}
	cout << ans << endl;
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
