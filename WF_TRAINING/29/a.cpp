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

int n;
string s;

void solve() {
	cin >> s; n = sz(s);
	FOR(i,0,n) {
		if (s[i] == ')') s[i] = '(';
		if (s[i] == ']') s[i] = '[';
	}
	FOR(i,0,n-2) if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
		cout << "No" << endl;
		return;
	}

	vector< vector< char > > lvl(n);

	stack<char> st;
	FOR(i,0,n) {
		if (!st.empty() && st.top() == s[i]) {
			st.pop();
			lvl[sz(st)].pb(s[i]);
		}
		else {
			lvl[sz(st)].pb(s[i]);
			st.push(s[i]);
		}
	}

	for (const auto &vec : lvl) {
		vi cnt(2);
		FOR(i,0,sz(vec)-1) {
			if (vec[i] == vec[i+1]) 
				cnt[vec[i] == '(']++;
		}
		if (max(cnt[0], cnt[1]) >= 2) {
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
	
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
