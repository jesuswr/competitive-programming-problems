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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int f(int x, int y) {
    if ((x & y) == y)
        return 0;
    int aux;
    for (int b = 24; b >= 0; --b) {
        if (((~x >> b) & 1) && ((y >> b) & 1)) {
            aux = b;
            break;
        }
    }
    // printf("%d\n", aux);
    for (int b = aux; b <= 24; ++b) {
        if ((x >> b) & 1) {
            int val = (1 << b) - (y & ((1 << b) - 1));
            if ((x & (y + val)) == y + val)
                return val;
        }
    }
    return 1e9;
}

void solve() {
    int a, b; rii(a, b);
    int ans = 1e6;
    FOR(bb, b, 4 * b + 1) {
        // printf("%d %d\n", bb, f(bb, a));
        ans = min(ans, f(bb, a) + 1 + (bb - b));
        ans = min(ans, bb - a);
    }
    printf("%d\n", ans);
}

// 001101110101100110
// 101000001001000110
// 100000000000000000

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}


