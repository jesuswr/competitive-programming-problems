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
const int MAXN = 2010; // CAMBIAR ESTE

// GJNM
int N, M;
char MAT[MAXN][MAXN];
int D[MAXN][MAXN];
vii moves = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};

bool valid(int n, int m) {
    return min(n, m) >= 0 && n < N && m < M;
}

int main() {
    rii(N, M);
    FOR(i, 0, N) FOR(j, 0, M) D[i][j] = INF;
    FOR(i, 0, N) dadsadasda = scanf("%s", MAT[i]);

    queue<pii> bfs;
    FOR(i, 0, N) FOR(j, 0, M) {
        bool edge = false;
        for (auto m : moves) {
            if (min(i, j) == 0 || i == N - 1 || j == M - 1) edge = true;
            if (!valid(i + m.F, j + m.S)) continue;
            if (MAT[i][j] != MAT[i + m.F][j + m.S]) edge = true;
        }

        if (edge) {
            bfs.push({i, j});
            D[i][j] = 0;
        }
    }

    while (!bfs.empty()) {
        int x = bfs.front().F, y = bfs.front().S; bfs.pop();
        for (auto m : moves) {
            if (valid(x + m.F, y + m.S) && D[x + m.F][y + m.S] > D[x][y] + 1) {
                D[x + m.F][y + m.S] = D[x][y] + 1;
                bfs.push({x + m.F, y + m.S});
            }
        }
    }
    ll ans = 0;
    FOR(i, 0, N) FOR(j, 0, M) ans += D[i][j] + 1;
    //FOR(i, 0, N) {
    //    FOR(j, 0, M) printf("%d ", D[i][j]);
    //    printf("\n");
    //}
    printf("%lld\n", ans);

    return 0;
}