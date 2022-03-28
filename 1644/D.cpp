#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 998244353;
const int MAXN = 2e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


void solve() {
    int n, m, k, q;
    rii(n, m); rii(k, q);
    vii qs(q);
    FOR(i, 0, q) rii(qs[i].F, qs[i].S);
    reverse(all(qs));
    set<int> xs, ys;
    int cnt = 0;
    for (auto [x, y] : qs) {
        bool good_x = (xs.find(x) == xs.end()) && (sz(ys) < m);
        bool good_y = (ys.find(y) == ys.end()) && (sz(xs) < n);
        cnt += good_x || good_y;
        xs.insert(x);
        ys.insert(y);
    }
    ll ans = 1;
    FOR(_, 0, cnt) ans = (ans * k) % MOD;
    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
