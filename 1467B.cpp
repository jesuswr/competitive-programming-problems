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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
void solve() {
    int n; ri(n);
    vi a(n);
    FOR(i, 0, n) ri(a[i]);
    vi bad(n);
    int tot = 0;
    FOR(i, 1, n - 1) {
        bad[i] = (a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]);
        tot += bad[i];
    }
    int best = tot;
    FOR(i, 1, n - 1) {
        vi opts = {a[i - 1], a[i + 1], a[i + 1] - 1, a[i + 1] + 1, a[i - 1] + 1, a[i - 1] - 1};
        for (auto x : opts) {
            int curr = tot;
            int old = a[i];
            a[i] = x;

            FOR(j, max(1, i - 5), min(n - 1, i + 5)) curr -= bad[j];
            FOR(j, max(1, i - 5), min(n - 1, i + 5)) {
                curr += (a[j] > a[j - 1] && a[j] > a[j + 1]) || (a[j] < a[j - 1] && a[j] < a[j + 1]);
            }
            a[i] = old;
            best = min(best, curr);
        }
    }
    printf("%d\n", best);
}


int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}