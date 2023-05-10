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
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int V, E;
vi G[MAXN];
bool VIS[MAXN];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<ll,ll> MP;
ll get(ll x) {
	if (MP.find(x) != MP.end()) return MP[x];
	return MP[x] = rng();
}

bool IN[MAXN];
vi calc_cycle() {
	FOR(i,0,V) IN[i] = 1;
	queue<int> q;
	vi CNT(V);
	FOR(i,0,V) {
		CNT[i] = sz(G[i]);
		if (CNT[i] == 1) q.push(i);
	} 
	while(!q.empty()) {
		int u = q.front(); q.pop();
		IN[u] = 0;
		for(int v : G[u]) {
			CNT[v]--;
			if (CNT[v] == 1) {
				q.push(v);
			}
		}
	}

	vi ret;
	vector<bool> vis(V);
	int root = 0;
	FOR(i,0,V) if (IN[i]) root = i;
	q.push(root);
	vis[root] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		ret.pb(u);
		for(int v : G[u]) if (!vis[v] && IN[v]) {
			vis[v] = 1;
			q.push(v);
			break;
		}
	}
	return ret;
}

ll dfs(int u) {
	VIS[u] = 1;
	ll ans = 0;
	for(int v : G[u]) if (!VIS[v] && !IN[v]) {
		ans += dfs(v);
	}
	return get(ans);
}
 

bool go() {
	vi ord = calc_cycle();
	vector<ll> hshs;
	FOR(i,0,V) VIS[i] = 0;
	for(int v : ord) {
		hshs.pb(dfs(v));
	}
	bool all_equal = 1;
	FOR(i,1,sz(hshs)) all_equal &= hshs[i] == hshs[i-1];
	bool xyxy = false;
	if (sz(hshs) % 2 == 0) {
		xyxy = true;
		FOR(i,2,sz(hshs)) xyxy &= hshs[i] == hshs[i-2];
	}
	return all_equal || xyxy;
}


void solve() {
	rii(V,E);
	FOR(i,0,V) G[i].clear();
	FOR(_,0,E) {
		int a,b; rii(a,b);
		--a;--b;
		G[a].pb(b);
		G[b].pb(a);
	}
	if (E > V) {
		printf("NO\n");
	}
	else if (E < V || go()) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}


}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
