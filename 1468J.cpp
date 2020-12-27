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
struct EDGE {
    int x, y;
    ll s;
    bool operator<(EDGE other) {
        return s < other.s;
    }
};

int father[MAXN], siz[MAXN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m) {
    for (int i = n; i <= m; ++i) {
        father[i] = -1;
        siz[i] = 0;
    }
}
int find(int x) {
    if (father[x] == -1) // -1 significa que es el representante del set
        return x;
    return father[x] = find(father[x]);
}
void unio(int x, int y) { // x y y tienen que ser los representantes
    if (siz[x] > siz[y])
        father[y] = x;
    else {
        father[x] = y;
        if ( siz[x] == siz[y] ) siz[y]++;
    }
}



void solve() {
    int n, m, k; riii(n, m, k);
    vector<EDGE> less, more;
    FOR(_, 0, m) {
        int x, y, s; riii(x, y, s);
        EDGE tmp = {x - 1, y - 1, s};
        if (s <= k) less.pb(tmp);
        else more.pb(tmp);
    }
    makeSet(0, n - 1);
    more.pb({0, 0, LLINF});
    int cn = n;
    ll mx = -LLINF;
    for (auto e : less) {
        mx = max(mx, e.s);
        if (find(e.x) != find(e.y)) {
            unio(find(e.x), find(e.y));
            cn--;
        }
    }

    sort(ALL(more));

    if (cn == 1) {
        ll mn = more[0].s;
        printf("%lld\n", min(k - mx, mn - k));
    }
    else {
        ll cst = 0;
        for (auto e : more) {
            if (find(e.x) != find(e.y)) {
                unio(find(e.x), find(e.y));
                cn--;
                cst += e.s - k;
            }
        }
        printf("%lld\n", cst);
    }
}


int main() {
    int t; ri(t);
    while (t--)
        solve();

    return 0;
}