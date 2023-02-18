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

int N, V;
int T[MAXN], A[MAXN];


int main(){
	rii(N,V);
	FOR(i,0,N) ri(T[i]);
	FOR(i,0,N) ri(A[i]);

	vector<pair<ll, ll>> ord;
	FOR(i,0,N) {
		ll a = A[i] + 1ll * V * T[i], b = A[i] - 1ll * V * T[i];
		if (b <= 0 && 0 <= a) {
			ord.push_back({-b, a});
		}
	}
	sort(all(ord));

	vector<ll> ans;
	for(auto [_, a] : ord) {
		int ind = upper_bound(all(ans), a) - ans.begin();
		if (ind == sz(ans)) ans.pb(69);
		ans[ind] = a;
	}

	cout << sz(ans) << endl;
	return 0;
}
