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

const int INF = 1e8;
const ll LLINF = 1e18;
const int MAXN = 1010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int R, C;
char A[MAXN][MAXN];

bool valid(int x, int y) {
    return min(x, y) >= 0 && x < R && y < C && A[x][y] != '#' && A[x][y] != 'X';
}

int DST[MAXN][MAXN];
void bfs(int x, int y) {
    FOR(i, 0, R) FOR(j, 0, C) DST[i][j] = INF;
    queue<pii> q; q.push({x, y});
    DST[x][y] = 0;
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        for (auto da : {1, 0, -1}) for (auto db : {1, 0, -1}) if (abs(da) != abs(db)) {
                    int na = a + da, nb = b + db;
                    if (valid(na, nb) && DST[na][nb] > DST[a][b] + 1) {
                        DST[na][nb] = DST[a][b] + 1;
                        q.push({na, nb});
                    }
                }
    }

}

int main() {
    rii(R, C);
    FOR(i, 0, R) dadsadasda = scanf("%s\n", A[i]);
    FOR(i, 0, R) FOR(j, 0, C) if (A[i][j] == 'E') bfs(i, j);
    int q; ri(q);
    while (q--) {
        int x, y; rii(x, y);
        --x, --y;
        if (A[x][y] == '#') printf("W\n");
        else if (A[x][y] == 'X') printf("X\n");
        else if (A[x][y] == 'E') printf("E\n");
        else if (DST[x][y] == INF) printf("?\n");
        else {
            if (valid(x, y - 1) && DST[x][y - 1] < DST[x][y]) printf("L\n");
            else if (valid(x + 1, y) && DST[x + 1][y] < DST[x][y]) printf("D\n");
            else if (valid(x, y + 1) && DST[x][y + 1] < DST[x][y]) printf("R\n");
            else printf("U\n");
        }
    }
    return 0;
}