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

using namespace std;

typedef long long ll;
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
const int MAXN = 2e3 + 10; // CAMBIAR ESTE

// GJNM
int N, M;
ll W;
ll MAT[MAXN][MAXN];
ll DIST[2][MAXN][MAXN];

ll bfs(int k, int r, int c) {
    FOR(i, 0, N) FOR(j, 0, M) DIST[k][i][j] = LLINF;
    queue< pii > ord; ord.push({r, c});
    DIST[k][r][c] = 0;
    while (!ord.empty()) {
        auto [x, y] = ord.front(); ord.pop();
        for (auto dx : {1, 0, -1}) for (auto dy : {1, 0, -1}) {
                if (abs(dx) == abs(dy)) continue;
                int new_x = x + dx, new_y = y + dy;
                if (min(new_y, new_x) < 0 || new_x >= N || new_y >= M) continue;
                if (MAT[new_x][new_y] == -1) continue;

                if (DIST[k][x][y] + W < DIST[k][new_x][new_y]) {
                    DIST[k][new_x][new_y] = DIST[k][x][y] + W;
                    ord.push({new_x, new_y});
                }
            }
    }
    ll bst = LLINF;
    FOR(i, 0, N) FOR(j, 0, M) {
        if (MAT[i][j] > 0) bst = min(bst, MAT[i][j] + DIST[k][i][j]);
    }
    return bst;
}

int main() {
    rii(N, M); rl(W);
    FOR(i, 0, N) FOR(j, 0, M) rl(MAT[i][j]);
    ll op1 = bfs(0, 0, 0);
    ll op2 = bfs(1, N - 1, M - 1);
    ll ans = min(DIST[0][N - 1][M - 1], op1 + op2);
    if (ans >= LLINF) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}