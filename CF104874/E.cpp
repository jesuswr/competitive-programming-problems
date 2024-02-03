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

int N, M;
vi G[MAXN]; 
int A[MAXN];

int DST[MAXN];
int F[MAXN];
void dfs(int u, int f = -1) {
	if (f == -1) DST[u] = 0;
	F[u] = f;
	for(int v : G[u]) if (v != f) {
		DST[v] = DST[u] + 1;
		dfs(v, u);
	}
}

int go_up(int u, int steps) {
	FOR(i,0,steps) u = F[u];
	return u;
}

int main(){
	rii(N,M);
	FOR(i,1,N) {
		int a, b; rii(a,b); --a; --b;
		G[a].pb(b);
		G[b].pb(a);
	}
	FOR(i,0,M) ri(A[i]);
	FOR(i,0,M) --A[i];


	dfs(A[0]);
	int farthest = A[0];
	FOR(i,0,M) if (DST[A[i]] > DST[farthest]) farthest = A[i];
	int candidate = go_up(farthest, DST[farthest] / 2);
	dfs(candidate);
	FOR(i,1,M) if (DST[A[0]] != DST[A[i]]) candidate = -1;

	if (candidate == -1) cout << "NO" << endl;
	else cout << "YES" << endl << candidate + 1 << endl;
	 

	return 0;
}
