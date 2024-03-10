#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

string to_bin(int x) {
	string ret;
	while(x > 0) {
		if (x & 1) ret.pb('1');
		else ret.pb('0');
		x /= 2;
	}
	reverse(all(ret));
	return ret;
}

string f(string s) {
	vector< pair<int, char> > cnt;
	for(char c : s) {
		if (cnt.empty() || cnt.back().S != c) 
			cnt.pb({1,c});
		else
			cnt.back().F++;
	}
	string ret;
	for(auto [c_cnt,c] : cnt) {
		ret += to_bin(c_cnt);
		ret += c;
	}
	return ret;
}

vector<string> s;

void pre(){
	int n = 1;
	s.pb("1");

	while(sz( s[ max(0, sz(s) - 2) ] ) < 1e6 ) {
		n++;
		s.pb( f(s.back()) );		
	}
	for(string &st : s) reverse(all(st));
}

void solve() {
	ll n,m; lrii(n,m); --n;
	if (n >= sz(s)) {
		if ((n & 1) == (sz(s) & 1)) n = sz(s) - 2;
		else n = sz(s) - 1;
	}
	if (n < sz(s)) printf("%c\n", m >= sz(s[n]) ? '0' : s[n][m] );
}

int main() {
	int t; ri(t);
	pre();
	while(t--) solve();
	return 0;
}