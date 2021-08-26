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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
void solve() {
    int a, b; rii(a, b);
    int n = a + b;

    int fst = (n + 1) / 2, snd = n / 2;
    set<int> ks;
    {   // first a
        int extra_a = max(a - fst, 0), extra_b = max(b - snd, 0);
        ks.insert(max(extra_a, extra_b));
        int mn_a = min(a, fst), mn_b = min(b, snd);
        FOR(i, 1, min(mn_a, mn_b) + 1)ks.insert(2 * i + max(extra_a, extra_b));
    }
    {   // first b
        swap(a, b);
        int extra_a = max(a - fst, 0), extra_b = max(b - snd, 0);
        ks.insert(max(extra_a, extra_b));
        int mn_a = min(a, fst), mn_b = min(b, snd);
        FOR(i, 1, min(mn_a, mn_b) + 1)ks.insert(2 * i + max(extra_a, extra_b));
    }

    printf("%d\n", SZ(ks));
    for (auto k : ks) printf("%d ", k);
    printf("\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}