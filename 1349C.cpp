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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N, M, T;
int MAT[1010][1010];
bool GOOD[1010][1010];
ll F[1010][1010];

bool valid(int r, int c) {
    return min(r, c) >= 0 && r < N && c < M;
}

void bfs() {
    queue < pii > q;
    FOR(i, 0, N) FOR(j, 0, M) {
        if (GOOD[i][j]) {
            F[i][j] = 0;
            q.push({i, j});
        }
    }

    while (!q.empty()) {
        int i = q.front().F, j = q.front().S; q.pop();
        for (auto dr : {1, -1, 0}) for (auto dc : {1, -1, 0}) {
                if (abs(dr) == abs(dc) || !valid(i + dr, j + dc)) continue;
                if (F[i][j] + 1 < F[i + dr][j + dc]) {
                    F[i + dr][j + dc] = F[i][j] + 1;
                    q.push({i + dr, j + dc});
                }
            }
    }
}

int main() {
    riii(N, M, T);
    FOR(i, 0, N) FOR(j, 0, M) dadsadasda = scanf("%1d", &MAT[i][j]);
    FOR(i, 0, N) FOR(j, 0, M) {
        F[i][j] = LLINF;
        for (auto dr : {1, -1, 0}) for (auto dc : {1, -1, 0}) {
                if (abs(dr) == abs(dc) || !valid(i + dr, j + dc)) continue;
                if (MAT[i][j] == MAT[i + dr][j + dc]) GOOD[i][j] = true;
            }
    }
    bfs();
    while (T--) {
        int i, j; ll p; rii(i, j), rl(p); i--, j--;
        if (p <= F[i][j]) printf("%d\n", MAT[i][j]);
        else {
            int changes = (p - F[i][j]) & 1ll;
            printf("%d\n", (MAT[i][j] + changes) & 1);
        }
    }

    return 0;
}