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
const int MAXN = 5e4 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, M, A[MAXN], PRV[MAXN];
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
        ST[id] = PRV[l];
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

int SV[MAXN * 10];
vi Ps[MAXN];
vi CNT[MAXN * 10];
void pre() {
    FOR(i, 2, MAXN * 10) if (SV[i] == 0) {
        int j = i;
        while (j < MAXN * 10) {
            if (SV[j] == 0)
                SV[j] = i;
            j += i;
        }
    }
    FOR(i, 0, N) {
        int aux = A[i];
        while (aux > 1) {
            Ps[i].pb(SV[aux]);
            while (aux % Ps[i].back() == 0)
                aux /= Ps[i].back();
        }
        FOR(msk, 1, 1 << SZ(Ps[i])) {
            int _aux = 1;
            FOR(b, 0, SZ(Ps[i])) {
                if ((msk >> b) & 1) {
                    _aux *= Ps[i][b];
                }
            }
            CNT[_aux].pb(i);
        }
    }
}

bool valid(int l, int r) {
    int cnt = 0;
    FOR(msk, 1, 1 << SZ(Ps[r])) {
        bool bit_cnt = 0;
        int aux = 1;
        FOR(b, 0, SZ(Ps[r])) {
            if ((msk >> b) & 1) {
                bit_cnt ^= 1;
                aux *= Ps[r][b];
            }
        }
        int add = lb(ALL(CNT[aux]), r) - lb(ALL(CNT[aux]), l);
        if (bit_cnt)
            cnt += add;
        else
            cnt -= add;
    }
    // printf("%d %d : %d\n", l, r, cnt);
    return r - l > cnt;
}

int main() {
    rii(N, M);
    FOR(i, 0, N) ri(A[i]);
    pre();
    FOR(i, 0, N) {
        int lo = 0, hi = i;
        while (lo < hi) {
            int mi = lo + (hi - lo + 1) / 2;
            if (valid(mi, i))
                lo = mi;
            else
                hi = mi - 1;
        }
        if (valid(lo, i))
            PRV[i] = lo;
        else
            PRV[i] = -1;
        // printf("%d : %d\n", i, PRV[i]);
    }
    STB();
    while (M--) {
        int l, r; rii(l, r);
        int ans = STQ(l - 1, r).mx;
        if (ans >= l - 1)
            printf("S\n");
        else
            printf("N\n");
    }

    return 0;
}