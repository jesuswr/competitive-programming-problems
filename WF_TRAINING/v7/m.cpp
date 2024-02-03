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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N,M;
int P,G;
vii GR[MAXN];

vector<ll> DST;
vector<ll> dijkstra(int s) {
	DST[s] = 0;
	priority_queue< pair<ll, int> >  pq; pq.push({0,s});

	while(!pq.empty()) {
		auto [cst, u] = pq.top(); pq.pop();
		cst = -cst;
		if (cst != DST[u]) continue;

		for(auto [v, w] : GR[u]) {
			if (DST[v] > cst + w) {
				DST[v] = cst + w;
				pq.push({-DST[v], v});
			}
		}
	}
	return DST;
}

int main(){
	rii(N,M);
	DST.resize(N);
	rii(P,G); --P, --G;
	FOR(_,0,M) {
		int a,b; rii(a,b); --a,--b; int w; ri(w);
		GR[a].pb({b,w});
		GR[b].pb({a,w});
	}

	FOR(i,0,N) DST[i] = INFLL;
	auto dst = dijkstra(P);
	FOR(i,0,N) DST[i] = INFLL;
	DST[G] = -INFLL;
	auto dst_no_g = dijkstra(P);

	bool g = 0;
	FOR(i,0,N) if (i != P && i != G) {
		if (dst[i] == 2 * dst[G] && dst[i] < dst_no_g[i]) g = 1, cout << i+1 << ' ';
	}
	if (!g) cout <<'*';
	cout << endl;

	return 0;
}
