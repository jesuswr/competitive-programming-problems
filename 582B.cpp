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

const int INF = 1e9 + 1e8;
const ll LLINF = 1e18;
const int MAXN = 110; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, T;
int A[MAXN];

const int n_states = 100;

struct Matrix {
    ll mat[n_states][n_states];
    Matrix(ll val) {
        FOR(i, 0, n_states) FOR(j, 0, n_states) {
            mat[i][j] = val;
        }
    }
    Matrix operator*(Matrix &other) {
        Matrix ret(-INF);
        FOR(i, 0, n_states) FOR(k, 0, n_states) FOR(j, 0, n_states) {
            ret.mat[i][j] = max(ret.mat[i][j], mat[i][k] + other.mat[k][j]);
        }
        return ret;
    }
};

Matrix bin_exp(Matrix b, ll e) {
    Matrix prod(-INF);
    FOR(i, 0, N)FOR(j, 0, N) prod.mat[i][j] = 0;
    while (e > 0) {
        if (e & 1)
            prod = prod * b;
        b = b * b;
        e >>= 1;
    }
    return prod;
}


int main() {
    rii(N, T);
    FOR(i, 0, N) ri(A[i]);

    Matrix dp(-INF);
    FOR(s, 0, N) FOR(t, 0, N) {
        if (A[s] > A[t])
            dp.mat[s][t] = -INF;
        else {
            dp.mat[s][t] = 1;
            FOR(i, 0, t) if (A[i] <= A[t])
                dp.mat[s][t] = max(dp.mat[s][t], dp.mat[s][i] + 1);
        }
    }
    dp = bin_exp(dp, T);
    ll ans = 0;
    FOR(i, 0, N) FOR(j, 0, N) ans = max(ans, dp.mat[i][j]);
    printf("%lld\n", ans);

    return 0;
}