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
	int n, k; rii(n, k);
	vi a(n);
	FOR(i,0,n) ri(a[i]);

	{ // remove 0s
		vi b;
		FOR(i,0,n) if (a[i]) b.pb(a[i]);
		n = sz(b);
		k -= (sz(a) - sz(b));
		swap(a, b);
	}

	if (k < 0) {
		printf("Impossible\n");
		return;
	}
	if (n == k) {
		printf("Richman\n");
		return;
	}

	ll sm = 0;
	int mn = 1e9 + 69;
	FOR(i,0,k) sm += a[i];
	FOR(i,k,n) mn = min(mn, a[i]);
	sm += mn-1;

	printf("%lld\n", sm);
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
