#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj, val, sizeof(obj))
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

map<string, int> M;

vi G[MAXN];
vi GR[MAXN];

vector<vi> text;
vector<string> RM;

int main() {

	string s;

	set<int> nxt, prv;
	set<int> nnxt, nprv;

	vector<int> acum;
	while (cin >> s) {
		string ss = s;
		if (s.back() == ',' || s.back() == '.') ss.pop_back();

		if (!M.count(ss)) RM.pb(ss);
		int v = M.count(ss) ? M[ss] : (M[ss] = sz(RM)-1);

		if (!acum.empty()) { G[acum.back()].pb(v); GR[v].pb(acum.back()); }
		acum.pb(v);

		if (s.back() == ',') nnxt.insert(v);
		if (s.back() == '.') { text.pb(acum); acum.clear(); }
	}

	while (!nnxt.empty()) {
		for (auto v : nnxt) {
			nxt.insert(v);
			for (auto u : G[v]) if(!prv.count(u)) nprv.insert(u);
		}
		nnxt.clear();

		for (auto v : nprv) {
			prv.insert(v);
			for (auto u : GR[v]) if (!nxt.count(u)) nnxt.insert(u);
		}
		nprv.clear();
	}

	for (auto &v : text) {
		FOR(i,0,sz(v)) {
			cout << RM[v[i]];
			if (i == sz(v) - 1) cout << ".";
			else if (nxt.count(v[i]))  cout << ",";
			cout << " ";
		}
	}

	cout << endl;
	

	return 0;
}
