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

int main() {
    int n, k; rii(n, k);
    vector<ll> a(n), pref(n);
    FOR(i, 0, n) rl(a[i]);
    sort(ALL(a));
    FOR(i, 0, n) pref[i] = a[i] + (i > 0 ? pref[i - 1] : 0);
    int mx_oc = 0, mx_i = -1;
    for (int i = 0; i < n; ++i) {
        int lo = 0, hi = i;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            ll sm = pref[i] - (mi > 0 ? pref[mi - 1] : 0);
            if ((i + 1 - mi) * a[i] - sm <= k)
                hi = mi;
            else
                lo = mi + 1;
        }
        if (i + 1 - hi > mx_oc) {
            mx_oc = i + 1 - hi;
            mx_i = a[i];
        }
    }
    printf("%d %d\n", mx_oc, mx_i);
    return 0;
}