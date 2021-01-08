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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N, M;
vi P[MAXN];
int R[MAXN];
vii G[MAXN];
bool VIS[MAXN];
int COL[MAXN];


bool dfs(int x) {
    VIS[x] = true;
    for (auto aux : G[x]) {
        int y = aux.F;
        int on = aux.S;
        if (!VIS[y]) {
            COL[y] = (on == 0 ? COL[x] ^ 1 : COL[x]);
            if (!dfs(y)) return false;
        }
        if (on == 1 && COL[x] != COL[y]) return false;
        if (on == 0 && COL[x] == COL[y]) return false;
    }
    return true;
}


int main() {
    rii(N, M);
    FOR(i, 0, N) ri(R[i]);
    FOR(i, 0, M) {
        int xi; ri(xi);
        while (xi--) {
            int a; ri(a);
            P[a - 1].pb(i);
        }
    }
    FOR(i, 0, N) {
        int a = P[i][0], b = P[i][1];
        G[a].pb({b, R[i]});
        G[b].pb({a, R[i]});
    }
    FOR(i, 0, M) {
        if (VIS[i]) continue;
        if (!dfs(i)) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}