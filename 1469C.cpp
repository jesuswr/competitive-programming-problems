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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int n, k;
int h[MAXN];
int lo[MAXN], hi[MAXN];

void solve() {
    rii(n, k);
    FOR(i, 0, n) ri(h[i]);

    bool ans = true;
    pii all = {h[0], h[0]};
    FOR(i, 0, n) {
        pii now;
        if (i == 0 || i == n - 1) now = {h[i], h[i]};
        else now = {h[i], h[i] + k - 1};

        all.F -= k - 1;
        all.S += k - 1;

        all = {max(all.F, now.F), min(all.S, now.S)};
        if (all.F > all.S) ans = false;
    }
    if (ans) printf("YeS\n");
    else printf("nO\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}