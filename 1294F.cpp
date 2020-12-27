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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int N;
vi G[MAXN];

pii bfs(int s) {
    vector<int> dst(N, -1);
    queue<int> q;
    q.push(s);
    dst[s] = 0;

    int lst = s;
    while (!q.empty()) {
        lst = q.front(); q.pop();
        for (auto y : G[lst]) {
            if (dst[y] != -1) continue;
            dst[y] = dst[lst] + 1;
            q.push(y);
        }
    }
    return {lst, dst[lst]};
}

int IN[MAXN], OUT[MAXN], T;

void pre(int v, int f = -1) {
    IN[v] = T++;
    for (auto u : G[v]) {
        if (u == f) continue;
        pre(u, v);
    }
    OUT[v] = T;
}

pii get_max(int v, int x, int f = -1) {
    pii ret = {v, 0};
    if (v == x || f == -1)
        ret.S = -INF;
    for (auto u : G[v]) {
        if (u == f) continue;
        pii tmp;
        if (IN[u] <= IN[x] && OUT[x] <= OUT[u]) tmp = get_max(u, x, v);
        else {
            tmp = get_max(u, x, v);
            tmp.S++;
        }
        if (tmp.S > ret.S) swap(tmp, ret);
    }
    return ret;
}


int main() {
    ri(N);
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    int a = bfs(0).F;
    pii b = bfs(a);
    pre(a);
    pii c = get_max(a, b.F);
    printf("%d\n", b.S + c.S);
    printf("%d %d %d\n", a + 1, b.F + 1, c.F + 1);
    return 0;
}