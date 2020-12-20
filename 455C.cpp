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
int n, m, q;
vi G[MAXN];

int rep[MAXN], hei[MAXN], dia[MAXN];
void makeSet() {
    FOR(i, 0, n) {
        rep[i] = -1;
        hei[i] = 1;
    }
}
int find(int x) {
    if (rep[x] == -1)
        return x;
    return rep[x] = find(rep[x]);
}
void unio(int x, int y) {
    if (hei[x] > hei[y]) {
        rep[y] = x;
        dia[x] = max({dia[x], dia[y], (dia[x] + 1) / 2 + (dia[y] + 1) / 2 + 1});
    }
    else {
        rep[x] = y;
        dia[y] = max({dia[x], dia[y], (dia[x] + 1) / 2 + (dia[y] + 1) / 2 + 1});
        if (hei[x] == hei[y])
            hei[y]++;
    }
}

int father[MAXN], dist[MAXN];
pii bfs(int s) {
    queue<int> qq;
    qq.push(s);
    dist[s] = 0; father[s] = -1;
    int x;
    while (!qq.empty()) {
        x = qq.front(); qq.pop();
        for (auto y : G[x]) {
            if (y == father[x])
                continue;
            dist[y] = dist[x] + 1;
            father[y] = x;
            qq.push(y);
        }
    }
    return {x, dist[x]};
}


int diameter(int v) {
    v = bfs(v).F;
    return bfs(v).S;
}

int main() {
    riii(n, m, q);
    makeSet();
    FOR(_, 0, m) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
        if (find(a) != find(b))
            unio(find(a), find(b));
    }
    FOR(i, 0, n) {
        if (rep[i] == -1)
            dia[i] = diameter(i);
    }
    while (q--) {
        int t; ri(t);
        if (t == 1) {
            int x; ri(x);
            printf("%d\n", dia[find(x - 1)]);
        }
        else {
            int x, y; rii(x, y); x--, y--;
            if (find(x) != find(y))
                unio(find(x), find(y));
        }
    }
    return 0;
}