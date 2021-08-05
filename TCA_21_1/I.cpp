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
const int MAXN = 1e3 + 10; // CAMBIAR ESTE

// GJNM
int N, M;
string MAT[MAXN];
vii MOVES = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};


bool valid(int i, int j) {
    return min(i, j) >= 0 && i <= N && j <= M && MAT[i][j] != '*';
}

pii START, END;

int D[MAXN][MAXN][4];
bool VIS[MAXN][MAXN][4];

void bfs01() {
    deque<tuple<int, int, int>> dq;
    FOR(i, 0, N) FOR(j, 0, M) FOR(d, 0, 4) D[i][j][d] = INF;
    FOR(i, 0, 4) {
        dq.push_back({START.F, START.S, i});
        D[START.F][START.S][i] = 0;
    }

    while (!dq.empty()) {
        auto [x, y, d] = dq.front(); dq.pop_front();
        if (D[x][y][d] > 2)
            break;

        if (x == END.F && y == END.S)
            break;
        if (VIS[x][y][d])
            continue;
        VIS[x][y][d] = true;

        int new_x = x + MOVES[d].F, new_y = y + MOVES[d].S;
        if (valid(new_x, new_y) && D[new_x][new_y][d] > D[x][y][d]) {
            D[new_x][new_y][d] = D[x][y][d];
            dq.push_front({new_x, new_y, d});
        }

        if (D[x][y][(d + 1) % 4] > D[x][y][d] + 1) {
            D[x][y][(d + 1) % 4] = D[x][y][d] + 1;
            dq.push_back({x, y, (d + 1) % 4});
        }
        if (D[x][y][(d + 3) % 4] > D[x][y][d] + 1) {
            D[x][y][(d + 3) % 4] = D[x][y][d] + 1;
            dq.push_back({x, y, (d + 3) % 4});
        }
    }
}

int main() {
    rii(N, M);
    FOR(i, 0, N) cin >> MAT[i];

    FOR(i, 0, N) FOR(j, 0, M) {
        if (MAT[i][j] == 'S') START = {i, j};
        if (MAT[i][j] == 'T') END = {i, j};
    }

    bfs01();

    bool good = false;
    FOR(i, 0, 4) good |= (D[END.F][END.S][i] <= 2);

    if (good)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}