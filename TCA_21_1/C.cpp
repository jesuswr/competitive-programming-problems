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

// GJNM
int N, K, L;
int A[MAXN], B[MAXN];
set<int> M;
vi G[MAXN];
vi AA;

vector<ll> D[MAXN];

void bfs(int x) {
    D[x].resize(N + 1, LLINF);
    D[x][x] = 0;
    queue<int> ord; ord.push(x);

    while (!ord.empty()) {
        int u = ord.front(); ord.pop();
        for (auto v : G[u]) {
            if (D[x][u] + 1 < D[x][v]) {
                D[x][v] = D[x][u] + 1;
                ord.push(v);
            }
        }
    }
}


ll DP[1 << 22];
ll f(int msk) {
    if (DP[msk] != -1)
        return DP[msk];
    if (msk + 1 == (1 << SZ(AA)))
        return 0;

    int u = 0;
    for (int b = 0; b < SZ(AA); ++b) {
        if (msk & (1 << b))
            continue;
        u = b;
        break;
    }

    DP[msk] = LLINF;
    FOR(b, u + 1, SZ(AA)) {
        if (msk & (1 << b))
            continue;
        DP[msk] = min(DP[msk], D[AA[u]][AA[b]] + f(msk | (1 << u) | (1 << b)));
    }
    return DP[msk];
}

int main() {
    memset(DP, -1, sizeof(DP));
    riii(N, K, L);
    FOR(i, 0, K) {
        int j; ri(j);
        A[j]++;
    }
    FOR(i, 0, L) {
        int aux; ri(aux);
        M.insert(aux);
    }

    FOR(i, 0, N+1) {
        B[i] = A[i] ^ A[i + 1];
        if (B[i])
            AA.pb(i);
    }
    FOR(i, 1, N + 1) {
        for (auto m : M) {
            if (i - 1 + m <= N ) {
                G[i - 1].pb(i - 1 + m);
                G[i - 1 + m].pb(i - 1);
            }
        }
    }
    // FOR(i, 0, N + 2) printf("%d%c", A[i], " \n"[i == N + 1]);
    // printf(" ");
    // FOR(i, 0, N + 1) printf("%d%c", B[i], " \n"[i == N]);

    FOR(i, 0, N + 2) if (B[i]) bfs(i);

    if (f(0) >= LLINF)
        printf("-1\n");
    else
        printf("%lld\n", f(0));
    return 0;
}