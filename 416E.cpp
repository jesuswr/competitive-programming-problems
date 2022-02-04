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
const int MAXN = 510; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int V, E;
ll G[MAXN][MAXN];
ll FW[MAXN][MAXN];
int IN[MAXN][MAXN];

int main() {
    rii(V, E);
    FOR(i, 0, V) FOR(j, 0, V) FW[i][j] = (i == j ? 0 : LLINF + 1);
    FOR(i, 0, V) FOR(j, 0, V) G[i][j] = (i == j ? 0 : LLINF + 69);
    FOR(_, 0, E) {
        int u, v, c;
        riii(u, v, c);
        --u; --v;
        G[u][v] = G[v][u] = FW[u][v] = FW[v][u] = c;
    }
    FOR(k, 0, V) FOR(i, 0, V) FOR(j, 0, V) FW[i][j] = min(FW[i][j], FW[i][k] + FW[k][j]);

    FOR(s, 0, V) FOR(t, 0, V) {
        int in = 0;
        FOR(u, 0, V) if (u != t)
            in += (FW[s][u] + G[u][t] == FW[s][t]);
        IN[s][t] = in;
    }
    FOR(s, 0, V) FOR(t, s + 1, V) {
        int cnt = 0;
        FOR(u, 0, V) if (u != s) {
            if (FW[s][u] + FW[u][t] == FW[s][t])
                cnt += IN[s][u];
        }
        printf("%d ", cnt);
    }
    printf("\n");
    return 0;
}