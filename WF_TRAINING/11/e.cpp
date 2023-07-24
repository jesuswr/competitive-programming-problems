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

int N, T;

char MP[690];

string go(string x) {
	MP['R'] = 'P'; MP['P'] = 'S'; MP['S'] = 'R';
	map<char, int> cnt;
	FOR(i,0,sz(x)) {
		cnt[x[i]]++;
		swap(x[i], x[ max(i - T, i - cnt[MP[x[i]]] ) ] );
	}
	return x;
}

int main(){
	rii(N,T);
	string s; cin >> s;
	vector<string> ss;
	string aux;
	set<char> st;
	for(char c : s) {
		st.insert(c);
		if (sz(st) == 3) {
			ss.pb(aux);
			st.clear();
			st.insert(c);
			aux.clear();
		}
		aux.pb(c);
	}
	ss.pb(aux);

	for(const string &x : ss) cout << go(x);
	cout << endl;
	return 0;
}
