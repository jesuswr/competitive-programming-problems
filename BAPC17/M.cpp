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
#include <array>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const int MAXXY = 1e9 + 10;

// GJNM
struct PT {
    int x, y;
    bool start, end;

    bool operator<(PT b) {
        if (y != b.y)
            return y > b.y;
        if (x != b.x)
            return x > b.x;
        if (end)
            return true;
        if (b.end)
            return false;
        if (start)
            return false;
        if (b.start)
            return true;
        return false;
    }
};

int N;
vector<PT> P;
void compress() {
    set<int> coords;
    FOR(i, 0, N) {
        coords.insert(P[i].x);
        coords.insert(P[i].y);
    }
    map<int, int> new_c;
    int k = 0;
    for (auto c : coords) new_c[c] = k++;
    FOR(i, 0, N) {
        P[i].x = new_c[P[i].x];
        P[i].y = new_c[P[i].y];
    }
}

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    int mx;
    void merge(STN& L, STN& R) {
        mx = max(L.mx, R.mx);
    }
    void operator=(int a) {
        mx = max(mx, a);
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = MAXN) {
    if (r - l < 2) {
        ST[id] = -2 * MAXN;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = MAXN) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int x, int id = 1, int l = 0, int r = MAXN) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

PT aux, aux2;
PT START, END;
int main() {
    ri(N);
    rii(aux.x, aux.y);
    rii(aux2.x, aux2.y);
    aux.start = true; aux2.end = true;
    P.pb(aux); P.pb(aux2);
    aux.start = false; aux2.end = false;
    FOR(i, 0, N) {
        rii(aux.x, aux.y);
        P.pb(aux);
    }
    N += 2;
    if (P[0].x > P[1].x)
        FOR(i, 0, N) P[i].x = MAXXY - P[i].x;
    if (P[0].y > P[1].y)
        FOR(i, 0, N) P[i].y = MAXXY - P[i].y;
    compress();
    START.x = P[0].x; START.y = P[0].y;
    END.x = P[1].x; END.y = P[1].y;
    sort(ALL(P));

    STB();
    for (auto p : P) {
        if (p.x < START.x || p.x > END.x || p.y < START.y || p.y > END.y)
            continue;
        if (p.start) {
            printf("%d\n", STQ(p.x, END.x + 1).mx);
            break;
        }
        if (p.end) {
            STU(p.x, 0);
        }
        else {
            int mx = STQ(p.x, END.x + 1).mx;
            STU(p.x, mx + 1);
        }
    }

    return 0;
}