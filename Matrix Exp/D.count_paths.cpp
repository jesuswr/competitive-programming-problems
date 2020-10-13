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
const ll MOD = 1e9 + 7;

// GJNM
struct Matrix { // struct para exp de matrices
    ll m[100][100];
    Matrix() {
        FOR(i, 0, 100) {
            FOR(j, 0, 100) {
                m[i][j] = 0;
            }
        }
    }
    Matrix operator *(const Matrix &other) {
        Matrix prod;
        FOR(i, 0, 100) FOR(j, 0, 100) FOR(k, 0, 100) {
            prod.m[i][k] += m[i][j] * other.m[j][k];
            prod.m[i][k] %= MOD;
        }
        return prod;
    }

    ll sum() {
        ll acum = 0;
        FOR(i, 0, 100) {
            FOR(j, 0, 100) {
                acum = (acum + m[i][j]) % MOD;
            }
        }
        return acum;
    }
};

Matrix bin_pow(Matrix x, int k) {
    Matrix prod;
    FOR(i, 0, 100) {
        prod.m[i][i] = 1;
    }
    while (k > 0) {
        if (k & 1) {
            prod = prod * x;
        }
        x = x * x;
        k >>= 1;
    }
    return prod;
}

int main() {
    int n, mm, k;
    riii(n, mm, k);
    Matrix x;
    FOR(i, 0, mm) {
        int a, b; rii(a, b);
        x.m[a - 1][b - 1] = 1;
    }
    x = bin_pow(x, k);
    printf("%lld\n", x.sum());
    return 0;
}