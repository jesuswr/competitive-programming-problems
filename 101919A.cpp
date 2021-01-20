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
const int MAXN = 1010; // CAMBIAR ESTE

// GJNM
struct ALGO {
    int x, y, t;
};

int N, M;
pii START, END;
char MAT[MAXN][MAXN];
int D[MAXN][MAXN][3]; // 0 is . 1 is | 2 is --
bool VIS[MAXN][MAXN][3];
char MOVE[MAXN][MAXN][3];
ALGO PREV[MAXN][MAXN][3];

bool valid(int x, int y) {
    return min(x, y) >= 0 && x < N && y < M && MAT[x][y] != '#';
}

void bfs() {
    queue< ALGO > q;
    q.push({START.F, START.S, 0});
    VIS[START.F][START.S][0] = true;
    while (!q.empty()) {
        auto act = q.front(); q.pop();
        int x = act.x, y = act.y, t = act.t;
        int d = D[x][y][t];
        if (t == 0) {
            if (valid(x - 2, y) && valid(x - 1, y) && !VIS[x - 2][y][1]) { // up
                VIS[x - 2][y][1] = true;
                D[x - 2][y][1] = d + 1;
                PREV[x - 2][y][1] = act;
                MOVE[x - 2][y][1] = 'U';
                q.push({x - 2, y, 1});
            }
            if (valid(x + 2, y) && valid(x + 1, y) && !VIS[x + 1][y][1]) { // down
                VIS[x + 1][y][1] = true;
                D[x + 1][y][1] = d + 1;
                PREV[x + 1][y][1] = act;
                MOVE[x + 1][y][1] = 'D';
                q.push({x + 1, y, 1});
            }
            if (valid(x, y - 2) && valid(x, y - 1) && !VIS[x][y - 2][2]) { // left
                VIS[x][y - 2][2] = true;
                D[x][y - 2][2] = d + 1;
                PREV[x][y - 2][2] = act;
                MOVE[x][y - 2][2] = 'L';
                q.push({x, y - 2, 2});
            }
            if (valid(x, y + 2) && valid(x, y + 1) && !VIS[x][y + 1][2]) { // right
                VIS[x][y + 1][2] = true;
                D[x][y + 1][2] = d + 1;
                PREV[x][y + 1][2] = act;
                MOVE[x][y + 1][2] = 'R';
                q.push({x, y + 1, 2});
            }
        }

        if (t == 1) {
            if (valid(x - 1, y) && !VIS[x - 1][y][0]) { // up
                VIS[x - 1][y][0] = true;
                D[x - 1][y][0] = d + 1;
                PREV[x - 1][y][0] = act;
                MOVE[x - 1][y][0] = 'U';
                q.push({x - 1, y, 0});
            }
            if (valid(x + 2, y) && !VIS[x + 2][y][0]) { // down
                VIS[x + 2][y][0] = true;
                D[x + 2][y][0] = d + 1;
                PREV[x + 2][y][0] = act;
                MOVE[x + 2][y][0] = 'D';
                q.push({x + 2, y, 0});
            }
            if (valid(x, y - 1) && valid(x + 1, y - 1) && !VIS[x][y - 1][1]) { // left
                VIS[x][y - 1][1] = true;
                D[x][y - 1][1] = d + 1;
                PREV[x][y - 1][1] = act;
                MOVE[x][y - 1][1] = 'L';
                q.push({x, y - 1, 1});
            }
            if (valid(x, y + 1) && valid(x + 1, y + 1) && !VIS[x][y + 1][1]) { // right
                VIS[x][y + 1][1] = true;
                D[x][y + 1][1] = d + 1;
                PREV[x][y + 1][1] = act;
                MOVE[x][y + 1][1] = 'R';
                q.push({x, y + 1, 1});
            }
        }

        if (t == 2) {
            if (valid(x - 1, y) && valid(x - 1, y + 1) && !VIS[x - 1][y][2]) { // up
                VIS[x - 1][y][2] = true;
                D[x - 1][y][2] = d + 1;
                PREV[x - 1][y][2] = act;
                MOVE[x - 1][y][2] = 'U';
                q.push({x - 1, y, 2});
            }
            if (valid(x + 1, y) && valid(x + 1, y + 1) && !VIS[x + 1][y][2]) { // down
                VIS[x + 1][y][2] = true;
                D[x + 1][y][2] = d + 1;
                PREV[x + 1][y][2] = act;
                MOVE[x + 1][y][2] = 'D';
                q.push({x + 1, y, 2});
            }
            if (valid(x, y - 1) && !VIS[x][y - 1][0]) { // l
                VIS[x][y - 1][0] = true;
                D[x][y - 1][0] = d + 1;
                PREV[x][y - 1][0] = act;
                MOVE[x][y - 1][0] = 'L';
                q.push({x, y - 1, 0});
            }
            if (valid(x, y + 2) && !VIS[x][y + 2][0]) { // r
                VIS[x][y + 2][0] = true;
                D[x][y + 2][0] = d + 1;
                PREV[x][y + 2][0] = act;
                MOVE[x][y + 2][0] = 'R';
                q.push({x, y + 2, 0});
            }
        }
    }
}

int main() {
    rii(N, M);
    FOR(i, 0, N) dadsadasda = scanf("%s", MAT[i]);
    FOR(i, 0, N) FOR(j, 0, M) {
        if (MAT[i][j] == 'C') START = {i, j};
        if (MAT[i][j] == 'E') END = {i, j};
    }
    bfs();
    if (!VIS[END.F][END.S][0]) {
        printf("-1\n");
        return 0;
    }
    printf("%d \n", D[END.F][END.S][0]);
    ALGO curr = {END.F, END.S, 0};
    string help;
    while (curr.x != START.F || curr.y != START.S || curr.t != 0) {
        help.pb(MOVE[curr.x][curr.y][curr.t]);
        curr = PREV[curr.x][curr.y][curr.t];
    }
    reverse(ALL(help));
    cout << help << endl;
    return 0;
}