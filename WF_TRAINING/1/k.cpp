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
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
vi G[MAXN];
int SZ[MAXN], H[MAXN];
vi CTRS;

void dfs_sizes(int u = 0, int f = -1) {
    SZ[u] = 0;
    if (f == -1) H[u] = 0;
    else H[u] = H[f] + 1;
    for(int v : G[u]) if (v != f) {
        dfs_sizes(v, u);
        SZ[u] += SZ[v];
    }
    SZ[u]++;
}
void dfs_centroids(int u = 0, int f = -1) {
    bool is_centroid = true;
    for(int v : G[u]) if (v != f) {
        if (2 * SZ[v] >= N) dfs_centroids(v, u);
        is_centroid &= 2* SZ[v] <= N;
    }
    if (is_centroid) CTRS.pb(u);
}

void calc_centroids() {
    dfs_sizes();
    dfs_centroids();
}   

ll knapsack(const vi &a) {
    bitset<MAXN> dp;
    dp[0] = 1;
    for(int x : a) {
        dp = (dp | (dp << x));
    }
    ll ans = 0;
    FOR(i,1,N) if (dp[i]) {
        ans = max(ans, 1ll * i * (N - 1 - i));
    }
    // cout << "    " << ans << endl;
    return ans;
}


ll go(int u) {
    dfs_sizes(u);
    ll ans = N;
    FOR(i, 0, N) ans += H[i];
    vector<int> ocs(N);
    for(int v : G[u]) 
        ocs[SZ[v]] += 1;
    vector<int> ws;
    FOR(i,0,N) if (ocs[i]) {
        int b = 1;
        while(ocs[i]) {
            int mn = min(b, ocs[i]);
            ws.push_back(mn * i);
            ocs[i] -= mn;
            b <<= 1;
        }
    }
    ans += knapsack(ws);
    return ans;
}



int main(){
    ri(N);
    FOR(i,1,N) {
        int pi; ri(pi); --pi; G[pi].pb(i); G[i].pb(pi);
    }
    calc_centroids();
    ll ans = 0;
    for(int c : CTRS) ans = max(ans, go(c));
    cout << ans << endl;
	return 0;
}
