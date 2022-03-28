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
int X[MAXN], W[MAXN];

void solve() {
    int n, m; rii(n, m);
    FOR(i, 0, m) rii(X[i], W[i]);
    vi ord(m);
    FOR(i, 0, m) ord[i] = i;
    sort(all(ord), [](int i, int j) {
        return W[i] < W[j];
    });
    sort(ord.begin(), ord.begin() + 2 * n, [](int i, int j) {
        return X[i] < X[j];
    });
    int sm = 0;
    FOR(i, 0, 2 * n) sm += W[ord[i]];
    printf("%d\n", sm);
    FOR(i, 0, n) printf("%d %d\n", ord[i] + 1, ord[2 * n - 1 - i] + 1);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
