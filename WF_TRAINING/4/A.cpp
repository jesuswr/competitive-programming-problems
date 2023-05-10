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
const int MAXN = 1010;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
vi G[MAXN], Gi[MAXN];

void dfs(int u, vector<bool> &v, vector<int> &cnt) {
	v[u] = 69;
	cnt[u]++;

	for(int x : Gi[u]) if (!v[x]) 
		dfs(x, v, cnt);
}

bool go(int u) {
	vector<bool> v1(N), v2(N), v3(N);
	vector<int> cnt(N);
	v1[u] = v2[u] = 1;
	dfs(G[u][0], v1, cnt);
	dfs(G[u][1], v2, cnt);
	dfs(u, v3, cnt);
	FOR(i,0,N) if (i != u && cnt[i] > 2) return true;
	return false;
}

int main(){
	ri(N);
	FOR(i,0,N) {
		int x,y; rii(x,y); --x, --y;
		G[i].pb(x);
		G[i].pb(y);
		Gi[x].pb(i);
		Gi[y].pb(i);
	}
	FOR(i,0,N) cout << (go(i) ? 'Y' : 'N');
	cout << endl;
	return 0;
}
