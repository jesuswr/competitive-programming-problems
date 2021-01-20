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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<ll> vi;
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

// GJNM


void solve() {
    int n; ri(n);
    vi a(n);
    FOR(i, 0, n) rl(a[i]);
    vi pre(n), suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (pre[i - 1] < 0) pre[i] = -1;
        else pre[i] = a[i] - pre[i - 1];
    }
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (suf[i + 1] < 0) suf[i] = -1;
        else suf[i] = a[i] - suf[i + 1];
    }
    if (pre[n - 1] == 0) {
        printf("YES\n");
        return;
    }
    for (int i = 0; i + 1 < n; i++) {
        if (i > 0 && pre[i - 1] < 0) continue;
        if (i + 2 < n && suf[i + 2] < 0) continue;
        int x = a[i + 1], y = a[i];
        if (i > 0) x -= pre[i - 1];
        if (i + 2 < n) y -= suf[i + 2];
        if (x == y && y >= 0) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}