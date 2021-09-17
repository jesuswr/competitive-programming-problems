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
const int MAXN = 2e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi G[MAXN];

int DP[2][MAXN];
void f(int u, int fat = -1) {
    for (auto v : G[u])
        if (v != fat)
            f(v, u);

    pii mxs = {0, 0};
    int bst_diam = 0;
    for (auto v : G[u])
        if (v != fat) {
            bst_diam = max(bst_diam, DP[1][v]);
            if (DP[0][v] + 1 > mxs.F) {
                mxs.S = mxs.F;
                mxs.F = DP[0][v] + 1;
            }
            else if (DP[0][v] + 1 > mxs.S)
                mxs.S = DP[0][v] + 1;
        }
    bst_diam = max(bst_diam, mxs.F + mxs.S);
    DP[0][u] = mxs.F;
    DP[1][u] = bst_diam;
    // printf("%d : %d %d\n", u, DP[0][u], DP[1][u]);
}

int main() {
    ri(N);
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    f(0);
    printf("%d\n", max(DP[0][0], DP[1][0]));
    return 0;
}