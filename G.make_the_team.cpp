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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM



#define MAX 1300
#define NIL 0
#define INF (1<<28)

vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for (i = 1; i <= n; i++) {
        if (match[i] == NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        if (u != NIL) {
            len = G[u].size();
            for (i = 0; i < len; i++) {
                v = G[u][i];
                if (dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool dfs(int u) {
    int i, v, len;
    if (u != NIL) {
        len = G[u].size();
        for (i = 0; i < len; i++) {
            v = G[u][i];
            if (dist[match[v]] == dist[u] + 1) {
                if (dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while (bfs())
        for (i = 1; i <= n; i++)
            if (match[i] == NIL && dfs(i))
                matching++;
    //printf("%d\n", matching);
    return matching;
}

vi GI[1100];

void build(int hi) {
    FOR(i, 0, MAX) {
        G[i].clear();
        match[i] = dist[i] = 0;
    }
    FOR(y, 1, hi + 1) {
        for (auto x : GI[y]) {
            G[x].pb(n + y);
        }
    }
}

int main() {
    ri(n);
    FOR(i, 0, n) {
        int aux; ri(aux);
        m += aux;
        FOR(j, 0, aux) {
            int aux2; ri(aux2);
            GI[aux2].pb(i + 1);
        }
    }

    int lo = 1, hi = 1001;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        build(mi);
        if (hopcroft_karp() == n)
            hi = mi;
        else
            lo = mi + 1;
    }

    printf("%d\n", hi + 1);
    return 0;
}