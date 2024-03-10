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
const int MAXN = 3e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int V, E;
vii G[MAXN];

priority_queue< pair< int, int > > pq;
int DST[MAXN];
ii COSTS[MAXN];

ii get_new_costs(ii costs, int new_c) {
	if (costs.F < new_c) {
		costs.S = costs.F;
		costs.F = new_c;
	}
	else if (costs.S < new_c) {
		costs.S = new_c;
	}
	return costs;
}

int f(int s = 0) {
	FOR(i,0,V) DST[i] = 2e9 + 1;
	DST[s] = 0;
	COSTS[s] = {0,0};
	pq.push({0,0});

	while(!pq.empty()) {
		auto [cst, u] = pq.top(); pq.pop();
		cst = -cst;

		for(auto [v,c] : G[u]) {
			ii costs = get_new_costs(COSTS[u], c);
			int new_cst = costs.F + costs.S;
			if (new_cst < DST[v]) {
				DST[v] = new_cst;
				COSTS[v] = costs;
				pq.push({-new_cst, v});
			}
		}
	}

	return DST[V-1];
}

int main(){
	rii(V, E);
	FOR(_,0,E) {
		int a,b,c; rii(a,b); --a; --b; ri(c);
		G[a].pb({b,c});
		G[b].pb({a,c});
	}
	cout << f() << endl;

	return 0;
}
