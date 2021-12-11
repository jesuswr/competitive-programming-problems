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
const int MAXN = 1e6 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
bool IS_P[MAXN];
void pre() {
    FOR(i, 2, MAXN) IS_P[i] = 1;
    FOR(i, 2, MAXN) if (IS_P[i]) {
        for (int j = i + i; j < MAXN; j += i)
            IS_P[j] = 0;
    }
}

ll _solve(const vi &a) {
    ll ans = 0;
    ll prod = a[0];
    int l = 0, r = 0;
    int lst = -INF;
    if (IS_P[a[0]])
        lst = 0;
    while (69) {
        while (l < r && (prod >= MAXN || (prod > 1 && !IS_P[prod])) ) {
            prod /= a[l];
            ++l;
        }
        if (IS_P[prod] && (l != r)) {
            ans += max(0, lst - l);
            if (r != lst)
                ++ans;
        }
        ++r;
        if (r == SZ(a))
            break;
        if (IS_P[a[r]])
            lst = r;
        prod = prod * a[r];
    }
    return ans;
}


void solve() {
    int n, e; rii(n, e);
    vi a(n);
    FOR(i, 0, n) ri(a[i]);
    ll ans = 0;
    FOR(i, 0, e) {
        vi b;
        for (int j = i; j < n; j += e)
            b.pb(a[j]);
        ans += _solve(b);
    }
    printf("%lld\n", ans);
}


int main() {
    pre();
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}