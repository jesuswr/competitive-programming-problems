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
const int MAXN = 5e5 + 10; // CAMBIAR ESTE

// GJNM
int N, Q;
// Todos los rangos son semi-abiertos [a,b)
int A[MAXN];
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
        ST[id] = A[l];
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

void comp() {
    int B[MAXN];
    FOR(i, 0, N) B[i] = A[i];
    sort(B, B + N);
    map<int, int> new_a;
    FOR(i, 0, N) new_a[B[i]] = i;
    FOR(i, 0, N) A[i] = new_a[A[i]];
}


int PREV[MAXN], NEXT[MAXN];
int LST[MAXN];

void pre() {
    FOR(i, 0, N) LST[i] = -1;

    for (int i = 0; i < N; ++i) {
        if (LST[A[i]] != -1) {
            if (STQ(LST[A[i]], i + 1).mx <= A[i])
                PREV[i] = LST[A[i]];
            else
                PREV[i] = -1;
        }
        else
            PREV[i] = -1;
        LST[A[i]] = i;
    }

    FOR(i, 0, N) LST[i] = -1;

    for (int i = N - 1; i >= 0; --i) {
        if (LST[A[i]] != -1) {
            if (STQ(i, LST[A[i]] + 1).mx <= A[i])
                NEXT[i] = LST[A[i]];
            else
                NEXT[i] = -1;
        }
        else
            NEXT[i] = -1;
        LST[A[i]] = i;

    }
}

struct query {
    int l, r, i;

    bool operator<(query b) {
        int block = l / 600, r_block = b.l / 600;
        return make_pair(block, (block & 1 ? -r : r)) < make_pair(r_block, (r_block & 1 ? -b.r : b.r));
    }
};

query Qs[MAXN];

int ANS[MAXN];
int LL[MAXN], LR[MAXN], OC[610 * 910], OCSQ[MAXN];

void upd(int i, int c) {
    OC[i] += c;
    OCSQ[i / 600] += c;
}

int main() {
    rii(N, Q);
    FOR(i, 0, N) ri(A[i]);
    comp();
    STB();
    pre();


    FOR(i, 0, Q) {
        rii(Qs[i].l, Qs[i].r);
        Qs[i].l--;
        Qs[i].r--;
        Qs[i].i = i;
    }
    sort(Qs, Qs + Q);

    FOR(i, 0, N) LL[i] = LR[i] = i;

    int l = 0, r = 0;
    FOR(i, 0, Q) {
        while (l > Qs[i].l) {
            --l;
            LL[l] = LR[l] = l;
            if (NEXT[l] != -1 && NEXT[l] <= r) {
                upd(abs(NEXT[l] - LR[NEXT[l]]), -1);
                LR[l] = LR[NEXT[l]];
                LL[LR[l]] = l;
                LR[NEXT[l]] = NEXT[l];
            }
            upd(abs(l - LR[l]), 1);
        }

        while (r < Qs[i].r) {
            ++r;
            LL[r] = LR[r] = r;
            if (PREV[r] != -1 && PREV[r] >= l) {
                upd(abs(PREV[r] - LL[PREV[r]]), -1);
                LL[r] = LL[PREV[r]];
                LR[LL[r]] = r;
                LL[PREV[r]] = PREV[r];
            }
            upd(abs(r - LL[r]), 1);
        }

        while (l < Qs[i].l) {
            upd(abs(l - LR[l]), -1);

            if (NEXT[l] != -1 && NEXT[l] <= r) {
                LR[NEXT[l]] = LR[l];
                LL[LR[l]] = NEXT[l];
                upd(abs(NEXT[l] - LR[NEXT[l]]), 1);
            }

            LL[l] = LR[l] = l;
            ++l;
        }
        while (r > Qs[i].r) {
            upd(abs(r - LL[r]), -1);

            if (PREV[r] != -1 && PREV[r] >= l) {
                LL[PREV[r]] = LL[r];
                LR[LL[r]] = PREV[r];
                upd(abs(PREV[r] - LL[PREV[r]]), 1);
            }

            LL[r] = LR[r] = r;
            --r;
        }

        int j = 0;
        FOR(k, 0, 900) if (OCSQ[k] > 0) j = k;
        FOR(k, 600 * j, (600) * (j + 1)) if (OC[k] > 0) ANS[Qs[i].i] = k;
    }

    FOR(i, 0, Q) {
        printf("%d\n", ANS[i]);
    }

    return 0;
}