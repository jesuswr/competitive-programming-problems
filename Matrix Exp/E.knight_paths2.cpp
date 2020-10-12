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

struct Matrix { // struct para exp de matrices
    unsigned int m[65][65];

    Matrix() {
        FOR(i, 0, 65) {
            FOR(j, 0, 65) {
                m[i][j] = 0;
            }
        }
    }

    Matrix operator *(const Matrix &other) {
        Matrix prod;
        FOR(i, 0, 65) FOR(j, 0, 65) FOR(k, 0, 65) {
            prod.m[i][k] += m[i][j] * other.m[j][k];
        }
        return prod;
    }
};

Matrix bin_pow(Matrix x, int k) {
    Matrix prod;
    FOR(i, 0, 65) {
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

bool is_inside(int r, int c) {
    return (min(r, c) >= 0 && max(r, c) < 8);
}

int main() {
    int k; ri(k); k++;

    Matrix x;
    FOR(r, 0, 8) FOR(c, 0, 8) {
        for (int dr : {1, -1, 2, -2}) {
            for (int dc : {1, -1, 2, -2}) {
                if (abs(dr) + abs(dc) != 3)
                    continue;
                int new_r = r + dr, new_c = c + dc;
                if (!is_inside(new_r, new_c))
                    continue;
                x.m[8 * r + c][8 * new_r + new_c] = 1;
            }
        }
    }
    FOR(i, 0, 65) {
        x.m[i][64] = 1;
    }

    x = bin_pow(x, k);

    printf("%u\n", x.m[0][64]);


    return 0;
}