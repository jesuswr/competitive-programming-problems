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

// GJNM
const int n_states = 2;

struct Matrix {
    double mat[n_states][n_states];
    Matrix(double val) {
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

Matrix bin_exp(Matrix b, int e) {
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
    int n; double p;
    scanf("%d %lF", &n, &p);

    // O(1) memory dp solution
    /*
    double happy = 1;
    double sad = 0;

    FOR(i, 0, n) {
        double new_happy = 0;
        double new_sad = 0;

        new_happy += happy * (1 - p);
        new_happy += sad * p;

        new_sad += happy * p;
        new_sad += sad * (1 - p);

        happy = new_happy;
        sad = new_sad;
    }
    printf("%lF\n", happy);
    */

    Matrix dp(0);

    dp.mat[0][0] = (1 - p);
    dp.mat[0][1] = p;
    dp.mat[1][0] = p;
    dp.mat[1][1] = (1 - p);

    dp = bin_exp(dp, n);
    printf("%lF\n", dp.mat[0][0]);

    return 0;
}