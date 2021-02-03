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
int N, K;
map<int, queue<int>> Q;
int A[MAXN];
vi QUERIES[MAXN];
map<int, int> LAST;

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    int sm;
    void merge(STN& L, STN& R) {
        sm = L.sm + R.sm;
    }
};
STN ST[4 * MAXN];
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
        ST[id].sm += x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int main() {
    rii(N, K);
    bool ans = false;
    FOR(i, 0, N) ri(A[i]);
    for (int i = N - 1; i >= 0; i--) {
        if (SZ(Q[A[i]]) >= K) Q[A[i]].pop();
        Q[A[i]].push(i);
        if (SZ(Q[A[i]]) == K) {
            int j = Q[A[i]].front();
            QUERIES[j].pb(i);
            ans = true;
        }
    }
    if (!ans) {
        printf("-1\n");
        return 0;
    }
    int mn = INF;
    for (int i = 0; i < N; i++) {
        if (LAST.find(A[i]) != LAST.end()) STU(LAST[A[i]], -1);
        LAST[A[i]] = i;
        STU(i, 1);
        for (auto j : QUERIES[i]) {
            mn = min(mn, STQ(j, i + 1).sm - 1);
        }
    }
    printf("%d\n", mn);
    return 0;
}