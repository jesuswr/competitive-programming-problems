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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N;

void solve() {
    ri(N);
    vector<ll> pos, neg; // 0 is neg because yes
    FOR(i, 0, N) {
        int tmp; ri(tmp);
        if (tmp > 0) pos.pb(tmp);
        else neg.pb(tmp);
    }
    sort(ALL(pos));
    sort(ALL(neg));

    ll ans = SZ(neg);
    if (SZ(pos) > 0) ans = max(ans, 1ll);
    ll mn_diff = LLINF;
    FOR(i, 1, SZ(neg)) mn_diff = min(mn_diff, neg[i] - neg[i - 1]);
    if (SZ(pos) > 0 && pos[0] <= mn_diff) ans = max(ans, SZ(neg) + 1ll);
    printf("%lld\n", ans);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}