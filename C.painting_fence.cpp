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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 5010; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN];

// Todos los rangos son semi-abiertos [a,b)
int N;
struct STN {
    int ind;
    void merge(STN& L, STN& R) {
        if (a[L.ind] <= a[R.ind])
            ind = L.ind;
        else
            ind = R.ind;
    }
    void operator=(int a) {
        ind = a;
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
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

ll f(int l, int r, int h) {
    if (r < l)
        return 0;
    int mn = STQ(l, r + 1).ind;
    // two options
    // * all verticals (r-l+1)
    // * put horizontals until you reach the min
    // less horizontals than that dont make sense because you still need vertical for min
    return min((ll)r - l + 1, f(l, mn - 1, a[mn]) + f(mn + 1, r, a[mn]) + (a[mn] - h));
}


int main() {
    int n;
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    N = n;
    STB();
    printf("%lld\n", f(0, n - 1, 0));

    return 0;
}