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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 1e9 + 10;
const ll LLINF = 4e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
ll G[100][100];

const int n_states = 100;

struct Matrix {
    ll mat[n_states][n_states];
    Matrix(ll val) {
        FOR(i, 0, n_states) FOR(j, 0, n_states) {
            mat[i][j] = val;
        }
    }
    Matrix operator*(Matrix &other) {
        Matrix ret(LLINF);
        FOR(k, 0, n_states) FOR(i, 0, n_states) FOR(j, 0, n_states) {
            ret.mat[i][j] = min(ret.mat[i][j], mat[i][k] + other.mat[k][j]);
        }
        return ret;
    }
    ll get_ans() {
        ll ret = LLINF;
        FOR(i, 0, n_states) FOR(j, 0, n_states) {
            ret = min(ret, mat[i][j]);
        }
        return ret;
    }
};

Matrix bin_exp(Matrix b, ll e) {
    Matrix prod(0);
    while (e > 0) {
        if (e & 1)
            prod = prod * b;
        b = b * b;
        e >>= 1;
    }
    return prod;
}

int main() {
    int n, m, k; riii(n, m, k);
    FOR(i, 0, n) FOR(j, 0, n) {
        G[i][j] = LLINF;
    }
    FOR(i, 0, m) {
        int a, b, c; riii(a, b, c);
        G[a - 1][b - 1] = c;
    }

    /* O(1) memory dp
    ll dp[100];
    FOR(i, 0, n) {
        dp[i] = 0;
    }
    FOR(_, 0, k) {
        ll new_dp[100];
        FOR(i, 0, n) {
            new_dp[i] = LLINF;
        }

        FOR(i, 0, n) FOR(j, 0, n) {
            new_dp[i] = min(new_dp[i], dp[j] + G[j][i]);
        }

        FOR(i, 0, n) {
            dp[i] = new_dp[i];
        }
    }
    ll ans = LLINF;
    FOR(i, 0, n) {
        ans = min(ans, dp[i]);
    }
    printf("%lld\n", (ans > (ll)(1e18) ? -1 : ans));
    */

    Matrix dp(LLINF);
    FOR(i, 0, n) FOR(j, 0, n) {
        dp.mat[i][j] = G[i][j];
    }
    dp = bin_exp(dp, k);
    ll ans = dp.get_ans();
    if (ans >= (LLINF >> 1))
        printf("IMPOSSIBLE\n");
    else
        printf("%lld\n", ans);

    return 0;
}