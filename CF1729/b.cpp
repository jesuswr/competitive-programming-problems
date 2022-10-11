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
	int n; ri(n);
	string s; cin >> s;
	string ans;
	for (int i = n - 1; i >= 0;) {
		if (s[i] == '0') {
			int x = 10 * (s[i - 2] - '0'), y = s[i - 1] - '0';
			// cout << "     " << x + y << endl;
			char let = 'a' + x + y - 1;
			ans.pb(let);
			i -= 3;
		}
		else {
			int x = s[i] - '0';
			// cout << x << endl;
			char let = 'a' + x - 1;
			ans.pb(let);
			i -= 1;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}

int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}