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
const int MAXN = 1e6 + 100; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, Q;
ll LZY[MAXN];
ll BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
    for (; p < MAXN; p += p & -p) // se puede cambiar maxN por n+5 si hace falta mas velocidad
        BIT[p] += val;
}
void updRGE(int l, int r, ll val) {
    updBIT(l, val);
    updBIT(r + 1, -val);
}
ll sumBIT(int p) {
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}



set<tuple<int, int, int>> ST;


void color() {
    int l, r, c; riii(l, r, c);
    auto it = ST.ub({l, INF, INF});
    --it;
    vector<tuple<int, int, int>> rgs;
    for (; it != ST.end(); ++it) {
        auto [_l, _r, _c] = *it;
        if (_l > r) break;
        rgs.emplace_back(_l, _r, _c);
    }

    for (auto [rl, rr, rc] : rgs) {
        if (rl >= l && rr <= r) { // l rl rr r
            ST.erase({rl, rr, rc});
            updRGE(rl, rr, LZY[rc] - LZY[c]);
        }
        else if (rl < l && rr > r) { // rl l r rr
            ST.erase({rl, rr, rc});
            ST.insert({rl, l - 1, rc});
            ST.insert({r + 1, rr, rc});
            updRGE(l, r, LZY[rc] - LZY[c]);
        }
        else if (l <= rl) { // l rl r rr
            ST.erase({rl, rr, rc});
            ST.insert({r + 1, rr, rc});
            updRGE(rl, r, LZY[rc] - LZY[c]);
        }
        else if (rr <= r) { // rl l rr r
            ST.erase({rl, rr, rc});
            ST.insert({rl, l - 1, rc});
            updRGE(l, rr, LZY[rc] - LZY[c]);
        }
    }
    ST.insert({l, r, c});
    // for (auto [x, y, z] : ST) printf("%d %d %d\n", x, y, z);
    // printf("\n");
}

void add() {
    int c, x; rii(c, x);
    LZY[c] += x;
}

void query() {
    int i; ri(i);
    auto it = ST.ub({i, INF, INF});
    --it;
    auto [_, __, c] = *it;
    // printf("%d %d %d %d\n", i, _, __, c);
    printf("%lld\n", sumBIT(i) + LZY[c]);
}
char q[69];
int main() {
    rii(N, Q);
    ST.insert({1, N, 1});
    while (Q--) {
        scanf("%s", q);
        if (q[0] == 'C')
            color();
        else if (q[0] == 'A')
            add();
        else
            query();
    }

    return 0;
}