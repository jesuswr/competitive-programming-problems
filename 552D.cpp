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
const int MAXN = 2010; // CAMBIAR ESTE
struct PTO {
    int x, y;

    bool operator<(PTO other) {
        return x < other.x;
    }

    int get_hash(PTO other) {
        int b = other.y - y;
        int a = other.x - x;
        int gcd = __gcd(a, b);
        a /= gcd;
        b /= gcd;
        return 410 * (a + 200) + (b + 200);
    }
};



// GJNM
int N;
PTO P[MAXN];

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    int cnt;
    void merge(STN& L, STN& R) {
        cnt = L.cnt + R.cnt;
    }
    void operator=(int a) {
        cnt = a;
    }
};
STN ST[4 * 168100];
void STB(int id = 1, int l = 0, int r = 168100) {
    if (r - l < 2) {
        ST[id] = 0;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = 168100) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int x, int id = 1, int l = 0, int r = 168100) {
    if (r - l < 2) {
        ST[id].cnt++;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


int main() {
    ri(N);
    FOR(i, 0, N) rii(P[i].x, P[i].y);
    ll ans = 0;
    FOR(i, 0, N) {
        STB();
        FOR(j, i + 1, N) {
            int h = P[i].get_hash(P[j]);
            ans += STQ(0, 168100).cnt;
            ans -= STQ(h, h + 1).cnt;
            STU(h, 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}