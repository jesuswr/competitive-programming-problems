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
    ll l, r, a; lrii(l, r); lri(a);
    if (a == 1) {
        printf("%lld\n", r);
        return;
    }

    ll mult_a = ((r + 1) / a) * a;
    --mult_a;
    if (mult_a > r) mult_a -= a;
    if (mult_a < l) printf("%lld\n", r / a + r % a);
    else printf("%lld\n", mult_a / a + mult_a % a);

}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
