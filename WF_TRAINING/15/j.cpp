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

struct Helper {
	vector<ll> DP, LZY;
	void resize(int add) {
		while(add--) {
			DP.pb(0);
			LZY.pb(0);
		}
	}

	void shift(int x) {
		if (LZY[x] != 0) {
			DP[x+1] = max(DP[x+1], DP[x] + LZY[x]);
			LZY[x+1] += LZY[x];
			LZY[x] = 0;
		}
	}

	void add(int x, ll val) {
		DP[x] += val;
	}
	
	ll get(int x) {
		return DP[x];
	}

	void add_lzy(ll val) {
		LZY[0] += val;
	}

	int size() {
		return sz(DP);
	}
};

int N; 
vi G[MAXN];
int C[MAXN];

vector<Helper> DP;

int f(int u) {
	if (sz(G[u]) == 0) {
		int ind = sz(DP);
		DP.emplace_back();
		DP[ind].resize(2);
		DP[ind].add(1, C[u]);
		return ind;
	}
	else {
		vi inds;
		for(int v : G[u]) {
			int i = f(v);
			if (!inds.empty() && DP[inds[0]].size() < DP[i].size()) {
				inds.pb(inds[0]);
				inds[0] = i;
			}
			else 
				inds.pb(i);
		}

		int big = inds[0];
		DP[big].resize( 1 );

		for(int i = 1; i < sz(inds); ++i) {
			int ind = inds[i];
			DP[ind].resize(1);
			for(int k = 0; k < DP[ind].size() - 1; ++k) {
				DP[big].shift(k); DP[ind].shift(k);
			}
		}

		DP[big].add_lzy(C[u]);
		return big;
	}
}



int main(){
	ri(N);
	vector<array<int,3>> A;
	FOR(i,0,N) {
		int l,r; rii(l,r); int c; ri(c);
		A.pb({l,r,c});
	}
	A.pb({0,1000005,0});
	sort(A.begin(), A.end(), [](auto a, auto b) {
		if (a[0] != b[0]) return a[0] < b[0];
		return a[1] > b[1];
	});

	stack<int> st;
	st.push(0);
	for(int i = 1; i <= N; ++i) {
		while( A[ st.top() ][1] < A[i][1] ) { 
			st.pop();
		}
		G[st.top()].pb(i);
		st.push(i);
		C[i] = A[i][2];
	}

	int ind = f(0);
	int diff = max(0, N + 2 - DP[ind].size());
	DP[ind].resize(diff);
	for(int i = 1; i <= N; ++i) {
		DP[ind].shift(i-1);
		printf("%lld ", DP[ind].get(i));
	}
	printf("\n");
	return 0;
}
