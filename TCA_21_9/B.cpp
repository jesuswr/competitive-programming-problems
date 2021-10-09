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
    int n; ri(n);
    vi a(n), ans(n);
    FOR(i, 0, n) ri(a[i]);
    int mx = 0;
    FOR(i, 0, n) mx = max(mx, a[i]);
    if (n <= 2) {
        FOR(i, 0, n) printf("%d ", mx);
        printf("\n");
        return 0;
    }
    ans[n - 1] = ans[n - 2] = mx;
    FOR(l, 0, n - 1) {
        int r = l + 1;
        int dff = max(l, n - 1 - r) - min(l, n - 1 - r);
        ans[dff] = max(ans[dff], max(a[l], a[r]));
    }
    FOR(l, 0, n - 1) {
        int r = l + 2;
        int dff = max(l, n - 1 - r) - min(l, n - 1 - r);
        ans[dff] = max(ans[dff], min(max(a[l], a[r]), a[l + 1]));
    }
    FOR(i, 2, n) ans[i] = max(ans[i], ans[i - 2]);
    FOR(i, 0, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}