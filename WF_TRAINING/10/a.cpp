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


struct array_element{
	vector<int> values;
	int ptr;
	void init(int x) {
		ptr = 0;
		values.clear();
		values.pb(x);
		while((x >> 1) > 0) {
			x >>= 1;
			values.pb(x);
		}
		reverse(all(values));
	}
	int get_dst(int x, int pos) {
		return sz(values) - pos - 1 + abs(x - values[pos]);
	}
	int get_dst(int x) {
		// while (ptr + 1 < sz(values) && get_dst(x, ptr) >= get_dst(x, ptr + 1)) ++ptr;
		// return get_dst(x, ptr);
		int mn = INF;
		FOR(i,0,sz(values)) mn = min(mn, get_dst(x, i));
		return mn;
	}
};

int N, M;
array_element A[MAXN];

ll go(int x) {
	vector<int> dsts(N);
	FOR(i,0,N) dsts[i] = A[i].get_dst(x);
	sort(all(dsts));
	ll ret = 0;
	FOR(i,0,N-M) ret += dsts[i];
	// cout << x << "  " << ret << endl;
	// FOR(i,0,N-M) cout << "    " << A[i].get_dst(x) << endl;
	return ret;
}

void solve() {
	rii(N,M);
	vi candidates;
	candidates.reserve(N << 1);
	FOR(i,0,N) {
		int x; ri(x);
		A[i].init(x);
		for(int c : A[i].values) candidates.pb(c);
	}
	sort(all(candidates));

	ll mn = INFLL;
	for(int c : candidates) {
		mn = min(mn, go(c));
	}
	printf("%lld\n", mn);

}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
