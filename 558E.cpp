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
// Todos los rangos son semi-abiertos [a,b)
int N;
char A[MAXN];
struct STN {
    int cnt[30];
    void merge(STN& L, STN& R) {
        FOR(i, 0, 30) cnt[i] = L.cnt[i] + R.cnt[i];
    }
    void operator=(int a) {
        FOR(i, 0, 30) cnt[i] = i == a;
    }
};
STN ST[4 * MAXN];
vii lzy[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = A[l] - 'a';
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
void shift(int id, int l, int r);
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, vii &x) {
    shift(id, l, r);
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
    if (lzy[id].empty()) return;
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    int need = m - l;
    vii aux1, aux2;
    for (auto p : lzy[id]) {
        if (p.S == 0) continue;
        if (need > 0) {
            int aux = min(need, p.S);
            need -= aux;
            p.S -= aux;
            aux1.pb({p.F, aux});
        }
    }
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    lzy[id].clear();
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int x, int y, vii &v, int id = 1, int l = 0, int r = N) {
    if (x >= r || y <= l) return;
    if (x <= l && y >= r) {
        upd(id, l, r, v);
        return;
    }
    shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int main() {
    ri(N);
    scanf("%s", A);
    return 0;
}