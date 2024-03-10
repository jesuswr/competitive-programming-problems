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
#define lri(a) das=scanf("%lld", &a)
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

int f(int x) {
	int mx = 0;
	while(x) {
		int d = x % 10;
		mx = max(mx, d);
		x /= 10;
	}
	return mx;
}

int brute(int la, int ra, int lb, int rb) {
	int mx = 0;
	FOR(a,la,ra+1) FOR(b,lb,rb+1) {
		mx = max(mx, f(a+b));
	}
	return mx;
}


void solve() {
	int la, ra, lb, rb; rii(la, ra), rii(lb,rb);
	int lena = ra - la, lenb = rb - lb;

	if (max(lena, lenb) <= 100) cout << brute(la, ra, lb, rb) << endl;
	else cout << 9 << endl;
}


int main(){
	int t; ri(t);
	while(t--) solve();

	return 0;
}