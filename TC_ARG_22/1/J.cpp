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
const int MAXN = 2e4+5;
const int MAXK = 9;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N,M,K;
vii G[MAXN];
int E,TM;
vi P[MAXN][MAXK];
int X,Y;

int DST[MAXN][1 << MAXK];
vector<int> go(int s) {
	FOR(i,0,N) FOR(j,0,1 << K) DST[i][j] = TM + 2;
	priority_queue< tuple<int, int, int> > pq;

	pq.push({0, s, 0});
	DST[s][0] = 0;

	vector<int> ret(1 << K, TM + 2);

	while(!pq.empty()) {
		auto [dst, u, msk] = pq.top(); pq.pop();
		dst = -dst;
		// printf("%lld %d %d\n", dst, u, msk);
		ret[msk] = min(ret[msk], dst);
		if (dst > TM) break;

		FOR(b,0,K) {
			if (msk & (1 << b)) continue;
			auto it = lower_bound(all(P[u][b]), dst);
			if (it != P[u][b].end()) {
				// printf("alo?\n");
				int new_msk = msk | (1 << b);
				int new_cst = *it;
				if (DST[u][new_msk] > new_cst) {
					DST[u][new_msk] = new_cst;
					pq.push({-new_cst, u, new_msk});
				}
			}
		}

		for(auto [v, c] : G[u]) {
			if (DST[v][msk] > DST[u][msk] + c) {
				DST[v][msk] = DST[u][msk] + c;
				pq.push({-DST[v][msk], v, msk});
			}
		}
	}

	return ret;
}

void solve() {
	rii(N,M),ri(K);
	FOR(_,0,M) {
		int u,v,w;
		rii(u,v), ri(w);
		--u, --v;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	rii(E,TM);
	FOR(_,0,E) {
		int p,x,t;
		rii(p,x), ri(t);
		--p, --x;
		P[x][p].pb(t);
	}
	rii(X,Y);
	FOR(i,0,N) FOR(j,0,K) sort(all(P[i][j]));

	vector<int> ax = go(X-1);
	vector<int> ay = go(Y-1);
	// vector<ll> ay = ax;

	int mn = TM + 2;
	mn = min(mn, min(ax[(1 << K) - 1], ay[(1 << K) - 1]));
	FOR(i, 0, 1 << K) FOR(j, 0, 1 << K) {
		if ( (i | j) == (1 << K) - 1 ) {
			mn = min(mn, max(ax[i], ay[j]));
		}
	}

	// printf("%lld\n", mn);
	if (mn > TM) mn = -1;
	printf("%d\n", mn);


	FOR(i,0,N) FOR(j,0,K) P[i][j].clear();
	FOR(i,0,N) G[i].clear();

}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
