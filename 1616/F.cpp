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
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const int MAXN = 300; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
typedef int Long;
pair< Long, vector<Long> > Gauss_MOD_SLAE(vector< vector<Long> > &A, Long mod) {
    Long n = A.size();
    Long m = A[0].size() - 1;
    vector<Long> where(m, -1);
    for (Long col = 0, row = 0; col < m && row < n; col++) {
        Long sel = row;
        for (Long i = row; i < n; i++) {
            if (A[i][col] != 0) {
                sel = i;
                break;
            }
        }
        if (A[sel][col] == 0) continue;
        for (Long i = col; i <= m; i++) swap(A[sel][i], A[row][i]);
        where[col] = row;
        for (Long i = row + 1; i < n; i++) {
            Long c = (A[i][col] * A[row][col]) % mod;
            if (c == 0) continue;
            for (Long j = col; j <= m; j++) {
                A[i][j] -= (A[row][j] * c) % mod;
                A[i][j] %= mod;
                if (A[i][j] < 0) A[i][j] += mod;;
            }
        }
        row++;
    }

    vector<Long> X(m, 0);
    for (Long j = m - 1; j >= 0; j--) {
        if (where[j] != -1) {
            Long b = A[where[j]][m];
            for (Long k = m - 1; k > j; k--) {
                b -= (X[k] * A[where[j]][k]) % mod;
                b %= mod;
                if (b < 0) b += mod;
            }
            X[j] = (b * A[where[j]][j]) % mod;
        }
    }
    for (Long i = 0; i < n; i++) {
        Long sum = 0;
        for (Long j = 0; j < m; j++) {
            sum += (X[j] * A[i][j]) % mod;
            sum %= mod;
        }
        if (A[i][m] != sum) return make_pair(0, X);
    }
    for (Long i = 0; i < m; i++) {
        if (where[i] == -1) return make_pair(INF, X);
    }
    return make_pair(1, X);
}

int N, M;
int G[MAXN][MAXN];

void solve() {
    rii(N, M);
    FOR(i, 0, N)FOR(j, 0, N) G[i][j] = -1;

    vector<vector<Long>> A;

    FOR(i, 0, M) {
        int a, b, c; riii(a, b, c);
        G[a - 1][b - 1] = G[b - 1][a - 1] = i;
        if (c != -1) {
            A.pb(vector<Long>(M + 1));
            A.back()[i] = 1;
            A.back().back() = c - 1;
        }
    }


    FOR(x, 0, N) {
        FOR(y, x + 1, N) {
            FOR(z, y + 1, N) {
                if (G[x][y] != -1 && G[y][z] != -1 && G[z][x] != -1) {
                    A.pb(vector<Long>(M + 1));
                    A.back()[G[x][y]] = A.back()[G[x][z]] = A.back()[G[y][z]] = 1;
                }
            }
        }
    }
    if (A.empty()) {
        FOR(i, 0, M) printf("1 ");
        printf("\n");
        return;
    }


    auto [exist, ans] = Gauss_MOD_SLAE(A, 3);
    if (exist == 0)
        printf("-1\n");
    else {
        FOR(i, 0, M)printf("%d ", ans[i] + 1);
        printf("\n");
    }

}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}