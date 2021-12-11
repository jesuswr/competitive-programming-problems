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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM



const int n_states = 50;
int n;

struct Matrix {
    ll mat[n_states][n_states];
    Matrix(ll val) {
        FOR(i, 0, n) FOR(j, 0, n) {
            mat[i][j] = val;
        }
    }
    Matrix operator*(Matrix &other) {
        Matrix ret(LLINF);
        FOR(i, 0, n) FOR(k, 0, n) FOR(j, 0, n) {
            ret.mat[i][j] = min(ret.mat[i][j], mat[i][k] + other.mat[k][j]);
        }
        return ret;
    }
};

Matrix bin_exp(Matrix b, ll e) {
    Matrix prod(LLINF);
    FOR(i, 0, n) prod.mat[i][i] = 0;
    while (e > 0) {
        if (e & 1)
            prod = prod * b;
        b = b * b;
        e >>= 1;
    }
    return prod;
}




void solve() {
    int e; rii(e, n);
    Matrix dp(0);
    FOR(i, 0, n) FOR(j, 0, n) rl(dp.mat[i][j]);
    FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) dp.mat[i][j] = min(dp.mat[i][j], dp.mat[i][k] + dp.mat[k][j]);
    ;
    dp = bin_exp(dp, e);
    FOR(i, 0, n) {
        FOR(j, 0, n) printf("%lld ", dp.mat[i][j]);
        printf("\n");
    }
}


int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Region #%d:\n", i);
        solve();
    }
    return 0;
}