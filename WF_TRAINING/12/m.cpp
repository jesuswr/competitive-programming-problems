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
const int MAXN = 5e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
vi G[MAXN];

int find_ind(int u, int v) {
	FOR(i,0,sz(G[u])) if (v == G[u][i]) return i;
}

tuple<bool, int, int> DP[MAXN][4];
bool VIS[MAXN][4];
tuple<bool, int, int> f(int u, int fi = 3, int ft = -1) {
	if (VIS[u][fi]) return DP[u][fi];
	VIS[u][fi] = 1;

	int mn, mx;
	mn = mx = u;
	bool can = 1;
	// cout << u << " " << ft << endl;
	vi VAL, MN, MX;
	for(int v : G[u]) if (v != ft) {
		auto [a,c,d] = f(v, find_ind(v, u), u);
		MN.pb(c);
		MX.pb(d);
		
		can &= a;
		mn = min(mn, c);
		mx = max(mx, d);
	}

	if (sz(MN) == 1) {
		if (MN[0] < u && MX[0] > u) can = 0;
	}
	else if (sz(MN) == 2) {
		if (MX[0] > u || MN[1] < u) can = 0;
	}
	else if (sz(MN) == 3) {
		can = 0;
	}

	return DP[u][fi] = make_tuple(can, mn, mx);
}


int main(){
	ri(N);
	bool g = 1;
	FOR(i,1,N) {
		int a,b; rii(a,b); --a; --b;
		G[a].pb(b);
		G[b].pb(a);
		if (sz(G[a]) > 3 || sz(G[b]) > 3) g = 0;
	}
	FOR(i,0,N) sort(all(G[i]));

	vi ans;
	if (g) {
		FOR(i,0,N) {
			auto [a, b, c] = f(i);
			if (a) ans.pb(i);
		}
	}


	if (sz(ans) == 0) printf("-1\n");
	else {
		for(int v : ans) printf("%d ", 1+v);
		printf("\n");
	}

	return 0;
}
