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

int N, X;
int A[MAXN];
void solve() {
    rii(N, X);
    FOR(i, 0, N) ri(A[i]);
    vector<ll> MX(N + 1, -INFLL);
    MX[0] = 0;
    FOR(l, 0, N) {
        ll sm = 0;
        FOR(r, l, N) {
            sm += A[r];
            MX[r - l + 1] = max(MX[r - l + 1], sm);
        }
    }
    for (int i = N - 1; i >= 0; --i) MX[i] = max(MX[i], MX[i + 1]);
    ll ans = 0;
    FOR(i, 0, N + 1) {
        ans = max(ans, MX[i] + i * X);
        printf("%lld%c", ans, i == N ? '\n' : ' ');
    }
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
