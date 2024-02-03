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

int sgn(int x) {
	if (x >= 0) return 1;
	else return -1;
}

bool cmp(ii a, ii b) {
	int da = a.S - a.F, db = b.S - b.F;
	if (sgn(da) != sgn(db)) return da > db;
	if (da >= 0) return a.F < b.F;
	return a.S > b.S;
}

int main(){
	int n; ri(n);
	vii a(n);
	FOR(i,0,n) rii(a[i].F, a[i].S);
	sort(all(a), cmp);

	ll ans = 0;
	ll free = 0;
	for(auto [x,y] : a) {
		if (free < x) {
			ans += (x - free);
			free = x;
		}
		free -= x;
		free += y;
	}	
	cout << ans << endl;
	return 0;
}
