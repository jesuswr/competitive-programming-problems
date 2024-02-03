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

const int INF = 1e8;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e4+1;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K;
int X[MAXN], A[MAXN], B[MAXN], C[MAXN]; 
vii MX[MAXN];

void pre() {
	FOR(i,0,N) {
		vii mx(C[i], {-1,-1});
		vector<bool> v(C[i]);
		int it = 0, x = X[i];
		while(!v[x]) {
			v[x] = 1;
			int modx = x % K;
			if (x > mx[modx].F) 
				mx[modx] = {x, it};
			
			x = (A[i] * x + B[i]) % C[i];
			it++;
		}

		FOR(_,0,20) {
			ii cmx = {-1,-1};
			int ps = -1;
			FOR(j,0,C[i]) if (mx[j].F != -1) {
				if (mx[j].F > cmx.F) {
					cmx = mx[j];
					ps = j;
				}
			}
			if (ps != -1) {
				mx[ps] = {-1,-1};
				MX[i].pb(cmx);
			}
		}
		// for(auto [x, y] : MX[i]) cout << x << " " << y << endl;
		// cout << endl;
	}
}

void simple_sol() {
	int sm = 0;
	vi ts(N);
	FOR(i,0,N) {
		sm += MX[i][0].F;
		ts[i] = MX[i][0].S;
	}
	if (sm % K != 0) {
		printf("%d\n", sm);
		FOR(i,0,N) printf("%d%c", ts[i], " \n"[i + 1 == N]);
		return;
	}

	int bst = -1;
	FOR(i,0,N) if (sz(MX[i]) > 1) {
		if (bst == -1) {
			bst = i;
		}
		else if ( sm - MX[bst][0].F + MX[bst][1].F < sm - MX[i][0].F + MX[i][1].F ) {
			bst = i;
		}
	}

	if (bst == -1) {
		printf("-1\n");
		return;
	}

	sm = sm - MX[bst][0].F + MX[bst][1].F;
	ts[bst] = MX[bst][1].S;
	printf("%d\n", sm);
	FOR(i,0,N) printf("%d%c", ts[i], " \n"[i + 1 == N]);
}


int DP[MAXN][1001];
bool VIS[MAXN][1001];
int f(int p, int md) {
	int &ret = DP[p][md];
	if (VIS[p][md]) return ret;
	VIS[p][md] = 1;
	if (p == N) return ret = md > 0 ? 0 : -INF;

	ret = -INF;
	for(auto [xi, _] : MX[p]) {
		ret = max(ret, f(p+1, (xi + md) % K) + xi);
	}
	return ret;
}


void complex_sol() {
	int sm = f(0,0);
	if (sm < 0) {
		printf("-1\n");
		return;
	}

	printf("%d\n", sm);
	int md = 0;
	FOR(p,0,N) {
		for(auto [xi, t] : MX[p]) {
			if (sm == f(p+1, (xi + md) % K) + xi) {
				printf("%d%c", t, " \n"[p + 1 == N]);
				md = (xi + md) % K;
				sm -= xi;
				break;
			}
		}
	}
}

int main(){
	freopen("generators.in", "r", stdin);
	freopen("generators.out", "w", stdout);
 

	rii(N,K);
	FOR(i,0,N) rii(X[i], A[i]), rii(B[i], C[i]);
	pre();

	if (K >= 1000) 
		simple_sol();
	else 
		complex_sol();


	return 0;
}
