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

const int MX_DIFF = (101 * 101) / 2;
int MX_CHANGE;
int S;
vector<ll> A[2];
ll W[2][100];
int DP[101][101][MX_DIFF];
int f(int p0, int p1, int dff) {
    if (dff >= MX_DIFF || dff < 0 ) return INF;
    if (p0 == sz(A[0]) || p1 == sz(A[1]))
        return (dff == 0 ? 0 : INF);
    if (DP[p0][p1][dff] != -1)
        return DP[p0][p1][dff];

    int ans = INF;
    if (p0 < sz(A[0])) ans = min(ans, f(p0 + 1, p1, dff));
    if (p1 < sz(A[1])) ans = min(ans, f(p0, p1 + 1, dff));
    if (p0 < sz(A[0]) && p1 < sz(A[1]))
        ans = min(ans, 1 + f(p0 + 1, p1 + 1, dff - A[0][p0] - A[1][p1]));
    return DP[p0][p1][dff] = ans;
}

void solve() {
    ms(DP, -1);
    A[0].clear();
    A[1].clear();
    ri(S);
    FOR(i, 0, S) lri(W[1][i]);
    FOR(i, 0, S) lri(W[0][i]);
    ll dff = 0;
    FOR(i, 0, S) {
        dff += W[0][i] * (i + 1);
        if (W[0][i] == 2) {
            A[0].pb(i + 1);
        }
        dff -= W[1][i] * (i + 1);
        if (W[1][i] == 1) {
            A[1].pb(i + 1);
        }
    }
    if (dff >= MX_DIFF || dff < 0) {
        printf("-1\n");
        return;
    }
    int ans = f(0, 0, dff);
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
