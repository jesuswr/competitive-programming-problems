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

const int MX_DIFF = (101 * 101);
int MX_CHANGE;
int S;
vector<int> A[2];
ll W[2][100];
int DP[101][101][MX_DIFF];
int f(int dff) {
    int sz0 = sz(A[0]), sz1 = sz(A[1]);
    for (int i = sz0; i >= 0; --i) {
        for (int j = sz1; j >= 0; --j) {
            int aux = 201 * min(sz0 - i, sz1 - j);
            for (int d = 0; d <= min(dff, aux + 201); ++d) {
                DP[i][j][d] = INF;
                if (d > aux) continue;
                if (i == sz0 && j == sz1 && d == 0) DP[i][j][d] = 0;
                if (i < sz0) DP[i][j][d] = min(DP[i][j][d], DP[i + 1][j][d]);
                if (j < sz1) DP[i][j][d] = min(DP[i][j][d], DP[i][j + 1][d]);
                if (i < sz0 && j < sz1 && d - A[0][i] - A[1][j] >= 0) {
                    DP[i][j][d] = min(DP[i][j][d], 1 + DP[i + 1][j + 1][d - A[0][i] - A[1][j] ]);
                    // printf("\t%d %d %d : %d\n", i + 1, j + 1, d - A[0][i] - A[1][j], DP[i + 1][j + 1][d - A[0][i] - A[1][j]]);
                }
                // printf("%d %d %d : %d\n", i, j, d, DP[i][j][d]);
            }
        }
    }
    return DP[0][0][dff];
}

void solve() {
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
    int ans = f(dff);
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
