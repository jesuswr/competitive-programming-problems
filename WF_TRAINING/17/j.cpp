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
const int MAXN = 3010;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int V, E, K;
vii G[MAXN];

ll go(int x) {
	priority_queue< pair<ll, int> > pq;
	vector<ll> dist(V,INFLL);

	dist[0] = 1ll * x * K;
	pq.push({-dist[0], 0});

	while(!pq.empty()) {
		auto [cst, u] = pq.top(); pq.pop();
		cst = -cst;

		if (cst != dist[u]) continue;
		for(auto [v,w] : G[u]) {
			ll new_cst = cst + max(0, w-x);
			if (new_cst < dist[v]) {
				dist[v] = new_cst;
				pq.push({-new_cst, v});
			}
		}
	}
	
	return dist[V-1];
}

int main(){
	rii(V,E), ri(K);
	FOR(_,0,E) {
		int u,v,w; rii(u,v), ri(w);
		--u; --v;
		G[u].pb({v,w});
		G[v].pb({u,w});
	}

	ll ans = INFLL;
	ans = min(ans, go(0));
	FOR(i,0,V){
		for(auto [_, w] : G[i]) ans = min(ans, go(w));
	}
	cout << ans << endl;


	return 0;
}
