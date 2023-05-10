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
const int MAXN = 5000+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, W;
string A[MAXN];
int A_SZ[MAXN];

void construct_sol(int rows, const vii &nxt) {
	vector< vector<string> > cols;
	int l = 0;
	vi szs;
	while(l < N) {
		auto [r, mx] = nxt[l];
		vector<string> col;
		for(int i = l; i < r; ++i) {
			while(sz(A[i]) < mx) A[i].push_back(' ');
			col.push_back(A[i]);
		}
		while(sz(col) < rows) {
			string s;
			FOR(_,0,mx) s.pb(' ');
			col.push_back(s);
		}
		cols.push_back(col);
		l = r;
		szs.pb(mx);
	}


	cout << rows << " " << sz(cols) << endl;
	for(int i = 0; i < sz(szs); ++i) {
		cout << szs[i];
		if (i + 1 == sz(szs)) cout << endl;
		else cout << " ";
	}
	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < sz(cols); ++j) {
			cout << cols[j][i];
			if (j + 1 == sz(cols)) cout << endl;
			else cout << " ";
		}
	}
}


bool f(int k, bool print_sol = false) {
	vi dp(N+1, 0);
	vii nxt(N+1);
	for(int i = N-1; i >= 0; --i) {
		int mx = 0;
		dp[i] = 10 * W;
		for(int j = i; j < min(N, i + k); ++j) {
			mx = max(mx, A_SZ[j]);
			dp[i] = min(dp[i], mx + 1 + dp[j+1]);
			if (dp[i] == mx + 1 + dp[j+1]) nxt[i] = {j+1, mx};
		}
	} 
	if (print_sol) {
		construct_sol(k, nxt);
	}
	if (dp[0] <= W) return true;
	else return false;
}

int main(){
	rii(N,W);
	FOR(i,0,N) {
		cin >> A[i];
		A_SZ[i] = sz(A[i]);
	}
	++W;

	int lo = 1, hi = N;
	while(lo < hi) {
		int mi = lo + (hi - lo) / 2;
		if (f(mi)) hi = mi;
		else lo = mi + 1;
	}
	f(lo, true);
	return 0;
}
