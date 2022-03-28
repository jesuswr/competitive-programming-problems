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
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


void solve() {
    int n, k; rii(n, k);
    vector<bool> mrk(2 * n);
    vii edg(k);
    for (auto &[a, b] : edg) {
        rii(a, b);
        --a; --b;
        if (a > b) swap(a, b);
        mrk[a] = mrk[b] = 1;
    }
    vi free;
    FOR(i, 0, 2 * n) if (!mrk[i]) free.pb(i);
    FOR(i, 0, n - k) edg.pb({free[i], free[n - k + i]});
    int cnt = 0;
    FOR(i, 0, n) FOR(j, i + 1, n) {
        if ( ( edg[j].F < edg[i].F && edg[i].F < edg[j].S && edg[j].S < edg[i].S ) || ( ( edg[j].S > edg[i].S && edg[i].F < edg[j].F && edg[j].F < edg[i].S ) ) ) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
