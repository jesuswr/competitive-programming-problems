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
const int MAXN = 5010; // CAMBIAR ESTE

// GJNM
struct EDGE {
    int to, ind;
};
int n, m;
int k = 1;
vector<EDGE> G[MAXN];
int VIS[MAXN];
int ans[MAXN];

void dfs(int x) {
    VIS[x] = 1;
    for (auto e : G[x]) {
        int y = e.to;
        int i = e.ind;
        if (VIS[y] == 0)
            dfs(y), ans[i] = 1;
        else if (VIS[y] == 2)
            ans[i] = 1;
        else {
            k = 2;
            ans[i] = 2;
        }
    }
    VIS[x] = 2;
}

int main() {
    rii(n, m);
    FOR(i, 0, m) {
        int f, t; rii(f, t); f--, t--;
        G[f].pb({t, i});
    }
    FOR(i, 0, n) {
        if (VIS[i] == 0)
            dfs(i);
    }
    printf("%d\n", k);
    FOR(i,0,m) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}