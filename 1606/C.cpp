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
ll P10[18];
void pre() {
    P10[0] = 1;
    FOR(i, 1, 18) P10[i] = P10[i - 1] * 10;
}

void solve() {
    int n, k; rii(n, k);
    vector<bool> have(18);
    FOR(_, 0, n) {
        int a; ri(a);
        have[a] = 1;
    }
    vi ans;
    int e = 0;
    int lst = -1;
    while (k >= 0) {
        if (e < 10 && have[e])
            lst = e;
        ll aux;
        ans.pb(0);
        for (int d = 1; d < 10; ++d) {
            aux = P10[e - lst] * d;
            ans[e] = d;
            // printf("%d %lld\n", d, aux);
            if (aux > k)
                break;
        }
        // printf("\n");
        k -= aux;
        e++;
    }
    ++k;
    k = abs(k);
    // printf("%d\n", k);
    for (int d = SZ(ans) - 1; d >= 0; --d) {
        e = 0;
        for (int i = 0; i <= min(9, d); ++i) if (have[i]) e = i;

        ll aux = 0;
        for (int i = 0; i <= min(9, ans[d]); ++i) {
            aux = P10[d - e] * (ans[d] - i);
            // printf("%d %lld\n", d, aux);
            // printf("\t%d %lld\n", i, aux);
            if (aux <= k) {
                ans[d] = i;
                k -= aux;
                break;
            }
        }
        // printf("%d\n", k);
    }

    reverse(ALL(ans));
    for (auto d : ans) printf("%d", d);
    printf("\n");
}

int main() {
    pre();
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}