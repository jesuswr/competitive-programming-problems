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
const int MAXN = 2e5 + 123; // CAMBIAR ESTE

// GJNM
int N, M;
int D[MAXN];
vi G[MAXN];
bool VIS[MAXN][2];


void bfs() {
    FOR(i, 0, N) D[i] = INF;
    queue<int> ord;
    ord.push(0); D[0] = 0;
    while (!ord.empty()) {
        int x = ord.front(); ord.pop();
        for (auto y : G[x]) {
            if (D[y] > D[x] + 1) {
                D[y] = D[x] + 1;
                ord.push(y);
            }
        }
    }
}

int MN[MAXN][2];
void dfs(int x, int t) {
    MN[x][t] = min(MN[x][t], D[x]);
    VIS[x][t] = true;
    for (auto y : G[x]) {
        if (D[x] < D[y]) {
            //printf("1 DEL (%d, %d) AL (%d, %d)\n", x + 1, t, y + 1, t);
            if (!VIS[y][t]) dfs(y, t);
            MN[x][t] = min(MN[x][t], MN[y][t]);
        }
        else if (t == 0) {
            //printf("2 DEL (%d, %d) AL (%d, %d)\n", x + 1, t, y + 1, 1);
            if (!VIS[y][1]) dfs(y, 1);
            MN[x][t] = min(MN[x][t], MN[y][1]);
        }
    }
}

void clean() {
    FOR(i, 0, N) G[i].clear();
    FOR(i, 0, N) VIS[i][0] = VIS[i][1] = false;
    FOR(i, 0, N) MN[i][0] = MN[i][1] = INF;
}

void solve() {
    rii(N, M);
    FOR(i, 0, N) MN[i][0] = MN[i][1] = INF;
    FOR(i, 0, M) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
    }
    bfs();

    FOR(i, 0, N) if (!VIS[i][0]) dfs(i, 0);

    FOR(i, 0, N) printf("%d ", min(MN[i][0], MN[i][1]));
    printf("\n");
    clean();
}





int main() {
    int t;
    ri(t);
    while (t--) solve();


    return 0;
}