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
const int MAXN = 1e5; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M, K;
int sx, sy, ex, ey;
string MAT[1010];
set<int> R[1010], C[1010];
int D[1010][1010];

int bfs() {
    FOR(i, 0, N) FOR(j, 0, M) {
        R[i].insert(j);
        C[j].insert(i);
    }
    FOR(i, 0, N) R[i].insert(INF), R[i].insert(-INF);
    FOR(i, 0, M) C[i].insert(INF), C[i].insert(-INF);

    R[sx].erase(sy);
    C[sy].erase(sx);

    queue<pair<int, int>>ord;
    ord.push({sx, sy});
    while (!ord.empty()) {
        auto [x, y] = ord.front(); ord.pop();
        if (x == ex && y == ey)
            return D[x][y];

        // printf("\t%d %d (%d)\n", x, y, D[x][y]);

        vii nxt;
        {   // go right
            auto it = R[x].lower_bound(y);
            for (; *it <= y + K && MAT[x][*it] != '#'; ++it)
                nxt.pb({x, *it});
        }
        {   // go left
            auto it = R[x].lower_bound(y);
            --it;
            for (; *it >= y - K && MAT[x][*it] != '#'; --it)
                nxt.pb({x, *it});
        }
        {   // go down
            auto it = C[y].lower_bound(x);
            for (; *it <= x + K && MAT[*it][y] != '#'; ++it)
                nxt.pb({*it, y});
        }
        {   // go left
            auto it = C[y].lower_bound(x);
            --it;
            for (; *it >= x - K && MAT[*it][y] != '#'; --it)
                nxt.pb({*it, y});
        }

        for (auto [nx, ny] : nxt) {
            ord.push({nx, ny});
            R[nx].erase(ny);
            C[ny].erase(nx);
            D[nx][ny] = D[x][y] + 1;
        }
    }
    return -1;
}

int main() {
    riii(N, M, K);
    FOR(i, 0, N) cin >> MAT[i];
    rii(sx, sy); rii(ex, ey);
    --sx, --sy, --ex, --ey;
    printf("%d\n", bfs());
    return 0;
}