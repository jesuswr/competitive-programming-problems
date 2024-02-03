#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int dasl;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasl=scanf("%d", &a)
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
const int MOD = 37;
const int MAXN = 20+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}



int N;
int MAT[MAXN][MAXN];
int CHAR_TO_INT[1234], INT_TO_CHAR[1234];


string go(const vi &a) {
	vi res(N);
	FOR(i,0,N) {
		FOR(j,0,N) {
			res[i] += MAT[i][j] * a[j];
			res[i] %= MOD;
		}
	}
	string t;
	t.resize(N);
	FOR(i,0,N) t[i] = INT_TO_CHAR[res[i]];
	return t;
}


void pre() {
	int cnt = 0;
	for(char c = 'A'; c <= 'Z'; c++) {
		CHAR_TO_INT[c - 0] = cnt;
		INT_TO_CHAR[cnt] = c;
		cnt++;
	}
	for(char c = '0'; c <= '9'; c++) {
		CHAR_TO_INT[c - 0] = cnt;
		INT_TO_CHAR[cnt] = c;
		cnt++;
	}
	for(char c = ' '; c <= ' '; c++) {
		CHAR_TO_INT[c - 0] = cnt;
		INT_TO_CHAR[cnt] = c;
		cnt++;
	}
}


int main(){
	pre();
	ri(N);
	FOR(i,0,N) FOR(j,0,N) ri(MAT[i][j]);
	string inp;
	getline(cin, inp);
	getline(cin, inp);
	while(sz(inp) % N != 0) inp.pb(' ');

	string ans;
	vi act;
	for(auto c : inp) {
		act.pb(CHAR_TO_INT[c - 0]);

		if (sz(act) == N) {
			string ret = go(act);
			act.clear();
			// cout << ret << endl;
			ans += ret;
		}
	}
	cout << ans << endl;
	return 0;
}
