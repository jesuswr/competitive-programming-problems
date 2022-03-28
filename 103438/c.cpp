#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 998244353;
const int MAXN = 3010;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N;
int C[MAXN];
vi G[MAXN];

int SZ[MAXN];
void pre(int u = 0, int f = -1) {
    for (int i = 0; i < sz(G[u]); ++i) if (G[u][i] != f) {
            pre(G[u][i], u);
            SZ[u] += SZ[G[u][i]];
            if (SZ[G[u][i]] > SZ[G[u][0]]) swap(G[u][i], G[u][0]);
        }
    SZ[u] += 1;
}


ll ans;

vector<ll> go(int u, int c, int cnt, int f = -1) {
    int mid = min(cnt, SZ[u]);
    vector<ll> dp(2 * mid + 1);
    if (C[u] == c)
        dp[mid + 1]++;
    else
        dp[mid - 1]++;

    if (G[u][0] != f) {
        int v = G[u][0];
        vector<ll> rec_dp = go(v, c, cnt, u);
        vector<ll> new_dp = dp;
        int rec_mid = sz(rec_dp) / 2;
        for (int i = mid - 1; i <= mid + 1; ++i) {
            for (int j = max(rec_mid - i, 0); j < min(2 * mid + 1 - i + rec_mid , 2 * rec_mid + 1); ++j) {
                new_dp[i + j - rec_mid] = (new_dp[i + j - rec_mid] + 1ll * dp[i] * rec_dp[j]) % MOD;
            }
        }
        swap(dp, new_dp);
    }

    for (int k = 1; k < sz(G[u]); ++k) {
        int v = G[u][k];
        if (f != v) {
            auto rec_dp = go(v, c, cnt, u);
            vector<ll> new_dp = dp;
            int rec_mid = sz(rec_dp) / 2;
            for (int i = 0; i < 2 * mid + 1; ++i) {
                for (int j = max(rec_mid - i, 0); j < min(2 * mid + 1 - i + rec_mid , 2 * rec_mid + 1); ++j) {
                    new_dp[i + j - rec_mid] = (new_dp[i + j - rec_mid] + 1ll * dp[i] * rec_dp[j]) % MOD;
                }
            }
            swap(dp, new_dp);
        }
    }
    for (int i = mid + 1; i < 2 * mid + 1; ++i) {
        ans = (ans + dp[i]) % MOD;
    }
    // for (int i = 0; i < 2 * cnt + 1; ++i) {
    //     FOR(_, 0, u) printf("\t");
    //     // printf("%d %d %d %d: %d\n", u + 1, c, cnt, i, dp[i]);
    // }
    // printf("%d\n", u);
    return dp;
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(C[i]);
    map<int, int> cols;
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    FOR(i, 0, N) cols[C[i]]++;
    pre();
    for (auto [c, cnt] : cols) go(0, c, cnt);
    printf("%lld\n", ans);
    return 0;
}
