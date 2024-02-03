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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int count_digits(int x) {
	int r = 0;
	while(x > 0) {
		r += 1;
		x /= 10;
	}
	return r;
}

int main(){
	ll n; cin >> n;

	int ans = 0;

	FOR(b,1,10) {
		if (b > n) continue;
		ll base = b;
		int cnt = 1;
		while(10 * base + b <= n) {
			base = 10 * base + b;
			cnt++;
		}
		ans += cnt;
	}
	ans += max(1, count_digits(n) - 1);
	cout << ans << endl;
	return 0;
}
