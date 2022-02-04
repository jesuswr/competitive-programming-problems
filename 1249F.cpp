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
const int MAXN = 210; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
int A[MAXN];
vi G[MAXN];
int DP[MAXN][MAXN];


void f(int v, int fa) {
    for (int to : G[v]) {
        if (to == fa) continue;
        f(to, v);
    }

    for (int d = 0; d <= K; ++d) {
        if (d == 0) {
            DP[v][0] = A[v];
            for (int to : G[v]) {
                if (to == fa) continue;
                DP[v][0] += DP[to][K - 1];
            }
        }
        else if (d == K) {
            for (int to : G[v]) {
                if (to == fa) continue;
                DP[v][K] =  max(DP[v][K], DP[to][K - 1]);
            }
        }
        else {
            for (int to : G[v]) {
                if (to == fa) continue;
                int cnt = DP[to][d - 1];
                for (int to2 : G[v]) {
                    if (to == fa) continue;
                    if (to == to2) continue;
                    cnt += DP[to2][max(d - 1, K - d - 1)];
                }
                DP[v][d] = max(DP[v][d], cnt);
            }
        }
    }
    for (int i = K; i > 0; --i) DP[v][i - 1] = max(DP[v][i - 1], DP[v][i]);
}

int main() {
    rii(N, K);
    ++K;
    FOR(i, 0, N) ri(A[i]);
    FOR(_, 0, N - 1) {
        int a, b; rii(a, b);
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    f(0, 0);
    printf("%d\n", DP[0][0]);
    return 0;
}