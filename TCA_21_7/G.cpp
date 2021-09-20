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
const int MAXN = 2e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll P[MAXN], S[MAXN];

int main() {
    int n, a, b; riii(n, a, b);
    b = min(b, n);
    vector<pair<ll, ll>> x(n);
    FOR(i, 0, n) rll(x[i].F, x[i].S);
    sort(ALL(x), [](pair<ll, ll> A, pair<ll, ll> B) {
        return A.F - A.S > B.F - B.S;
    });

    FOR(i, 0, n) {
        P[i] = max(x[i].F, x[i].S);
        if (i > 0) P[i] += P[i - 1];
    }
    for (int i = n - 1; i >= 0; --i)
        S[i] = x[i].S + S[i + 1];

    if (b == 0) {
        printf("%lld\n", S[0]);
        return 0;
    }

    ll ans = 0;
    FOR(i, 0, n) {
        if (i <= b - 1) {
            // printf("%lld %lld %lld\n", P[b - 1], max(x[i].F, x[i].S), max(x[i].F * (1 << a), x[i].S));
            ans = max(ans, P[b - 1] - max(x[i].F, x[i].S) + max(x[i].F * (1 << a), x[i].S) + S[b]);
        }
        else
            ans = max(ans,
                      (b - 2 >= 0 ? P[b - 2] : 0) + S[b - 1] - x[i].S + max(x[i].F * (1 << a), x[i].S));
    }
    printf("%lld\n", ans);
    return 0;
}