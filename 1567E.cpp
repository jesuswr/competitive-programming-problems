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
#include <random>
#include <chrono>

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
const int MAXN = 2e5 + 1; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, Q, A[MAXN];
struct STN {
    int lft, rgt, fst, lst, l, r;
    ll cnt;
    void merge(STN& L, STN& R) {
        cnt = L.cnt + R.cnt;
        lft = L.lft;
        rgt = R.rgt;
        l = L.l;
        r = R.r;
        if (L.rgt <= R.lft) {
            if (L.lst == -1 && R.fst == -1)
                cnt += 1ll * (L.r - L.l + 1) * (R.r - R.l + 1);
            else if (L.lst == -1)
                cnt += 1ll * (L.r - L.l + 1) * (R.fst - R.l + 1);
            else if (R.lst == -1)
                cnt += 1ll * (L.r - L.lst + 1) * (R.r - R.l + 1);
            else
                cnt += 1ll * (L.r - L.lst + 1) * (R.fst - R.l + 1);
        }

        if (L.fst != -1)
            fst = L.fst;
        else if (L.rgt > R.lft)
            fst = L.r;
        else if (R.fst != -1)
            fst = R.fst;
        else
            fst = -1;

        if (R.lst != -1)
            lst = R.lst;
        else if (L.rgt > R.lft)
            lst = R.l;
        else if (L.lst != -1)
            lst = L.lst;
        else
            lst = -1;
        // printf("l = %d, r = %d, lft = %d, rgt = %d, cnt = %d, fst = %d, lst = %d: \n", l, r, lft, rgt, cnt, fst, lst);
    }
    void operator=(pii a) {
        cnt = 1;
        lft = rgt = a.F;
        fst = lst = -1;
        l = r = a.S;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = make_pair(A[l], l);
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
        ST[id] = make_pair(x, l);
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int main() {
    rii(N, Q);
    FOR(i, 0, N) ri(A[i]);
    STB();
    while (Q--) {
        // printf("QUERY\n");
        int t; ri(t);
        if (t == 1) {
            int i, ai; rii(i, ai);
            STU(i - 1, ai);
        }
        else {
            int l, r; rii(l, r);
            printf("%lld\n", STQ(l - 1, r).cnt);
        }
    }

    return 0;
}