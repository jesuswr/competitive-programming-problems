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
int A[40];

vi go(int l, int r) {
    vi ret;
    int len = r - l;
    FOR(msk, 0, (1 << len)) {
        int sm = 0;
        FOR(b, 0, len) if ((msk >> b) & 1)
            sm = min(sm + A[l + b], (int)1e9 + 1);
        ret.pb(sm);
    }
    sort(ALL(ret));
    return ret;
}

int main() {
    int n, x; rii(n, x);
    FOR(i, 0, n) ri(A[i]);
    auto l = go(0, n / 2), r = go(n / 2, n);
    ll ans = 0;
    for (auto sm1 : l)
        ans += ub(ALL(r), x - sm1) - lb(ALL(r), x - sm1);
    printf("%lld\n", ans);
    return 0;
}