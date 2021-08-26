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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, Q;
int A[MAXN];
vi C[MAXN];
int LQ[MAXN], RQ[MAXN], VQ[MAXN];

struct STN {
    int val = 0;
    void merge(STN& L, STN& R) {
        val = L.val & R.val;
    }
    void operator=(int a) {
        val = a;
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

int main() {
    rii(N, Q);
    FOR(i, 0, Q) {
        riii(LQ[i], RQ[i], VQ[i]); LQ[i]--;
        C[LQ[i]].pb(VQ[i]);
        C[RQ[i]].pb(-VQ[i]);
    }

    vi cnt(31, 0);
    FOR(i, 0, N) {
        for (auto v : C[i]) {
            int add = v / abs(v);
            v = abs(v);
            FOR(b, 0, 31) if ((v >> b) & 1) {
                cnt[b] += add;
            }
        }
        A[i] = 0;
        FOR(b, 0, 31) if (cnt[b] > 0)
            A[i] |= (1 << b);
    }

    STB();
    bool ans = true;
    FOR(i, 0, Q) {
        if (STQ(LQ[i], RQ[i]).val != VQ[i])
            ans = false;
    }
    if (ans) {
        printf("YES\n");
        FOR(i, 0, N) printf("%d ", A[i]);
        printf("\n");
    }
    else
        printf("NO\n");

    return 0;
}