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
const ll INFLL = 1e14;
const int MOD = 1e9+7;
const int MAXN = 110;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct HK {
	// A from 1 to A
	// B from A+1 to A+B < MAXN
	vector<vi> G; // edges A->B  //clear G for several test cases
	vi match, dist;
	int A, B;
	HK(int a, int b) {
		A = a; B = b;
		match.resize(A+B+1);
		dist.resize(A+B+1);
		G.resize(A+B+1);
	}
	bool bfs() {
		queue<int> q;
		FOR(i,1,A+1){
			if(match[i]==0){
				dist[i]=0;
				q.push(i);
			} else dist[i]=INF;
		}
		dist[0] = INF;
		while(!q.empty()) {
			int v = q.front(); q.pop();
			if(v!=0) {
				FOR(i,0,G[v].size()){
					int u = G[v][i];
					if(dist[match[u]]==INF) {
						dist[match[u]] = dist[v] + 1;
						q.push(match[u]);
					}
				}
			}
		}
		return (dist[0]!=INF);
	}
	bool dfs(int v) {
		if(v!=0) {
			FOR(i,0,G[v].size()){
				int u = G[v][i];
				if(dist[match[u]]==dist[v]+1) {
					if(dfs(match[u])) {
						match[u] = v;
						match[v] = u;
						return true;
					}
				}
			}
			dist[v] = INF;
			return false;
		}
		return true;
	}
	int go(){
		int MBM = 0;
		while(bfs())
			FOR(i,1,A+1)
				if(match[i]==0 && dfs(i))
					MBM++;
		return MBM;
	}
};


int N[2];
vi G[2][MAXN];
int DP[MAXN][MAXN];

int go(int u0, int u1, int f0, int f1) {
	int &r = DP[u0][u1];
	if (r != -1) return r;

	int ch0_sz = sz(G[0][u0]) - (f0 != -1) ;
	int ch1_sz = sz(G[1][u1]) - (f0 != -1);

	if (ch1_sz == 0) return r = 1;
	if (ch1_sz > ch0_sz) return r = 0;

	HK hk(sz(G[0][u0]), sz(G[1][u1]));
	for(int i = 0; i < sz(G[0][u0]); ++i) if (G[0][u0][i] != f0) {
		for(int j = 0; j < sz(G[1][u1]); ++j) if (G[1][u1][j] != f1) {
			if (go(G[0][u0][i], G[1][u1][j], u0, u1)) {
				hk.G[i + 1].pb(sz(G[0][u0]) + 1 + j);
			}
		}
	}
	return r = (hk.go() == ch1_sz);
}



int main(){
	FOR(i,0,2) {
		ri(N[i]);
		FOR(_,1,N[i]) {
			int u,v; rii(u,v); --u, --v;
			G[i][u].pb(v);
			G[i][v].pb(u);
		}
	}

	FOR(r,0,N[0]) {
		FOR(a,0,N[0]) FOR(b,0,N[1]) DP[a][b] = -1; 
		if (go(r, 0, -1, -1)) {
			cout << 'Y' << endl;
			return 0;
		}
	}
	cout << 'N' << endl;
	return 0;
}
