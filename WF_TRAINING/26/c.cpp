#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
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

typedef ll tf;
typedef ll tc;

const tf INFFLOW = 1e9;
const tc INFCOST = 1e9;
struct MCF{ 
	int n;
	vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge, prevnode;
	priority_queue<pair<tc, int>, vector<pair<tc,int>>, greater<pair<tc,int>>> q;
	struct edge{int to, rev; tf f, cap; tc cost;};
	vector<vector<edge>> g;
	MCF(int n) : n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n) {}
	void add_edge(int s, int t, tf cap, tc cost) {
		g[s].pb((edge){t,sz(g[t]),0,cap,cost});
		g[t].pb((edge){s,sz(g[s])-1,0,0,-cost});
	}
	pair<tf, tc> get_flow(int s, int t) {
		tf flow = 0; tc flowcost=0;
		while(1) {
			q.push({0, s});
			fill(all(prio), INFCOST);
			prio[s] = 0; curflow[s] = INFFLOW;
			while(!q.empty()) {
				auto cur = q.top();
				tc d = cur.F;
				int u = cur.S;
				q.pop();
				if (d != prio[u]) continue;
				for(int i = 0; i < sz(g[u]); ++i) {
					edge &e = g[u][i];
					int v = e.to;
					if(e.cap <= e.f) continue;
					tc nprio = prio[u] +e.cost + pot[u] - pot[v];
					if(prio[v] > nprio) {
						prio[v] = nprio;
						q.push({nprio, v});
						prevnode[v] = u; prevedge[v] = i;
						curflow[v] = min(curflow[u], e.cap-e.f);
					}
				}
			}
			if (prio[t] == INFCOST) break;
			FOR(i,0,n) pot[i] += prio[i];
			tf df = min(curflow[t], INFFLOW-flow);
			flow += df;
			for(int v = t; v!=s; v=prevnode[v]) {
				edge &e=g[prevnode[v]][prevedge[v]];
				e.f+= df; g[v][e.rev].f -= df;
				flowcost += df*e.cost;
			}
		}
		return {flow, flowcost};
	}
};


int R, C;
ll A[123][123];
bool vist[123][123];
ll mxR[123], mxC[123];

int getNode(int r, int c) {
	return r * C + c;
}
int getRow(int r) { return R*C + r; }
int getCol(int c) { return R*C + R + c; }

int main() {
	rii(R, C);
	FOR(i,0,R) FOR(j,0,C) {
		lri(A[i][j]);
		mxR[i] = max(mxR[i], A[i][j]);
		mxC[j] = max(mxC[j], A[i][j]);
	}

	int N = R*C + R + C + 2;
	int s = N-2, t = N-1;
	MCF mcf(N);

	FOR(i,0,R) FOR(j,0,C) {
		if(A[i][j] == mxR[i]) mcf.add_edge(getNode(i,j), getRow(i), INFFLOW, 0);
		if(A[i][j] == mxC[j]) mcf.add_edge(getNode(i,j), getCol(j), INFFLOW, 0);

		mcf.add_edge(s, getNode(i,j), 1, 1);
	}
	FOR(i,0,R) mcf.add_edge(getRow(i), t, INFFLOW, 0);
	FOR(i,0,C) mcf.add_edge(getCol(i), t, INFFLOW, 0);

	mcf.get_flow(s, t);

	ll ans = 0;
	for (auto &e : mcf.g[s]) {
		if (e.cost > 0 && e.f > 0) vist[e.to / C][e.to % C] = true;
	}

	FOR(i,0,R) FOR(j,0,C) if(!vist[i][j] && A[i][j] > 0) {
		ans += A[i][j] - 1;
	}

	printf("%lld\n", ans);



	return 0;
}

