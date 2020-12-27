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

using namespace std;

typedef long long ll;
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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N, M, X, Y;
char A[1010][1010], B[110][110];
int PI[1110][1110];
char T[1110];

void pf(int n, int k) {
    FOR(i, 0, n) PI[k][i] = 0;
    FOR(i, 1, n) {
        PI[k][i] = 0;
        int j = PI[k][i - 1];
        while (j > 0 && T[i] != T[j]) j = PI[k][j - 1];
        if (T[i] == T[j]) PI[k][i] = j + 1;
    }
}

void solve() {
    rii(N, M);
    FOR(i, 0, N) dadsadasda = scanf("%s", A[i]);
    rii(X, Y);
    FOR(i, 0, X) dadsadasda = scanf("%s", B[i]);

    int ans = 0;
    FOR(i, 0, N - X + 1) {

        FOR(j, i, i + X) {
            FOR(k, 0, Y) T[k] = B[j - i][k];
            T[Y] = '$';
            FOR(k, 0, M) T[Y + 1 + k] = A[j][k];
            pf(M + Y + 1, j);
        }

        FOR(k, 0, M) {
            int cnt = 0;
            FOR(j, i, i + X) {
                if (PI[j][Y + 1 + k] == Y) cnt = min(cnt + 1, X);
                else cnt = 0;

                ans += cnt == X;
            }
        }
    }

    printf("%d\n", ans);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}