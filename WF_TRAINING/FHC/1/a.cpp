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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


void solve() {
	int n; ri(n);
	vi a(n);
	FOR(i,0,n) ri(a[i]);
	sort(all(a));
	int ans = 0;
	if (n == 5) {
		int l = (a[0] + a[2]), r = (a[n-1] + a[n-2]);
		ans = max(ans, r - l);
		l = (a[0] + a[1]);
		r = (a[n-1] + a[n-3]);
		ans = max(ans, r - l);
	}
	else {
		int l = (a[0] + a[1]), r = (a[n-1] + a[n-2]);
		ans = r - l;
	}
	printf("%.10lF\n", (double) ans / 2);
}


int main(){
	int t; ri(t);
	FOR(i,1,t+1) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
