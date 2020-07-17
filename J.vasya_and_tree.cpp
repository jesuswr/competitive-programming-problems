#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e6; // CAMBIAR ESTE
const ll MAX_D = 4e5;


ll BIT[maxN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
	p++;	// esto es porque el bit esta indexado desde 1
	for (; p < maxN; p += p & -p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
		BIT[p] += val;
}
ll sumBIT(int p) {
	p++;
	ll ret = 0;
	for (; p; p -= p & -p)
		ret += BIT[p];
	return ret;
}

void updBITRANGE(int l, int r, ll val) {
	updBIT(l, val);
	updBIT(r + 1, -val);
}

// GJNM
int V, Q;
vi G[maxN];
vector< pair<ll, ll> > QUERIES[maxN];

ll CNT[maxN];

void dfs(int v, int h, int f = -1){
	for(auto &p : QUERIES[v]){
		updBITRANGE(h, h+p.F, p.S);
	}

	CNT[v] = sumBIT(h);

	for(auto w : G[v]){
		if ( f == w )
			continue;
		dfs(w, h+1, v);
	}

	for(auto &p : QUERIES[v]){
		updBITRANGE(h, h+p.F, -p.S);
	}
}


int main() {
	ri(V);
	FOR(i, 1, V) {
		int a, b;
		rii(a, b);
		G[a].pb(b);
		G[b].pb(a);
	}
	ri(Q);
	FOR(i, 0, Q) {
		int v; ri(v);
		ll d, x; rll(d, x);
		d = min(d, MAX_D);
		QUERIES[v].pb({d, x});
	}

	dfs(1, 0);

	FOR(i,1,V+1){
		printf("%lld ", CNT[i]);
	}
	printf("\n");


	return 0;
}