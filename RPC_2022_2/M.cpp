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
const int MAXN = 3e5 + 100; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K, A[MAXN];

ll BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
    ++p;    // esto es porque el bit esta indexado desde 1
    for (; p < MAXN; p += p & -p) // se puede cambiar maxN por n+5 si hace falta mas velocidad
        BIT[p] += val;
}
ll sumBIT(int p) {
    ++p;
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

struct STN {
    int mn, mni;
    void merge(STN& L, STN& R) {
        if (L.mn <= R.mn) {
            mn = L.mn;
            mni = L.mni;
        }
        else {
            mn = R.mn;
            mni = R.mni;
        }
        // printf("\tL %d %d \n", L.mn, L.mni);
        // printf("\tR %d %d \n", R.mn, R.mni);
        // printf("%d %d \n", mn, mni);
    }
    void operator=(int a) {
        mni = a;
        mn = A[a];
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = l;
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
        ST[id].mn = INF;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

vi INDS[MAXN];
int VAL[MAXN];

int main() {
    rii(N, K);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) A[i]--;
    FOR(i, 0, N) INDS[A[i]].pb(i);
    set<int> uniq;
    for (int i = N - 1; i >= 0; --i) {
        uniq.insert(A[i]);
        VAL[i] = SZ(uniq);
    }
    STB();
    vi ans;
    int l = 0;
    for (int i = 0; i < K; ++i) {
        int lo = l, hi = N - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo + 1) / 2;
            int val = VAL[mi] + sumBIT(mi);
            if (val == K - i)
                lo = mi;
            else
                hi = mi - 1;
        }
        int ind = STQ(l, lo + 1).mni;
        int x = A[ind];
        updBIT(0, -1);
        updBIT(INDS[x].back() + 1, 1);
        for (auto xi : INDS[x]) STU(xi, INF);
        l = ind + 1;
        ans.pb(x + 1);
    }
    FOR(i, 0, SZ(ans)) printf("%d%c", ans[i], i == SZ(ans) - 1 ? '\n' : ' ');
    return 0;
}