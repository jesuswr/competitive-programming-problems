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
const int MAXN = 510; // CAMBIAR ESTE

// GJNM
int R, C;
int M[MAXN][MAXN];
bool VIS[MAXN][MAXN];
priority_queue< pair<int, pair<int, int>>> pq;

bool valid(int r, int c) {
    return min(r, c) >= 0 && r < R && c < C && !VIS[r][c];
}

void dfs(int r, int c) {
    VIS[r][c] = true;
    for (int dr : {1, 0, -1}) for (int dc : {1, 0, -1}) {
            if (abs(dr) == abs(dc)) continue;
            if (valid(r + dr, c + dc) && M[r][c] >= M[r + dr][c + dc])
                dfs(r + dr, c + dc);
        }
}

int main() {
    rii(R, C);
    FOR(i, 0, R) FOR(j, 0, C) ri(M[i][j]);
    FOR(i, 0, R) FOR(j, 0, C) M[i][j] = max(0, M[i][j] - 1);
    FOR(i, 0, R) FOR(j, 0, C) pq.push({M[i][j], {i, j}});
    int cnt = 0;
    while (!pq.empty()) {
        int r = pq.top().S.F;
        int c = pq.top().S.S;
        pq.pop();
        if (!VIS[r][c] && M[r][c] > 0) {
            ++cnt;
            dfs(r, c);
        }
    }
    printf("%d\n", cnt);
    return 0;
}