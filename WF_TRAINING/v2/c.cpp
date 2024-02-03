#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
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
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vi get(string s) {
	vi ord;
	stack<int> st;
	FOR(i,0,sz(s)) {
		while(!st.empty() && s[st.top()] > s[i]) {
			ord.pb(st.top());
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) ord.pb(st.top()), st.pop();
	return ord;
}

void solve() {
	string s; cin >> s;

	long long pos; cin >> pos;
	vector<bool> bad(sz(s));
	vi chngs = get(s);
	int sz = sz(s);
	int i = 0;
	while(1) {
		if (pos <= sz) {
			FOR(j,0,sz(s)) {
				if (bad[j]) continue;
				pos--;
				if (pos == 0) {
					cout << s[j];
					return;
				}
			}
		}

		pos -= sz;
		sz--;
		bad[chngs[i]] = 1;
		i += 1;
	}


}


int main(){
	int t; cin >> t; while(t--) solve();
	cout << endl;
	return 0;
}
