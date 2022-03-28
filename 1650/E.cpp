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
    int n, d; rii(n, d);
    vi x(n + 1);
    FOR(i, 0, n) ri(x[i + 1]);
    multiset<int> lens;
    FOR(i, 1, n + 1) lens.insert(x[i] - x[i - 1]);
    int ans = 0;
    FOR(i, 1, n) {
        lens.erase(lens.find(x[i] - x[i - 1]));
        lens.erase(lens.find(x[i + 1] - x[i]));
        lens.insert(x[i + 1] - x[i - 1]);

        ans = max(ans, min( *lens.begin() , max(d - x[n], (*lens.rbegin()) / 2)  ));
        // printf("%d %d\n", i, ans);
        lens.insert(x[i] - x[i - 1]);
        lens.insert(x[i + 1] - x[i]);
        lens.erase(lens.find(x[i + 1] - x[i - 1]));
    }
    lens.erase(lens.find(x[n] - x[n - 1]));
    ans = max(ans, min( *lens.begin() , max(d - x[n - 1], (*lens.rbegin()) / 2)  ));

    printf("%d\n", ans - 1);
}


int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}
