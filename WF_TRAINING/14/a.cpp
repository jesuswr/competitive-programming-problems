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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, C, Q;
vi G[MAXN];

int T; // Timer
int IN[MAXN], OUT[MAXN], NXT[MAXN], SZ[MAXN], F[MAXN], H[MAXN];
void dfsSz(int v = 0, int p = -1) {
    SZ[v] = 1;
    if (p != -1) H[v] = H[p] + 1;
    for (auto &u : G[v]) if (u != p) {
            dfsSz(u, v);
            SZ[v] += SZ[u];
            if (SZ[u] > SZ[G[v][0]] || G[v][0] == p) swap(u, G[v][0]);
        }
}
void dfsHLD(int v = 0, int p = -1) {
    IN[v] = T++;
    F[v] = p;
    for (auto u : G[v]) if (u != p) {
            NXT[u] = (u == G[v][0] ? NXT[v] : u);
            dfsHLD(u, v);
        }
    OUT[v] = T;
}

int COL_TO_CNT[MAXN], CNT[MAXN];

stack<ii> ST[MAXN];
void update(int u, int col) {
	while(69) {
		int fu = NXT[u];
		int h = H[u] - H[fu] + (fu != 0);
		if (h == 0) break;
		int aux_h = h;

		while(!ST[fu].empty() && aux_h) {
			auto [_h, _col] = ST[fu].top(); ST[fu].pop();
			int rem = min(_h, aux_h);
		
			CNT[ COL_TO_CNT[ _col ] ]--;
			COL_TO_CNT[ _col ] -= rem;
			CNT[ COL_TO_CNT[ _col ] ]++;

			_h -= rem;
			aux_h -= rem;

			if (_h) 
				ST[fu].push({_h, _col});
		}
		
		CNT[ COL_TO_CNT[ col ] ]--;
		COL_TO_CNT[ col ] += h;
		CNT[ COL_TO_CNT[ col ] ]++;

		ST[fu].push({h, col});

		if (F[fu] == -1) break;
		u = F[fu];
	}
} 



int main(){
	rii(N, C), ri(Q);
	FOR(_,1,N) {
		int a,b; rii(a,b); --a; --b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfsSz();
	dfsHLD();

	CNT[0] = C;

	while(Q--) {
		int u, c, m; rii(u, c), ri(m);

		--u;
		update(u, c);

		// FOR(i,1,C+1) printf("\t %d : %d\n", i, COL_TO_CNT[i]);

		printf("%d\n", CNT[m]);
	}


	return 0;
}
