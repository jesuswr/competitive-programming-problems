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
const int MAXN = 3e3 + 10; // CAMBIAR ESTE

// GJNM
int N, M;
vi G[MAXN];
int S[2], T[2], L[2];
int D[MAXN][MAXN];

void dfs(int s) {
    FOR(i, 0, N) D[s][i] = INF;
    D[s][s] = 0;
    queue<int> ord; ord.push(s);
    while (!ord.empty()) {
        int x = ord.front(); ord.pop();
        for (auto y : G[x]) {
            if (D[s][y] > D[s][x] + 1) {
                ord.push(y);
                D[s][y] = D[s][x] + 1;
            }
        }
    }
}

int main() {
    rii(N, M);
    FOR(_, 0, M) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    FOR(i, 0, N) dfs(i);
    FOR(i, 0, 2) {
        riii(S[i], T[i], L[i]);
        --S[i], --T[i];
    }

    int ans = INF;
    {
        int x = D[S[0]][T[0]];
        int y = D[S[1]][T[1]];
        if (x <= L[0] && y <= L[1]) ans = min(ans, max(0, M - x - y));
    }

    FOR(x, 0, N) FOR(y, x, N) {
        int X = D[S[0]][x] + D[x][y] + D[y][T[0]];
        int Y = D[S[1]][x] + D[x][y] + D[y][T[1]];
        if (X <= L[0] && Y <= L[1]) {
            X -= D[x][y];
            ans = max(ans, max(0, M - X - Y));
        }
    }
    swap(S[1], T[1]);
    FOR(x, 0, N) FOR(y, x, N) {
        int X = D[S[0]][x] + D[x][y] + D[y][T[0]];
        int Y = D[S[1]][x] + D[x][y] + D[y][T[1]];
        if (X <= L[0] && Y <= L[1]) {
            X -= D[x][y];
            ans = max(ans, max(0, M - X - Y));
        }
    }
    swap(S[0], T[0]);
    FOR(x, 0, N) FOR(y, x, N) {
        int X = D[S[0]][x] + D[x][y] + D[y][T[0]];
        int Y = D[S[1]][x] + D[x][y] + D[y][T[1]];
        if (X <= L[0] && Y <= L[1]) {
            X -= D[x][y];
            ans = max(ans, max(0, M - X - Y));
        }
    }
    swap(S[1], T[1]);
    FOR(x, 0, N) FOR(y, x, N) {
        int X = D[S[0]][x] + D[x][y] + D[y][T[0]];
        int Y = D[S[1]][x] + D[x][y] + D[y][T[1]];
        if (X <= L[0] && Y <= L[1]) {
            X -= D[x][y];
            ans = max(ans, max(0, M - X - Y));
        }
    }

    printf("%d\n", (ans == INF ? -1 : ans));
    return 0;
}