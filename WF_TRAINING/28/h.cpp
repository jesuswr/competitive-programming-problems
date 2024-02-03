#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second 
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 5e5+5;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void fastIO() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
}

int n, k, d[MAXN], deg[MAXN];
vi G[MAXN];

int T;
int IN[MAXN], OUT[MAXN], NXT[MAXN], SZ[MAXN], F[MAXN], H[MAXN], CMP[MAXN];
void dfsSz(int v = 0, int root = 0, int p = -1) {
	SZ[v] = 1;
	CMP[v] = root;
	if (p != -1) H[v] = H[p] + 1;
	for (auto &u : G[v]) if (u != p) {
		dfsSz(u, root, v);
		SZ[v] += SZ[u];
		if(SZ[u] > SZ[G[v][0]] || G[v][0] == p) swap(u, G[v][0]);
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

bool vist[MAXN];

int CNT;
vi cyc[MAXN];
bool viscyc[MAXN];
int cn[MAXN], pos[MAXN];

int ans[MAXN];
vi cycans[MAXN];

void solve (int v) {
	int kk = k+1;
	int u = CMP[v];

	while (kk > 0) {
		int anc = NXT[v]; 

		ans[IN[v]+1]--;
		if (H[v] - H[anc] + 1 > kk) {
			ans[IN[v]-kk+1]++;
			kk = 0;
			break;
		}

		ans[IN[anc]]++;
		kk -= H[v] - H[anc] + 1;
		v = F[anc];
		if (v == -1) break;
	}

	if (kk == 0) return;
	
	kk = min(kk, sz(cyc[cn[u]])-1);
	cycans[cn[u]][pos[u]+1]++;

	// cout << u+1 << " " << kk << endl;
	

	if (pos[u] + kk + 1 <= sz(cyc[cn[u]])) cycans[cn[u]][pos[u] + kk + 1]--;
	else {
		cycans[cn[u]][sz(cyc[cn[u]])]--;
		cycans[cn[u]][0]++;
		cycans[cn[u]][ (pos[u] + kk + 1) % sz(cyc[cn[u]])]--;
	}
}

int main() {
	rii(n, k);
	FOR(i,0,n) {
		ri(d[i]); d[i]--;
		deg[d[i]]++;
	}

	queue<int> q;
	FOR(i,0,n) if (deg[i] == 0) q.push(i);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		vist[v] = true;
		deg[d[v]]--;
		if (deg[d[v]] == 0) q.push(d[v]);
	}

	FOR(i,0,n) if (!vist[i]) NXT[i] = i;

	FOR(i,0,n) if (vist[i]) G[d[i]].pb(i);
	FOR(i,0,n) if (!vist[i]) dfsSz(i, i);
	FOR(i,0,n) if (!vist[i]) dfsHLD(i);


	FOR(i,0,n) if (!vist[i] && !viscyc[i]) {
		cyc[CNT].pb(i);
		int v = d[i]; viscyc[i] = true;
		cn[i] = CNT, pos[i] = 0;
		while (v != i) {
			cn[v] = CNT, pos[v] = sz(cyc[CNT]);
			viscyc[v] = true, cyc[CNT].pb(v), v = d[v];
		}

		cycans[CNT] = vi(sz(cyc[CNT]) + 5);
		CNT++;
	}


	FOR(i,0,n) solve(i);

	FOR(i,1,n) ans[i] += ans[i-1];
	FOR(i,0,CNT) FOR(j,1,sz(cyc[i])) cycans[i][j] += cycans[i][j-1];


	FOR(i,0,n) {
		if (vist[i]) printf("%d\n", ans[IN[i]]);
		else {
			printf("%d\n", ans[IN[i]] + cycans[cn[i]][pos[i]]);
		}
	}










	return 0;
}
