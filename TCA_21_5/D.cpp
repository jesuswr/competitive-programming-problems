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
const int MAXN = 1e6; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
ll X, Y, P;
int A[MAXN];

const int n_states = 2;

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
            ret.mat[i][j] %= P;
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


ll go(ll sm, ll mn, ll mx, ll exp) {
    Matrix m(0);
    m.mat[0][0] = 3 % P;
    m.mat[1][0] = P - 1;
    m.mat[1][1] = 1;
    m = bin_exp(m, exp);
    return (sm * m.mat[0][0] + (mn + mx) * m.mat[1][0]) % P;
}

pair<ll, ll> fib(ll e) {
    Matrix m(0);
    m.mat[0][0] = m.mat[0][1] = m.mat[1][0] = 1;
    m = bin_exp(m, e);
    return {m.mat[0][0], m.mat[0][1]};
}

int main() {
    ri(N); rll(X, Y), rl(P);
    FOR(i, 0, N) ri(A[i]);
    ll sm = 0;
    FOR(i, 0, N) sm += A[i];
    sm = go(sm % P, A[0] % P, A[N - 1] % P, X);
    pair<ll, ll> f = fib(X);
    A[N - 1] = (A[N - 1] * f.F + A[N - 2] * f.S) % P;
    printf("%lld\n", go(sm % P, A[0] % P, A[N - 1] % P, Y));
    return 0;
}