#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int P = 1777771;
const int MOD[2] = {999727999, 1070777777};
const int PI[2] = {325255434, 10018302};

struct Hash {
    vector<int> h[2], pi[2];
    Hash(string& s) {
        FOR(k, 0, 2)h[k].resize(SZ(s) + 1), pi[k].resize(SZ(s) + 1);
        FOR(k, 0, 2) {
            h[k][0] = 0; pi[k][0] = 1;
            ll p = 1;
            FOR(i, 1, SZ(s) + 1) {
                h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
                pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
                p = (p * P) % MOD[k];
            }
        }
    }
    ll get(int s, int e) { // [s,e)
        ll h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
        h0 = (1LL * h0 * pi[0][s]) % MOD[0];
        ll h1 = (h[1][e] - h[1][s] + MOD[1]) % MOD[1];
        h1 = (1LL * h1 * pi[1][s]) % MOD[1];
        return (h0 << 32) | h1;
    }
};

// GJNM
int N, M, Q;
string S;
map<ll, int> MP;
vector< pair<int, char> > G[MAXN];
ll H0[MAXN], H1[MAXN];
int TO[MAXN][25];

void dfs(int u, ll p0, ll p1) {
    if (u > 0)
        MP[(H0[u] << 32) | H1[u]] = u;
    for (auto [v, c] : G[u]) {
        H0[v] = (H0[u] + c * p0) % MOD[0];
        H1[v] = (H1[u] + c * p1) % MOD[1];
        dfs(v, (p0 * P) % MOD[0], (p1 * P) % MOD[1]);
    }
}

void solve() {
    riii(N, M, Q);
    FOR(i, 0, N + 1) G[i].clear();
    MP.clear();
    FOR(i, 1, N + 1) {
        int fi; char c;
        dadsadasda = scanf("%d %c\n", &fi, &c);
        G[fi].pb({i, c});
    }
    cin >> S;
    dfs(0, 1, 1);


    Hash H(S);
    vi NXT(M + 2);
    NXT[M] = M + 1;
    NXT[M + 1] = M + 1;

    for (int i = M - 1; i >= 0; --i) {
        int lo = i, hi = M;
        while (lo < hi) {
            int mi = lo + (hi - lo + 1) / 2;
            if (MP.find(H.get(i, mi)) != MP.end())
                lo = mi;
            else
                hi = mi - 1;
        }
        NXT[i] = lo + 1;
    }

    for (int i = M + 1; i >= 0; --i) {
        TO[i][0] = NXT[i];
        for (int b = 1; b < 25; ++b) {
            TO[i][b] = TO[ TO[i][b - 1] ][b - 1];
        }
    }

    while (Q--) {
        int l, r; rii(l, r); --l, --r;

        int cnt = 0;
        for (int b = 24; b >= 0; --b) {
            if (TO[l][b] <= r) {
                l = TO[l][b];
                cnt += (1 << b);
            }
        }
        int u = MP[H.get(l, r + 1)];
        printf("%d %d\n", cnt + (u == 0), u);
    }

}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}