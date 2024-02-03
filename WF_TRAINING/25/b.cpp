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
const int MAXN = 5010;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int V, N, M, E;
vii G[MAXN];

int DST[MAXN][MAXN];
void dijkstra(int s) {
	FOR(i,0,V) DST[s][i] = 1e9;
	priority_queue< ii > pq;

	pq.push({0,s});
	DST[s][s] = 0;
	while(!pq.empty()) {
		auto [cst, u] = pq.top(); pq.pop();
		cst = -cst;

		if (DST[s][u] != cst) continue;

		for(auto [v,w] : G[u]) {
			if (cst + w < DST[s][v]) {
				DST[s][v] = cst + w;
				pq.push({-DST[s][v], v});
			}
		}
	}
}
vii Gr[MAXN];
int DST2[MAXN][MAXN];
void dijkstra2(int s) {
	FOR(i,0,V) DST2[s][i] = 1e9;
	priority_queue< ii > pq;

	pq.push({0,s});
	DST2[s][s] = 0;
	while(!pq.empty()) {
		auto [cst, u] = pq.top(); pq.pop();
		cst = -cst;

		if (DST2[s][u] != cst) continue;

		for(auto [v,w] : Gr[u]) {
			if (cst + w < DST2[s][v]) {
				DST2[s][v] = cst + w;
				pq.push({-DST2[s][v], v});
			}
		}
	}
}

ll CST[MAXN];

ll C(int i, int j) {
	ll sm = CST[j] - (i > 0 ? CST[i-1] : 0);
	return sm * (j-i);
}

ll DP[MAXN][MAXN];

ll f(int i, int j) {
	if (DP[i][j] != -1) return DP[i][j];
	if (i == N) return 0;
	if (j == M-1) return C(i,N-1);

	DP[i][j] = INFLL;
	int lim = j == 0 ?  N : i / j;
	for(int k = 1; k <= lim && i + k <= N; k++) {
		DP[i][j] = min(DP[i][j], f(i+k, j+1) + C(i, i+k-1));
	}
	return DP[i][j];
}

int main(){
	ms(DP,-1);
	rii(V,N), rii(M,E);
	FOR(_,0,E) {
		int u,v,w; rii(u,v), ri(w);
		--u,--v;
		G[u].pb({v,w});
		Gr[v].pb({u,w});
	}

	dijkstra(N);
	dijkstra2(N);

	FOR(i,0,N) CST[i] = DST[N][i] + DST2[N][i];
	sort(CST, CST+N);
	FOR(i,1,N) CST[i] += CST[i-1];

	cout << f(0,0) << endl;	


	return 0;
}
