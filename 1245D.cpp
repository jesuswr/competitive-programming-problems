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
const int MAXN = 2000; // CAMBIAR ESTE

// GJNM
int n;
int x[MAXN], y[MAXN], c[MAXN], k[MAXN];

int father[MAXN], siz[MAXN];
bool good[MAXN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int nn, int m) {
    for (int i = nn; i <= m; ++i) {
        father[i] = -1;
        siz[i] = 0;
    }
}
int find(int xx) {
    if (father[xx] == -1) // -1 significa que es el representante del set
        return xx;
    return father[xx] = find(father[xx]);
}
void unio(int xx, int yy) { // x y y tienen que ser los representantes
    if (siz[xx] > siz[yy]) {
        father[yy] = xx;
        good[xx] |= good[yy];
    }
    else {
        father[xx] = yy;
        if ( siz[xx] == siz[yy] ) siz[yy]++;
        good[yy] |= good[xx];
    }
}
void make_good(int xx) {
    good[find(xx)] = true;
}
bool is_good(int xx) {
    return good[find(xx)];
}


int dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

struct EVENT {
    bool is_edge;
    int from, to;
    int p;
    ll cst;

    bool operator<(const EVENT &other) {
        return cst < other.cst;
    }
};

int main() {
    ri(n);
    FOR(i, 0, n) rii(x[i], y[i]);
    FOR(i, 0, n) ri(c[i]);
    FOR(i, 0, n) ri(k[i]);

    vector<EVENT> actions;
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            EVENT tmp;
            tmp.is_edge = true;
            tmp.from = i;
            tmp.to = j;
            tmp.cst = 1ll * dist(i, j) * (k[i] + k[j]);
            actions.pb(tmp);
        }
        EVENT tmp;
        tmp.is_edge = false;
        tmp.p = i;
        tmp.cst = c[i];
        actions.pb(tmp);
    }
    sort(ALL(actions));
    makeSet(0, n - 1);

    ll ans = 0;
    vii edges;
    vi goods;
    int comp = n, cnt = 0;
    for (auto act : actions) {
        if (comp == cnt)
            break;
        if (act.is_edge) {
            int a = act.from, b = act.to;
            if (find(a) == find(b) || (is_good(a) && is_good(b)))
                continue;
            unio(find(a), find(b));
            edges.pb({a, b});
            ans += act.cst;
            comp--;
        }
        else {
            int a = act.p;
            if (is_good(a))
                continue;
            make_good(a);
            goods.pb(a);
            ans += act.cst;
            cnt++;
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", SZ(goods));
    for (auto p : goods)
        printf("%d ", p + 1);
    printf("\n");
    printf("%d\n", SZ(edges));
    for (auto p : edges)
        printf("%d %d\n", p.F + 1, p.S + 1);
    return 0;
}