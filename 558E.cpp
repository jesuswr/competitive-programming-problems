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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM

// Todos los rangos son semi-abiertos [a,b)
int N, Q;
struct STN {
    int val;
    void merge(STN& L, STN& R) {
        val = L.val + R.val;
    }
};

struct STLZY {
    vector<STN> ST;
    vector<int> lzy;
    STLZY() {
        ST.resize(4 * N);
        lzy.resize(4 * N);
        FOR(i, 0, 4 * N) lzy[i] = -1;
    }

    // Actualiza el nodo y guarda en lazy
    void upd(int id, int l, int r, int x) {
        lzy[id] = x;
        ST[id].val = (r - l) * x;
    }
    // Propaga el update en lazy
    void shift(int id, int l, int r) {
        int m = (l + r) >> 1, L = id << 1, R = L | 1;
        upd(L, l, m, lzy[id]);
        upd(R, m, r, lzy[id]);
        lzy[id] = -1;
    }
    STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
        if (x == l && y == r) return ST[id];
        if (lzy[id] != -1) shift(id, l, r);
        int m = (l + r) >> 1, L = id << 1, R = L | 1;
        if (x >= m) return STQ(x, y, R, m, r);
        if (y <= m) return STQ(x, y, L, l, m);
        STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
        return res.merge(ln, rn), res;
    }
    void STU(int x, int y, int v = 1, int id = 1, int l = 0, int r = N) {
        if (x >= r || y <= l) return;
        if (x <= l && y >= r) {
            upd(id, l, r, v);
            return;
        }
        if (lzy[id] != -1) shift(id, l, r);
        int m = (l + r) >> 1, L = id << 1, R = L | 1;
        STU(x, y, v, L, l, m);
        STU(x, y, v, R, m, r);
        ST[id].merge(ST[L], ST[R]);
    }
};

int main() {
    rii(N, Q);
    vector<STLZY> st(26);
    string s;
    cin >> s;
    FOR(i, 0, SZ(s)) st[s[i] - 'a'].STU(i, i + 1);
    while (Q--) {
        int l, r, k; riii(l, r, k); l--;
        vector<pair<char, int>> cnt;
        for (char c = 'a'; c <= 'z'; c++) cnt.pb({c, st[c - 'a'].STQ(l, r).val});
        for (char c = 'a'; c <= 'z'; c++) st[c - 'a'].STU(l, r, 0);
        if (k == 0) reverse(ALL(cnt));
        for (auto p : cnt) {
            if (p.S == 0) continue;
            st[p.F - 'a'].STU(l, l + p.S);
            l += p.S;
        }
    }
    FOR(i, 0, N) FOR(c, 0, 26) {
        int x = st[c].STQ(i, i + 1).val;
        if (x == 1) printf("%c", c + 'a');
    }
    printf("\n");

    return 0;
}