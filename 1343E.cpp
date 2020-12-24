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
const int MAXN = 3e6; // CAMBIAR ESTE

// GJNM
int N, M, A, B, C;
vi G[MAXN];
int DIST[3][MAXN];
bool VIS[3][MAXN];
ll P[MAXN];

void bfs(int s, int p) {
    queue<int> q;
    q.push(s);
    VIS[p][s] = true;
    DIST[p][s] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto y : G[x]) {
            if (VIS[p][y])
                continue;
            VIS[p][y] = true; DIST[p][y] = DIST[p][x] + 1;
            q.push(y);
        }
    }
}

void solve() {
    rii(N, M), riii(A, B, C); A--, B--, C--;
    FOR(i, 0, M)
        rl(P[i+1]);
    FOR(i, 0, M) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    bfs(A, 0), bfs(B, 1), bfs(C, 2);

    sort(P, P + M+1);
    FOR(i, 1, M+1)
        P[i] += P[i-1];
    FOR(i,M+1, 5*M)
        P[i] = LLINF;
    ll ans = LLINF;
    FOR(i,0,N){
        ll maybe = 0;
        int a = DIST[0][i];
        int b = DIST[1][i];
        int c = DIST[2][i];
        maybe += P[c + a + b] + P[b];
        ans = min(ans, maybe);
    }
    printf("%lld\n", ans);

    FOR(i, 0, N) {
        G[i].clear();
        FOR(j, 0, 3)
            VIS[j][i] = false;
    }
}


int main() {
    int t; ri(t);
    while (t--)
        solve();

    return 0;
}