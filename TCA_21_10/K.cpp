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
const int MAXN = 1e6; // CAMBIAR ESTE
const int MAXA = 1e7 + 69;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int SV[MAXA];
void pre() {
    FOR(i, 2, MAXA) if (SV[i] == 0) {
        int j = i;
        while (j < MAXA) {
            if (SV[j] == 0)
                SV[j] = i;
            j += i;
        }
    }
}

int K;
int A[MAXN];
vector< pair<int, ll> > P;
ll NEED[MAXA];

bool valid(ll n) {
    for (auto [i, need] : P) {
        ll cnt = 0;
        ll m = n;
        while (m > 1) {
            cnt += m / i;
            m /= i;
        }
        if (cnt < need)
            return false;
    }
    return true;
}

int main() {
    pre();
    ri(K);
    FOR(i, 0, K) ri(A[i]);
    sort(A, A + K);
    int j = 0;
    FOR(n, 2, MAXA) {
        while (j < K && A[j] < n) ++j;
        if (j == K)
            break;
        int m = n;
        while (m > 1) {
            int mn_div = SV[m];
            ll cnt = 0;
            while (m % mn_div == 0) {
                ++cnt;
                m /= mn_div;
            }
            NEED[mn_div] += (K - j) * cnt;
        }
    }
    FOR(n, 2, MAXA) if (NEED[n] > 0)
        P.pb({n, NEED[n]});

    ll lo = 1, hi = 1e18;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        if (valid(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    printf("%lld\n", lo);
    return 0;
}