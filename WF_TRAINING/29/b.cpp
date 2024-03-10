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
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 998244353;
const int MAXN = 1e5 + 10;
const int SQ = 500;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K;
vi G[MAXN];
int SZ[MAXN];

namespace small {
    ll DP[MAXN][SQ];
    ll dp[SQ];

    void f(int u = 0, int fat = -1) {
        FOR(i,2,K+2) DP[u][i] = 0;
        SZ[u] = 1;
        DP[u][1] = 1;

        for(int v : G[u]) if (v != fat) {
            f(v, u);

            FOR(i,1,SQ) dp[i] = 0;
            for(int i = 1; i <= min(SZ[u], K+1); ++i) {
                dp[i] += (DP[u][i] * (DP[v][K] + DP[v][K+1]));
                dp[i] %= MOD;
                for(int j = 1; i + j <= K+1 && j <= SZ[v]; ++j) {
                    dp[i + j] += (DP[u][i] * DP[v][j]);
                    dp[i + j] %= MOD; 
                }
            }

            SZ[u] += SZ[v];
            FOR(i,1,min(SZ[u], K+1)+1) DP[u][i] = dp[i];
        }
    }

    void gogopr() {
        f();
        int ans = (DP[0][K] + DP[0][K+1]) % MOD;
        cout << ans << endl;
    }
}

namespace big {
    map<int, ll> DP[MAXN], dp;

    void f (int u = 0, int p = -1) {
        DP[u].clear();
        
        SZ[u] = 1;
        DP[u][1] = 1;
        
        for (int v : G[u]) {
            if (v == p)
                continue;
            
            f(v, u);
            dp.clear();
            
            for (auto [i, x] : DP[u]) {
                if (DP[v].count(K)) (dp[i] += x * DP[v][K]) %= MOD;
                if (DP[v].count(K + 1)) (dp[i] += x * DP[v][K + 1]) %= MOD;
                for (auto [j, y] : DP[v]) {
                    if (i + j <= K + 1) (dp[i + j] += x * y) %= MOD;
                }
            }
            
            SZ[u] += SZ[v];
            DP[u] = dp;
        }
    }

    void gogopr() {
        f();
        int ans = (DP[0][K] + DP[0][K+1]) % MOD;
        cout << ans << endl;
    }
}



void solve() {
    rii(N,K);
    FOR(_,1,N) {
        int a,b; rii(a,b); --a;--b;
        G[a].pb(b);
        G[b].pb(a);
    }

    if (K + 1 < SQ) small::gogopr();
    else big::gogopr();

    FOR(i,0,N) G[i].clear();
}



int main(){
    int t; ri(t);
    while(t--) solve();
	return 0;
}
