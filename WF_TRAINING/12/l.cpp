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
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K;
int A[MAXN];
vi INDS[MAXN];

int DP[MAXN];
ii NXT[MAXN];
int f(int i) {
	if (DP[i] != -1) return DP[i];

	int ans = INF;
	// eliminar
	auto it = lower_bound(all(INDS[A[i]]) , i + 1);
	if (it == INDS[A[i]].end()) {
		ans = 1;
		NXT[i] = {1, N};
	}
	else {
		int j = *it;
		ans = 1 + f(j);
		NXT[i] = {1, j};
	}

	// dejar
	if (A[i] < K) {
		auto it = lower_bound(all(INDS[A[i] + 1]) , i + 1);
		if (it == INDS[A[i] + 1].end()) {
			ans = 0;
			NXT[i] = {0, N};
		}
		else {
			int j = *it;
			ans = min(ans, f(j));
			if (ans == f(j)) NXT[i] = {0, j};
		}
	}
	return DP[i] = ans;
}

int main(){
	ms(DP,-1);
	rii(N,K);
	--K;
	FOR(i,0,N) {
		ri(A[i]);
		A[i]--;
		INDS[A[i]].pb(i);
	}

	if (sz(INDS[0]) == 0) {
		printf("0\n");
		return 0;
	}

	int mn = f(INDS[0][0]);
	printf("%d\n", mn);
	vi inds;

	int u = INDS[0][0];
	while(mn) {
		auto [cst, v] = NXT[u];
		if (cst == 1) inds.pb(u);
		mn -= cst;
		u = v;
	}

	if (sz(inds)) {
		for(int x : inds) printf("%d ", 1+x);
		printf("\n");
	}


	return 0;
}
