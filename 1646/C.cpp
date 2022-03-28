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
int cnt_bits(ll x) {
    int cnt = 0;
    while (x > 0) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}

ll F[15];

void solve() {
    ll n; rl(n);
    int ans = 100;
    FOR(i, 0, 1 << 15) {
        int on_b = 0;
        ll sm = 0;
        FOR(b, 0, 15) if ((i >> b) & 1) {
            on_b++;
            sm += F[b];
        }
        if (sm <= n)
            ans = min(ans, cnt_bits(n-sm) + on_b);
    }
    printf("%d\n", ans);
}


int main() {
    F[0] = 1;
    FOR(i, 1, 15) F[i] = i * F[i - 1];
    F[0] = F[2] = 0;
    int t; ri(t);
    while (t--) solve();
    return 0;
}