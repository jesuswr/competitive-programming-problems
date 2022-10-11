#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	string s; cin >> s;
	vector< vector<int> > POS(26);
	for (int i = 0; i < sz(s); ++i) {
		POS[s[i] - 'a'].pb(i + 1);
	}
	int cst = s[sz(s) - 1] - s[0];
	vi ans;
	int start = s[0] - 'a', end = s[sz(s) - 1] - 'a';
	if (cst >= 0) {
		while (start <= end) {
			for (int x : POS[start]) ans.pb(x);
			start++;
		}
	}
	else {
		while (start >= end) {
			for (int x : POS[start]) ans.pb(x);
			start--;
		}
	}
	printf("%d %d\n", abs(cst), sz(ans));
	for (auto x : ans) printf("%d ", x);
	printf("\n");
}

int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}