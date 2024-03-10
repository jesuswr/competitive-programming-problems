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


namespace encode {	
	vector<string> split(const string &line) {
		vector<string> ret;
		string aux;
		for(auto c : line) {
			if (c == ' ' || c == ':') {
				if (sz(aux) != 0) {
					ret.pb(aux);
					aux.clear();
				}
			}
			else 
				aux.pb(c);
		}
		if (sz(aux)) ret.pb(aux);
		return ret;
	}

	string root;
	map<string, vector<string>> g;

	void input() {
		string s; 
		while( getline(cin, s) ) {
			vector<string> line = split(s);
			if (sz(root) == 0) root = line[0];
			FOR(i,1,sz(line)) {
				g[line[0]].pb(line[i]);
			}
		}
	}


	string encoding;
	vector<string> order;

	void dfs(const string &u) {
		encoding.pb('1'); // entre
		order.pb(u);

		for (const string &v : g[u]) dfs(v);

		encoding.pb('0'); // sali
	} 

	void go() {
		input();
		dfs(root);

		for(const string &s : order) cout << s << endl;
		cout << encoding << endl;
	}
}

namespace decode {
	vector<string> order;
	string encoding;

	void input() {
		string s;
		while(getline(cin, s)) {
			if (s[0] == '1') encoding = s;
			else order.pb(s);
		}
		reverse(all(encoding));
		reverse(all(order));
	}

	vector< vector< string > > ans;

	void dfs(const string s) {
		order.pop_back();
		encoding.pop_back();

		int ans_i = sz(ans);
		ans.pb({s});

		while(1) {
			if (encoding.back() == '0') {
				encoding.pop_back();
				break;
			}
			else {
				ans[ ans_i ].pb(order.back());
				dfs(order.back());
			}
		}
	}


	void go() {
		input();
		dfs(order.back());

		for(const auto &vec : ans) if (sz(vec) > 1) {
			cout << vec[0] << ':';
			FOR(i,1,sz(vec)) cout << ' ' << vec[i];
			cout << endl;
 		}
	}
}

int main(){
	string s; getline(cin, s);
	if (s[0] == 'E') encode::go();
	else decode::go();w
	return 0;
}
