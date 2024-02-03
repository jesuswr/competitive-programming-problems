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
	// FOR(i,0,V) DST[s][i] = 1e9;
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

ll CST[MAXN];


vector<long long> dp_before(MAXN), dp_cur(MAXN);

long long C(int i, int j) {
	ll sum = CST[j] - (i > 0 ?  CST[i-1] : 0);
	return sum * (j - i);
}

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    pair<long long, int> best = {INFLL, -1};

    for (int k = optl; k <= min(mid, optr); k++) {
        best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int solve() {
    for (int i = 0; i < N; i++)
        dp_before[i] = C(0, i);
    FOR(i,0,)
    for (int i = 1; i < M; i++) {
        compute(0, N - 1, 0, N - 1);
        dp_before = dp_cur;
    }

    return dp_before[N - 1];
}


int main(){
	ms(DST, INF);
	rii(V,N), rii(M,E);
	FOR(_,0,E) {
		int u,v,w; rii(u,v), ri(w);
		--u,--v;
		G[u].pb({v,w});
	}
	FOR(i,0,N+1) dijkstra(i);

	FOR(i,0,N) CST[i] = DST[i][N] + DST[N][i];

	sort(CST, CST+N);

	FOR(i,1,N) CST[i] += CST[i-1];

	cout << solve() << endl;


	return 0;
}