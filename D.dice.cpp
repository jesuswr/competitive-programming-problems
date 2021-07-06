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
const ll MOD = 1000000007;

// GJNM
ll N, K, M;
ll CNT[210];


const int n_states = 200;
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
        if (e & 1ll)
            prod = prod * b;
        b = b * b;
        e >>= 1;
    }
    return prod;
}

ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e & 1)
            ret = (ret * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ret;
}


int main() {
    rll(N, K), rl(M);

    ll inv = binpow(K - K / M, MOD - 2);
    FOR(i, 1, M + 1) {
        CNT[i] = K / M;
        if (i <= K % M) CNT[i]++;
    }
    Matrix m(0);
    FOR(i, 0, M) FOR(j, 0, M) {
        m.mat[i][(i + j) % M] = (CNT[j] * inv) % MOD;
    }

    printf("%lld\n", bin_exp(m, N).mat[0][0]);
    return 0;
}