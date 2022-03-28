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

int S;
ll W[2][100];
unordered_map<int, int> DP[101][101];
vector<ll> A[2];
int f(int p0, int p1, int dff) {
    if (abs(dff) >= 50000 + 11000) return INF;
    if (p0 == sz(A[0]) && p1 == sz(A[1])) {
        return (dff == 50000 ? 0 : INF);
    }
    if (DP[p0][p1].find(dff) != DP[p0][p1].end())
        return DP[p0][p1][dff];
    int ans = INF;
    if (p0 < sz(A[0])) ans = min(ans, f(p0 + 1, p1, dff + 2 * A[0][p0] ));
    if (p1 < sz(A[1])) ans = min(ans, f(p0, p1 + 1, dff - A[1][p1] ));
    if (p0 < sz(A[0]) && p1 < sz(A[1]))
        ans = min(ans, 1 + f(p0 + 1, p1 + 1, dff + A[0][p0] - 2 * A[1][p1]));
    return DP[p0][p1][dff] = ans;
}

void solve() {
    FOR(i, 0, 100) FOR(j, 0, 100) DP[i][j].clear(), DP[i][j].reserve(100);
    A[0].clear();
    A[1].clear();
    ri(S);
    FOR(i, 0, S) lri(W[1][i]);
    FOR(i, 0, S) lri(W[0][i]);
    ll dff = 0;
    FOR(i, 0, S) {
        if (W[0][i] != 2) dff += W[0][i] * (i + 1);
        else A[0].pb(i + 1);
        if (W[1][i] != 1) dff -= W[1][i] * (i + 1);
        else A[1].pb(i + 1);
    }
    if (abs(dff) >= 50000) {
        printf("-1\n");
        return;
    }
    int ans = f(0, 0, dff + 50000);
    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);
}
// 4 + 2 + 3 = 9
// 2 + 4 + 3 = 9

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
