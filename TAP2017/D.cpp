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
const int MAXN = 410; // CAMBIAR ESTE

// GJNM
int V, E;
long double C[MAXN], D[MAXN];
struct EDGE {
    int f, t;
    long double a, b; // a * x + b
};
vector<EDGE> G;

bool valid(long double s) {
    FOR(i, 0, MAXN) D[i] = LLINF;
    D[0] = -s;
    FOR(i, 0, 2 * V) {
        bool change = false;
        for (auto e : G) {
            if (D[e.f] < 0 && D[e.t] > e.a * D[e.f] + e.b) {
                D[e.t] = e.a * D[e.f] + e.b;
                change = true;
            }
        }
        if (!change) break;
    }
    for (auto e : G) {
        if (D[e.f] < 0 && D[e.t] > e.a * D[e.f] + e.b) {
            return true;
        }
    }
    return false;
}

int main() {
    rii(V, E);
    FOR(i, 0, V) dadsadasda = scanf("%Lf", C + i);
    FOR(i, 0, E) {
        int a, b, p; riii(a, b, p);
        --a, --b;
        G.pb({a, b, 1.0, 1.0 * p});
        G.pb({b, a, 1.0, 1.0 * p});
        G.pb({V + a, V + b, 1.0, p*C[a]});
        G.pb({V + b, V + a, 1.0, p*C[b]});
    }
    FOR(i, 0, V) {
        G.pb({i, V + i, C[i], 0});
        G.pb({V + i, i, 1.0 / C[i], 0});
    }

    int lo = 1, hi = 2e6;
    bool good = false;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (valid(mi)) {
            good = true;
            hi = mi;
        }
        else
            lo = mi + 1;
    }

    if (good && hi <= (int)1e6) printf("%d\n", hi);
    else printf("-1\n");

    return 0;
}