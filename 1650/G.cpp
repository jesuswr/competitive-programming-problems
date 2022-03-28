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
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N, M, S, T;
vi G[MAXN];


void solve() {
    rii(N, M);
    rii(S, T);
    --S; --T;
    FOR(i, 0, N) G[i].clear();
    FOR(i, 0, M) {
        int a, b; rii(a, b);
        // printf("%d - %d\n", a, b);
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    vector<ll> DP(N), DP2(N);
    DP[S] = DP[T] = 1;
    vi VIS(N), C(N);
    queue<int> q;
    q.push(S); q.push(T);
    VIS[S] = 1; VIS[T] = 2;
    ll ans = 0;
    int dst = N + 69;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : G[u]) {
            if (VIS[v] == VIS[u]) {
                if (C[u] == C[v]) {
                    DP2[u] += DP[v];
                    DP2[u] %= MOD;
                }
                else if (C[u] - 1 == C[v]) {
                    DP2[u] += DP2[v];
                    DP2[u] %= MOD;
                }
            }
        }
        // printf("%d %d %d %d\n", u + 1, VIS[u], DP[u], DP2[u]);
        for (auto v : G[u]) {
            if (VIS[v] == 0) {
                VIS[v] = VIS[u];
                C[v] = C[u] + 1;
                q.push(v);
                DP[v] = DP[u];
            }
            else if (VIS[v] == VIS[u] && C[v] == C[u] + 1) {
                DP[v] += DP[u];
                DP[v] %= MOD;
            }
            else if (VIS[v] != VIS[u] && (C[u] > C[v] || (C[u] == C[v] && VIS[u] == 2))) {
                dst = min(dst, C[u] + C[v] + 1);
                if ((C[u] + C[v] + 1 - dst) <= 1)
                    ans += DP[u] * DP[v];
                if ((C[u] + C[v] + 1 - dst) <= 0) {
                    // printf("\t\t\t%d\n", DP2[u] * DP[v] + DP[u] * DP2[v]);
                    ans += DP2[u] * DP[v] + DP[u] * DP2[v];
                }
                ans %= MOD;
            }
        }
    }
    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
