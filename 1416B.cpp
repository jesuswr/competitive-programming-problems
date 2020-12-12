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
struct op {
    int i, j, x;
};

void solve() {
    int n; ri(n);
    vi a(n + 1);
    int sum = 0;
    FOR(i, 0, n) {
        ri(a[i + 1]);
        sum += a[i + 1];
    }
    if (sum % n) {
        printf("-1\n");
        return;
    }

    vector<op> ops;
    int k = sum / n;

    for (int i = 2; i <= n; i++) {
        int need = (i - (a[i] % i)) % i;
        ops.pb({1, i, need});
        ops.pb({i, 1, (a[i] + i - 1) / i});
    }
    for (int i = 2; i <= n; i++) {
        ops.pb({1, i, k});
    }
    printf("%d\n", SZ(ops));
    for (auto o : ops)
        printf("%d %d %d\n", o.i, o.j, o.x);

}



int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}