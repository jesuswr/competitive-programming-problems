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

const string A = "any", L = "left", R = "right";

int main(){
	int n; ri(n);
	map< string , map< string, int> > mp;
	FOR(_,0,n) {
		string a,b; int c;
		cin >> a >> b >> c;
		mp[a][b] = c;
	}

	bool pos = false;
	for(auto &[s, m] : mp) {
		if ( min(1, m[L]) + min(1, m[R]) + min(2, m[A]) >= 2) pos = true;
	}

	if (!pos) {
		cout << "impossible" << endl;
		return 0;
	}

	int ans = 1;
	for(auto &[s, m] : mp) {
		if (m[L] > 0 || m[R] > 0) ans += max(m[L], m[R]);
		else ans += 1;
	}
	cout << ans << endl;

	return 0;
}
