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

int N, M;
int A[MAXN];
vector<tuple<int, int, int>> E[MAXN];

pair<ll, vi> go(int i) {
    int n = sz(E[i]);
    vector<vector<ll>> DP(n + 1, vector<ll>(200, INFLL));
    DP[n][0] = 0;
    for (int p = n - 1; p >= 0; --p) {
        auto [time, perc, _] = E[i][p];
        // printf("%d %d\n", time, perc);
        for (int c = 0; c < 200; ++c) {
            DP[p][c] = DP[p + 1][c];
            if (c >= perc)
                DP[p][c] = min(DP[p][c], DP[p + 1][c - perc] + time);
            // printf("%d %d : %lld\n", p, c, DP[p][c]);
        }
    }
    int c = 100;
    FOR(j, 101, 200) if (DP[0][c] > DP[0][j]) c = j;
    vi inds;
    if (DP[0][c] != INFLL) {
        int a = 0, b = c;
        while (b > 0) {
            if (DP[a + 1][b] == DP[a][b]) ++a;
            else {
                auto [_, perc, ind] = E[i][a];
                inds.pb(ind);
                b -= perc;
                ++a;
            }
        }
    }
    // printf("%d : %lld %d\n", i, DP[0][c], n);
    return {DP[0][c], inds};
}

void solve() {
    rii(N, M);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) E[i].clear();
    FOR(_, 0, M) {
        int e, t, p; rii(e, t); ri(p);
        E[e - 1].pb({t, p, _ + 1});
    }
    vi ans;
    ll t = 0;
    FOR(i, 0, N) {
        auto [time, inds] = go(i);
        t += time;
        if (t > A[i]) {
            printf("-1\n");
            return;
        }
        for (auto j : inds) ans.pb(j);
    }
    printf("%d\n", sz(ans));
    for (auto i : ans) printf("%d ", i);
    printf("\n");
}



int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
