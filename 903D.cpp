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
typedef __int128 lll;

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
const int MAXN = 2e5 + 100; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N;
ll A[MAXN];
struct STN {
    lll cnt;
    lll sm;
    void merge(STN& L, STN& R) {
        cnt = L.cnt + R.cnt;
        sm = L.sm + R.sm;
    }
};
STN ST[4 * MAXN];
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
        ST[id].cnt++;
        ST[id].sm += x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
map<ll, ll> MP;
ll B[MAXN];

void compress() {
    FOR(i, 0, N) B[i] = A[i];
    sort(B, B + N);
    FOR(i, 0, N) MP[B[i]] = i + 10;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    ri(N);
    FOR(i, 0, N) rl(A[i]);
    compress();
    lll ans = 0, cnt = 0, sm = 0;
    FOR(i, 0, N) {
        lll new_cnt = cnt, new_sm = sm;
        auto stq = STQ(MP[A[i]], MP[A[i]] + 1);
        new_cnt -= stq.cnt;
        new_sm -= stq.sm;
        if (MP.find(A[i] - 1) != MP.end()) {
            stq = STQ(MP[A[i] - 1], MP[A[i] - 1] + 1);
            new_cnt -= stq.cnt;
            new_sm -= stq.sm;
        }
        if (MP.find(A[i] + 1) != MP.end()) {
            stq = STQ(MP[A[i] + 1], MP[A[i] + 1] + 1);
            new_cnt -= stq.cnt;
            new_sm -= stq.sm;
        }

        ans += new_cnt *  A[i] - new_sm;

        cnt++; sm += A[i];
        STU(MP[A[i]], A[i]);
    }
    print(ans); printf("\n");
    return 0;
}