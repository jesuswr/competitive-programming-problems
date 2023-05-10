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
#define ri(a) dasdas=scanf("%d\n", &a)
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
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

char S[MAXN], T[MAXN];
bool xr[MAXN];

void solve() {
	int n; ri(n);
	scanf("%s\n", S);
	scanf("%s\n", T);
	FOR(i,0,n) xr[i] = S[i] != T[i];
	vii islas;
	int l = 0, r;
	while(l < n) {
		if (xr[l] == 0) {
			++l;
			continue;
		}

		r = l;
		while(r + 1 < n && xr[r+1] == 1) {
			++r;
		}
		islas.pb({l, r});
		l = r + 1;
	}

	ll ans = 0;
	if (sz(islas) == 0) 
		ans = (1ll * n * (n + 1)) / 2;
	else if (sz(islas) == 1) {
		int aux = (islas[0].S - islas[0].F);
		ans = 2 * aux + 2 * (n - aux - 1);
	}
	else if (sz(islas) == 2)
		ans = 6;
	printf("%lld\n", ans);
}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
