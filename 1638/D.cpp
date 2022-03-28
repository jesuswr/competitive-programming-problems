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
int A[MAXN][MAXN];
bool V[MAXN][MAXN];

bool good(int x, int y) {
    if (x == N - 1 || y == M - 1 || min(x, y) < 0) return false;
    vi aux;
    if (A[x][y] != 0)
        aux.pb(A[x][y]);
    if (A[x][y + 1] != 0)
        aux.pb(A[x][y + 1]);
    if (A[x + 1][y] != 0)
        aux.pb(A[x + 1][y]);
    if (A[x + 1][y + 1] != 0)
        aux.pb(A[x + 1][y + 1]);
    FOR(i, 1, SZ(aux)) if (aux[i] != aux[i - 1]) return false;
    return !aux.empty();
}

void solve() {
    rii(N, M);
    FOR(i, 0, N) FOR(j, 0, M) ri(A[i][j]);
    vector < tuple<int, int, int> > ans;
    queue<pii> q;
    FOR(i, 0, N - 1) FOR(j, 0, M - 1) if (good(i, j)) {
        q.push({i, j});
        V[i][j] = 1;
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (good(x, y)) {
            ans.pb({x + 1, y + 1, max({A[x][y] , A[x + 1][y] , A[x][y + 1] , A[x + 1][y + 1]}) });
            A[x][y] = A[x + 1][y] = A[x][y + 1] = A[x + 1][y + 1] = 0;
        }
        for (auto dx : {1, 0, -1}) for (auto dy : {1, 0, -1})
                if (good(x + dx, y + dy) && !V[x + dx][y + dy]) {
                    V[x + dx][y + dy] = 1;
                    q.push({x + dx, y + dy});
                }
    }


    FOR(i, 0, N) FOR(j, 0, M) if (A[i][j]) {
        printf("-1\n");
        return;
    }
    printf("%d\n", SZ(ans));
    reverse(ALL(ans));
    for (auto [x, y, k] : ans) printf("%d %d %d\n", x, y, k);
}


int main() {
    solve();
    return 0;
}