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
    ll m[2][2] = {{0, 0}, {0, 0}};
    Matrix operator *(const Matrix &other) {
        Matrix prod;
        FOR(i, 0, 2) FOR(j, 0, 2) FOR(k, 0, 2) {
            prod.m[i][k] += m[i][j] * other.m[j][k];
            prod.m[i][k] %= MOD;
        }
        return prod;
    }
};

Matrix bin_pow(Matrix x, ll k) {
    Matrix prod;
    FOR(i, 0, 2) {
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
    ll n;
    rl(n);
    Matrix x;
    x.m[0][0] = 0;
    x.m[0][1] = 1;
    x.m[1][0] = 1;
    x.m[1][1] = 1;
    x = bin_pow(x, n);
    printf("%lld\n", x.m[0][1] );



    return 0;
}