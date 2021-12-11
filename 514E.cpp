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
const int MAXN = 1e5; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

const int n_states = 101;

struct Matrix {
    ll mat[n_states][n_states];
    Matrix(ll val) {
        FOR(i, 0, n_states) FOR(j, 0, n_states) {
            mat[i][j] = val;
        }
    }
    Matrix operator*(Matrix &other) {
        Matrix ret(0);
        FOR(i, 0, n_states) FOR(k, 0, n_states) FOR(j, 0, n_states) {
            ret.mat[i][j] += mat[i][k] * other.mat[k][j];
            if (ret.mat[i][j] >= MOD * MOD * 8)
                ret.mat[i][j] -= MOD * MOD * 8;
        }
        FOR(i, 0, n_states) FOR(j, 0, n_states) {
            ret.mat[i][j] %= MOD;
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
    int n, x;
    rii(n, x);
    vi cnt(101);
    FOR(i, 0, n) {
        int a; ri(a);
        cnt[a]++;
    }

    vector<ll> dp(101);
    dp[0] = 1;
    FOR(i, 1, 100) {
        FOR(j, 0, 101) if (i - j >= 0) {
            dp[i] = (dp[i] + cnt[j] * dp[i - j]) % MOD;
        }
    }

    Matrix m(0);
    FOR(i, 1, 100) m.mat[i][i - 1] = 1;
    FOR(i, 1, 101) m.mat[99 - i + 1][99] += cnt[i];
    m.mat[0][100] = 1;
    m.mat[100][100] = 1;

    m = bin_exp(m, x + 1);

    ll ans = 0;
    FOR(i, 0, n_states) ans = (ans + dp[i] * m.mat[i][100]) % MOD;
    printf("%lld\n", ans);

    // ll ans = 0;
    // FOR(_, 0, x + 1) {
    //     vector<ll> new_dp(100);

    //     FOR(i, 1, 100) new_dp[i - 1] = dp[i];

    //     FOR(i, 1, 101) {
    //         new_dp[99] += cnt[i] * dp[99 - i + 1];
    //         new_dp[99] %= MOD;
    //     }

    //     ans = ans + dp[0];
    //     ans %= MOD;

    //     swap(dp, new_dp);
    // }
    // printf("%lld\n", ans);


    return 0;
}