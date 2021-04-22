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
#define rlll(a,b,c) rll(a,b),rl(c)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 1e9 + 10;
const ll LLINF = 1e18;
const int MAXN = 3e6 + 20; // CAMBIAR ESTE

// GJNM
struct EVENT {
    bool circle;
    bool open;
    int x, y;
    int x1, x2;
    int hi, i;

    bool operator<(EVENT &b) {
        if (y != b.y)
            return y < b.y;
        if (circle && open && b.circle && b.open)
            return x < b.x;
        if (circle && open)
            return 1;
        if (b.circle && b.open)
            return 0;
        if (!circle && !b.circle)
            return x1 < b.x1;
        if (!circle)
            return 1;
        if (!b.circle)
            return 0;
        return x < b.x;
    }
};

int N, Q;
vector<EVENT> swipe;
map<int, int> new_x;

void pre() {
    set<int> tmp;
    for (auto e : swipe) {
        if (e.circle) tmp.insert(e.x);
        else {
            tmp.insert(e.x1);
            tmp.insert(e.x2);
        }
    }
    int i = 0;
    for (auto x : tmp) new_x[x] = i++;
}

multiset<int> MXS[MAXN];

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    int mx;
    void merge(STN& L, STN& R) {
        mx = max(L.mx, R.mx);
    }
    void operator=(int a) {
        mx = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = -INF;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

bool OUT[MAXN];

int main() {
    rii(N, Q);
    FOR(i, 0, N) {
        int x, y, r; riii(x, y, r);
        EVENT aux;
        aux.circle = true, aux.open = true;
        aux.x = x; aux.y = y - r;
        aux.hi = y + r;
        swipe.pb(aux);
        aux.open = false;
        aux.y = y + r;
        swipe.pb(aux);
    }
    FOR(i, 0, Q) {
        int px, py, qx, qy, ymn, ymx; riii(px, py, qx), riii(qy, ymn, ymx);
        EVENT aux;
        aux.circle = false;
        aux.x1 = min(px, qx), aux.x2 = max(px, qx);
        aux.y = ymn, aux.hi = ymx;
        aux.i = i;
        swipe.pb(aux);
    }
    sort(ALL(swipe));
    pre();
    N = N + 2 * Q + 5;
    STB();

    for (auto e : swipe) {
        if (e.circle && e.open) {
            int x = new_x[e.x];
            MXS[x].insert(e.hi);
            int mx = *MXS[x].rbegin();
            STU(x, mx);
        }
        else if (e.circle) {
            int x = new_x[e.x];
            MXS[x].erase(MXS[x].find(e.hi));
            int mx = (!MXS[x].empty() ? *MXS[x].rbegin() : -INF);
            STU(x, mx);
        }
        else {
            int mx = STQ(new_x[e.x1], new_x[e.x2] + 1).mx;
            OUT[e.i] = mx < e.hi;
        }
    }
    FOR(i, 0, Q) {
        if (OUT[i]) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}