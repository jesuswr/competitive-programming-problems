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
const int MAXN = 1010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
string A[MAXN];
bool VIS[MAXN][MAXN];
int SZ[MAXN][MAXN];
pii F[MAXN][MAXN];

bool valid(int x, int y) {
    return min(x, y) >= 0 && x < N && y < M && !VIS[x][y] && A[x][y] == '.';
}

int dfs(int x, int y, int fx, int fy) {
    F[x][y] = {fx, fy};
    VIS[x][y] = 1;
    int sz = 1;
    for (auto dx : {1, 0, -1}) for (auto dy : {1, 0, -1}) if (abs(dx) != abs(dy)) {
                if (valid(x + dx, y + dy))
                    sz += dfs(x + dx, y + dy, fx, fy);
            }
    return SZ[x][y] = sz;
}

void solve() {
    rii(M, N);
    FOR(i, 0, N) cin >> A[i];
    FOR(i, 0, N) FOR(j, 0, M) VIS[i][j] = 0;

    FOR(i, 0, N) FOR(j, 0, M) if (!VIS[i][j] && A[i][j] == '.') {
        dfs(i, j, i, j);
    }

    int q; ri(q);
    while (q--) {
        int x, y; rii(x, y);
        --x, --y;
        printf("%d\n", SZ[ F[x][y].F ][ F[x][y].S ]);
    }
}



int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case %d:\n", i);
        solve();
    }
    return 0;
}