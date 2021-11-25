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
const int MAXN = (1 << 18) + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct SEG_TREE {
    struct STN {
        ll val;
        void merge(STN& L, STN& R) {
            val = min(L.val, R.val);
        }
        void operator=(ll a) {
            val = a;
        }
    };
    vector<STN> ST;
    SEG_TREE() {
        ST.resize(4 * MAXN);
        STB();
    }
    void STB(int id = 1, int l = 0, int r = N) {
        if (r - l < 2) {
            ST[id] = LLINF;
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
    void STU(int p, ll x, int id = 1, int l = 0, int r = N) {
        if (r - l < 2) {
            ST[id] = x;
            return;
        }
        int m = (l + r) >> 1, L = id << 1, R = L | 1;
        if (p < m) STU(p, x, L, l, m);
        else STU(p, x, R, m, r);
        ST[id].merge(ST[L], ST[R]);
    }
};
int _f(int n) {
    int ret = 0;
    while (n > 1) {
        ret++;
        n >>= 1;
    }
    return ret;
}
vi _f2(int dst, int p2) {
    int sm = 0;
    vi ret;
    while (sm < dst) {
        sm += (1 << p2);
        ret.pb(p2);
        --p2;
    }
    reverse(ALL(ret));
    return ret;
}
int _g(vi &ps, int p) {
    int ret = 0;
    FOR(i, p, SZ(ps)) {
        ret += (1 << ps[i]);
    }
    return ret;
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    int ind = 0;
    FOR(i, 0, N) if (A[i] == -1)
        ind = i;
    int p2 = _f(N);
    if (ind + 1 == N) {
        printf("0\n");
        return 0;
    }
    vi ps = _f2(N - (ind + 1), p2 - 1);
    vector<SEG_TREE> ST(p2);

    for (int i = ind + 1; i < N; ++i) {
        for (int p = 0; p < SZ(ps); ++p) {
            if (p == 0)
                ST[p].STU(i, A[i]);
            else if (max(ind + 1, N - _g(ps, p)) < i + 1) {
                ll cst = A[i] + ST[p - 1].STQ(max(ind + 1, N - _g(ps, p) - 1), i).val;
                ST[p].STU(i, cst);
            }
            // printf("%d %d : %d\n", i, p, _g(ps, p));
        }
    }

    // for (int i = ind + 1; i < N; ++i) {
    //     for (int p = 1; p < p2; ++p) {
    //         ll cst = A[i] + ST[p - 1].STQ(max(ind, i - (1 << p)), i).val;
    //         printf("%d %d (%d, %d) : %lld\n", i, p, max(ind, i - (1 << p)), i, ST[p - 1].STQ(max(ind, i - (1 << p)), i).val);
    //         ST[p].STU(i, cst);
    //     }
    // }
    printf("%lld\n", ST[SZ(ps) - 1].STQ(N - 1, N).val);
    return 0;
}