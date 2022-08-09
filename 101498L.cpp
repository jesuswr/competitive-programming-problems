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
void solve() {
    int v, e; rii(v, e);
    vector<tuple<int, int, int>> edge(e);
    FOR(i, 0, e) {
        int a, b, c;
        riii(a, b, c);
        --a, --b;
        edge[i] = {a, b, c};
    }
    vector<ll> dst(v);
    FOR(_, 0, v + 2) {
        for (auto [from, to, cst] : edge)
            dst[to] = min(dst[to], dst[from] + cst);
    }

    for (auto [from, to, cst] : edge)
        if (dst[to] > dst[from] + cst) {
            printf("-inf\n");
            return;
        }

    ll mn = LLINF;
    FOR(i, 0, v) if (dst[i] != 0)
        mn = min(mn, dst[i]);
    for (auto [_, __, cst] : edge) mn = min(mn, 1ll * cst);
    printf("%lld\n", mn);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}