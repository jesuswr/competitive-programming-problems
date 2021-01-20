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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N;
string S;
struct STN {
    int mx_pref = 0, mn_pref = 0, tot = 0;
    void merge(STN L, STN R) {
        mx_pref = max(L.mx_pref, L.tot + R.mx_pref);
        mn_pref = min(L.mn_pref, L.tot + R.mn_pref);
        tot = L.tot + R.tot;
    }
    void operator=(int a) {
        mx_pref = max(a, 0);
        mn_pref = min(a, 0);
        tot = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = (S[l] == '+' ? 1 : -1);
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

void solve() {
    int m; rii(N, m);
    cin >> S;
    STB();
    while (m--) {
        int l, r; rii(l, r); --l;
        STN q;
        if (l > 0) q.merge(q, STQ(0, l));
        if (r < N) q.merge(q, STQ(r, N));
        printf("%d\n", q.mx_pref + 1 - q.mn_pref);

    }
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}