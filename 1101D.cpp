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
const int MAXN = 2e5 + 100; // CAMBIAR ESTE

// GJNM
int N;
vi G[MAXN];
int SMDIV[MAXN];
vi P[MAXN];

void pre() {
    FOR(i, 0, MAXN) SMDIV[i] = INF;
    FOR(i, 2, MAXN) {
        if (SMDIV[i] != INF) continue;
        int j = i;
        while (j < MAXN) {
            SMDIV[j] = min(SMDIV[j], i);
            j += i;
        }
    }
}

int ans = 0;

map<pii, int> MP;
void dfs(int x, int f = -1) {
    for (auto y : G[x]) {
        if (y == f) continue;
        dfs(y, x);
    }
    for (auto p : P[x]) {
        pii mxs = { -1, -1};
        for (auto y : G[x]) {
            if (y == f) continue;
            int h = MP[ {y, p} ];
            if (h == 0) continue;
            h++;
            if (h > mxs.F) swap(mxs.F, h);
            if (h > mxs.S) swap(mxs.S, h);
        }
        MP[ {x, p} ] = max(1, mxs.F);
        ans = max(ans, MP[ {x, p} ]);
        if (mxs.S != -1) ans = max(ans, mxs.F + mxs.S - 1);
    }
}


int main() {
    pre();
    ri(N);
    FOR(i, 0, N) {
        int a; ri(a);
        while (a > 1) {
            int aux = SMDIV[a];
            P[i].pb(aux);
            while (a % aux == 0) a /= aux;
        }
    }
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }

    dfs(0);
    printf("%d\n", ans);
    return 0;
}