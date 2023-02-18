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


void solve() {
	int w,l; rii(w,l);
	vector<ll> ops;
	ops.pb(__gcd(w-1, l-1));
	ops.pb(__gcd(w, l-2));
	ops.pb(__gcd(w-2, l));
	ops.pb( __gcd(l, __gcd(l-2, w-1))  );
	ops.pb( __gcd(w, __gcd(w-2, l-1))  );
	set<int> ans;
	for(auto g : ops) {
		for(ll i = 1; i * i <= g; ++i) {
			if (g % i == 0) {
				ans.insert(i);
				ans.insert(g / i);
			}
		}
	}
	cout << sz(ans);
	for(int x : ans) cout << " " << x;
	cout << endl;
}



int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
