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
const int MAXN = 5010; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
    int mn;
    int ind;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
        if (mn == L.mn) ind = L.ind;
        else ind = R.ind;
    }
    void operator=(int a) {
        mn = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N + 2) {
    if (r - l < 2) {
        ST[id] = A[l];
        ST[id].ind = l;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N + 2) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}


int f(int l, int r) {
    if (l >= r) return 0;
    auto q = STQ(l, r);
    int mn = q.mn;
    int m = q.ind;
    int mx = max(A[l - 1], A[r]);
    return min(r - l, (mn - mx) + f(l, m) + f(m + 1, r));
}


int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i + 1]);
    STB();
    A[0] = A[N + 1] = 0;
    printf("%d\n", f(1, N + 1));

    return 0;
}