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
const int MAXN = 1e3 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int X[MAXN][MAXN], Y[MAXN][MAXN];
char ANS[MAXN][MAXN];
bool V[MAXN][MAXN];
vector<tuple<int, int, char, char>> D = {{1, 0, 'U', 'D'}, { -1, 0, 'D', 'U'}, {0, 1, 'L', 'R'}, {0, -1, 'R', 'L'}};

int NO() {
    printf("INVALID\n");
    exit(0);
    return 69;
}

bool valid(int x, int y) {
    return min(x, y) >= 0 && max(x, y) < N;
}

void bfs() {
    queue<pii> ord;
    FOR(i, 0, N) FOR(j, 0, N) if (X[i][j] == i && Y[i][j] == j) {
        ord.push({i, j});
        V[i][j] = 1;
        ANS[i][j] = 'X';
    }
    while (!ord.empty()) {
        auto [x, y] = ord.front(); ord.pop();
        for (auto [dx, dy, c, _] : D) {
            int new_x = x + dx, new_y = y + dy;
            if (!valid(new_x, new_y) || X[new_x][new_y] != X[x][y] || Y[new_x][new_y] != Y[x][y] || V[new_x][new_y])
                continue;
            ANS[new_x][new_y] = c;
            V[new_x][new_y] = 1;
            ord.push({new_x, new_y});
        }
    }
    FOR(i, 0, N) FOR(j, 0, N) if (!V[i][j] && X[i][j] != -2)
        NO();
    FOR(x, 0, N) FOR(y, 0, N) if (!V[x][y]) {
        for (auto [dx, dy, rc, c] : D) {
            int new_x = x + dx, new_y = y + dy;
            if (!valid(new_x, new_y))
                continue;
            if (!V[new_x][new_y]) {
                V[x][y] = V[new_x][new_y] = true;
                ANS[x][y] = c;
                ANS[new_x][new_y] = rc;
                break;
            }
            else if (X[new_x][new_y] == -2) {
                V[x][y] = true;
                ANS[x][y] = c;
                break;
            }
        }
        if (!V[x][y])
            NO();
    }
    printf("VALID\n");
    FOR(i, 0, N) {
        FOR(j, 0, N) printf("%c", ANS[i][j]);
        printf("\n");
    }
}


int main() {
    ri(N);
    FOR(i, 0, N) FOR(j, 0, N) rii(X[i][j], Y[i][j]), --X[i][j], --Y[i][j], ANS[i][j] = '?';
    bfs();

    return 0;
}