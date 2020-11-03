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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE
const ll mod = 1e9 + 7;

// GJNM
int n; ll k;
const int n_states = 13;
ll a[10], c[10], p, q, r;

struct Matrix {
    ll mat[n_states][n_states];
    Matrix(ll val) {
        FOR(i, 0, n_states) FOR(j, 0, n_states) {
            mat[i][j] = val;
        }
    }
    Matrix operator*(Matrix &other) {
        Matrix ret(0);
        FOR(k, 0, n_states) FOR(i, 0, n_states) FOR(j, 0, n_states) {
            ret.mat[i][j] += mat[i][k] * other.mat[k][j];
            ret.mat[i][j] %= mod;
        }
        return ret;
    }
};

Matrix bin_exp(Matrix b, ll e) {
    Matrix prod(0);
    FOR(i, 0, n_states) {
        prod.mat[i][i] = 1;
    }
    while (e > 0) {
        if (e & 1)
            prod = prod * b;
        b = b * b;
        e >>= 1;
    }
    return prod;
}





int main() {
    scanf("%d %lld", &n, &k);
    FOR(i, 0, n) {
        rl(a[i]);
    }
    FOR(i, 0, n) {
        rl(c[i]);
    }
    rl(p), rll(q, r);


    /* O(1) memory dp solution
        ll dp[13];
        FOR(i, 0, n) {
            dp[i] = a[i];
        }
        dp[10] = 1; // to add p
        dp[11] = n;
        dp[12] = n * n;

        FOR(_, 0, k) {
            ll new_dp[13];
            FOR(i, 0, 13) {
                new_dp[i] = 0;
            }

            FOR(i, 0, n - 1) {
                new_dp[i] += dp[i + 1] * 1;
            }

            FOR(i, 0, n) {
                new_dp[n - 1] += dp[n - 1 - i] * c[i];
            }

            new_dp[n - 1] += dp[10] * p;
            new_dp[n - 1] += dp[11] * q;
            new_dp[n - 1] += dp[12] * r;

            new_dp[10] += dp[10] * 1;

            new_dp[11] += dp[11] * 1;
            new_dp[11] += dp[10] * 1;

            new_dp[12] += dp[12] * 1;
            new_dp[12] += dp[11] * 2;
            new_dp[12] += dp[10] * 1;

            FOR(i, 0, 13) {
                dp[i] = new_dp[i];
            }
        }

        printf("%lld\n", dp[0]);
    */

    Matrix dp(0);
    FOR(i, 0, n - 1) {
        dp.mat[i + 1][i] = 1;
    }
    FOR(i, 0, n) {
        dp.mat[n - 1 - i][n - 1] = c[i];
    }

    dp.mat[10][n - 1] = p;
    dp.mat[11][n - 1] = q;
    dp.mat[12][n - 1] = r;

    dp.mat[10][10] = 1;

    dp.mat[11][11] = 1;
    dp.mat[10][11] = 1;

    dp.mat[12][12] = 1;
    dp.mat[11][12] = 2;
    dp.mat[10][12] = 1;

    dp = bin_exp(dp, k);

    ll ans = 0;
    FOR(i, 0, n) {
        ans = (ans + a[i] * dp.mat[i][0]) % mod;
    }
    ans = (ans + 1 * dp.mat[10][0]) % mod;
    ans = (ans + n * dp.mat[11][0]) % mod;
    ans = (ans + n * n * dp.mat[12][0]) % mod;


    printf("%lld\n", ans);

    return 0;
}