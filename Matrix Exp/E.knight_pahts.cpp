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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE
const ll MOD = 4294967296ll;

// GJNM
unsigned int G[64][64];


const int n_states = 65;

struct Matrix {
    unsigned int mat[n_states][n_states];
    Matrix(unsigned int val) {
        FOR(i, 0, n_states) FOR(j, 0, n_states) {
            mat[i][j] = val;
        }
    }
    Matrix operator*(Matrix &other) {
        Matrix ret(0);
        FOR(k, 0, n_states) FOR(i, 0, n_states) FOR(j, 0, n_states) {
            ret.mat[i][j] += mat[i][k] * other.mat[k][j];
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
    int k; ri(k);

    FOR(i, 0, 8) FOR(j, 0, 8) FOR(i2, 0, 8) FOR(j2, 0, 8) {
        if (abs(i - i2) == 1 && abs(j - j2) == 2)
            G[8 * i + j][8 * i2 + j2] = 1;
        if (abs(i - i2) == 2 && abs(j - j2) == 1)
            G[8 * i + j][8 * i2 + j2] = 1;
    }

    /* O(1) memory dp sol
        // in dp you have the paths of current lenght
        // in ans you have the paths of prev lenghts

        unsigned int dp[64];
        FOR(i, 0, 64) {
            dp[i] = 0;
        }
        unsigned int ans = 0;
        dp[0] = 1;
        FOR(l, 0, k + 1) {
            unsigned int new_dp[64];
            FOR(i, 0, 64) {
                new_dp[i] = 0;
            }
            unsigned int new_ans = 0;

            FOR(i, 0, 64) FOR(j, 0, 64) {
                new_dp[i] += dp[j] * G[j][i];
            }

            FOR(i, 0, 64) {
                new_ans += dp[i];
            }
            new_ans += ans;

            FOR(i, 0, 64) {
                dp[i] = new_dp[i] * 1;
            }
            ans = new_ans;
        }
        printf("%u\n", ans);
    */

    Matrix dp(0);
    FOR(i, 0, 64) FOR(j, 0, 64) {
        dp.mat[i][j] = G[i][j];
    }
    FOR(i, 0, 65) {
        dp.mat[i][64] = 1;
    }

    dp = bin_exp(dp, k + 1);
    printf("%u\n", dp.mat[0][64]);

    return 0;
}