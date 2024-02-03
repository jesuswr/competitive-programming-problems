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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int R, C;
char G[15][15];
int dp[15][15][123][123][18];
string s;

int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool valid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

int solve (int r, int c, int i, int k, int dir) {
	if (i + 1 == sz(s)) return k == 0;
	if (k < 0) return false;
	if (dp[r][c][i][k][dir] != -1) return dp[r][c][i][k][dir];

	bool ret = false;
	FOR(j,0,8) {
		int rr = r+dr[j], cc = c+dc[j];
		if (valid(rr, cc) && s[i+1] == G[rr][cc]) ret = ret || solve(rr, cc, i+1, k - (dir != j), j);
	}

	return dp[r][c][i][k][dir] = ret;
}

int main(){
	ms(dp, -1);
	cin >> R >> C;
	FOR(i,0,R) FOR(j,0,C) {
		string ss;
		cin >> ss; G[i][j] = ss[0];
	}
	ll k; cin >> k;
	cin >> s;

	if (k > sz(s) || k < 0) {
		cout << "NO" << endl;
		return 0;
	}

	bool pos = false;
	FOR(i,0,R) FOR(j,0,C) if (G[i][j] == s[0]) {
        FOR(d,0,8) pos = pos || solve(i, j, 0, k, d);
	}

	cout << (pos ? "YES" : "NO") << endl;


	return 0;
}
