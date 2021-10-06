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
const int MAXN = 3e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N; ll K;
int A[MAXN];
int MXA;
ll PRE[MAXN];

void pre() {
    sort(A, A + N);
    FOR(i, 0, N) PRE[i] = A[i] + (i > 0 ? PRE[i - 1] : 0);
    MXA = A[N - 1];
}
pair<ll, ll> qry(ll lo, ll hi) {
    int l = ub(A, A + N, lo) - A, r = ub(A, A + N, hi) - A;
    int sz = r - l;
    if (sz == 0)
        return {0, 0};
    ll sm = PRE[l + sz - 1] - (l > 0 ? PRE[l - 1] : 0);
    return {sz, sm};
}

bool posible(ll d) {
    ll need = 0;
    ll _d = d;
    while (d - _d <= MXA) {
        auto [n_elem, sum] = qry(d - _d, d);
        need += d * n_elem - sum;
        d += _d;
    }
    return need <= K;
}

int main() {
    ri(N), rl(K);
    FOR(i, 0, N) ri(A[i]);
    pre();
    ll ans = 1;
    for (int i = 2; i <= MXA; ++i)
        if (posible(i))
            ans = i;
    ll lo = MXA, hi = 1e18 + MXA;
    while (lo < hi) {
        ll mi = lo + (hi - lo + 1) / 2;
        if ((__int128)mi * N - PRE[N - 1] <= K) {
            lo = mi;
            ans = lo;
        }
        else
            hi = mi - 1;
    }
    printf("%lld\n", ans);
    return 0;
}