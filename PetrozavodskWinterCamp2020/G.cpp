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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};

int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

int N;
pt TA[6], LR[6];

struct NODE {
    int p = 0, msk = 0;
    int to[6];
};

void solve() {
    ri(N);
    FOR(i, 0, N) rll(TA[i].x, TA[i].y);
    FOR(i, 0, N) rll(LR[i].x, LR[i].y);
    stack<NODE> dfs;
    NODE aux;
    dfs.push(aux);
    while (!dfs.empty()) {
        auto x = dfs.top(); dfs.pop();
        if (x.p == N) {
            FOR(i, 0, N) {
                printf("2\n");
                printf("%lld %lld\n", TA[i].x, TA[i].y);
                printf("%lld %lld\n", LR[x.to[i]].x, LR[x.to[i]].y);
            }
            break;
        }
        FOR(i, 0, N) {
            if (x.msk & (1 << i)) continue;
            bool good = true;
            FOR(j, 0, x.p) {
                good &= !check_inter(TA[x.p], LR[i], TA[j], LR[x.to[j]]);
            }
            if (good) {
                aux.p = x.p + 1;
                aux.msk = x.msk | (1 << i);
                FOR(k, 0, N) aux.to[k] = x.to[k];
                aux.to[x.p] = i;
                dfs.push(aux);
            }
        }
    }
}


int main() {
    int t; ri(t);
    while (t--) {
        solve();
    }

    return 0;
}