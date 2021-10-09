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
const ll MOD = 1e9;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
const int n_states = 1 << 8;

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
            if (ret.mat[i][j] >= MOD * MOD)
                ret.mat[i][j] %= MOD;
        }
        FOR(i, 0, n_states) FOR(j, 0, n_states) {
            if (ret.mat[i][j] >= MOD)
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


ll N, M;
int DP[1 << 8][1 << 8][8];
int f(int l, int r, int b) {
    if (b == N)
        return 1;
    if (b > N)
        return 0;
    if (DP[l][r][b] != -1)
        return DP[l][r][b];

    int l_b = l & 1, r_b = r & 1;
    if (l_b || r_b)
        return DP[l][r][b] = f(l >> 1, r >> 1, b + 1);
    int ret = f(l >> 1, r >> 1, b + 1);
    if (b + 1 < N) {
        l_b = (l >> 1) & 1, r_b = (r >> 1) & 1;
        if (!l_b && !r_b)
            ret += f(l >> 2, r >> 2, b + 2);
    }
    return DP[l][r][b] = ret;
}

int main() {
    memset(DP, -1, sizeof(DP));
    rll(N, M);

    Matrix dp(0);
    FOR(i, 0, 1 << N) FOR(j, 0, 1 << N) {
        if (i & j)
            continue;
        dp.mat[i][j] += f(i, j, 0);
    }
    dp = bin_exp(dp, M);
    printf("%lld\n", dp.mat[0][0]);

    return 0;
}