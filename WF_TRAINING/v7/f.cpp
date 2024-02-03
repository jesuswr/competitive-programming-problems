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
const int MOD = 1e6+5;
const int MAXN = 1e6+69;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll N;

vector<ll> get3() {
	vector<ll> ret;
	FOR(i,2,MAXN) {
		vector<ll> num;
		ll n = N;
		while(n > 0) {
			num.pb(n % i);
			n /= i;
		}
		if (sz(num) <= 2) continue;
		bool pal = 1;
		int l = 0, r = sz(num)-1;
		while(l <= r) {
			if (num[l] != num[r]) pal = 0;
			l += 1; r -= 1;
		}
		if (pal) ret.pb(i);
	}
	return ret;
}

vector<ll> get2() {
	vector<ll> ret;
	FOR(i,1,MAXN) {
		ll num = N-i;
		if (num % i != 0) continue;
		num /= i;
		if (num > i) ret.pb(num);
	}
	return ret;
}

int main(){
	cin >> N;

	vector<ll> g3 = get3();
	vector<ll> g2 = get2();

	vector<ll> ans = g2;
	for(ll x : g3) ans.pb(x);
	sort(all(ans));

	for(ll x : ans) cout << x << ' ';
	if (sz(ans) == 0) cout << '*';
	cout << endl;

	return 0;
}
