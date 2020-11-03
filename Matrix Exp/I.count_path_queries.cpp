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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE
const ll mod = 1e9 + 7;

// GJNM
const int n_states = 200;
int n;

struct Matrix {
    ll mat[n_states][n_states];
    Matrix() {
    }
    Matrix(ll val) {
        FOR(i, 0, n) FOR(j, 0, n) {
            mat[i][j] = val;
        }
    }
    Matrix operator*(Matrix &other) {
        Matrix ret(0);
        FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) {
            ret.mat[i][j] += mat[i][k] * other.mat[k][j];
            if (ret.mat[i][j] >= mod * mod * 8)
                ret.mat[i][j] -= mod * mod * 8;
        }
        FOR(i, 0, n) FOR(j, 0, n) {
            ret.mat[i][j] %= mod;
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

Matrix all[32];

int main() {
    int m, q;
    riii(n, m, q);
    Matrix dp(0);
    FOR(i, 0, m) {
        int a, b;
        rii(a, b);
        dp.mat[a - 1][b - 1] = 1;
    }

    all[0] = dp;
    FOR(i, 1, 32) {
        all[i] = all[i - 1] * all[i - 1];
    }

    while (q--) {
        int s, t, k;
        riii(s, t, k);
        vector<ll> cnt(n, 0);
        cnt[s - 1] = 1;

        FOR(i, 0, 32) {
            if (k & (1 << i)) {
                vector<ll> new_cnt(n, 0);
                FOR(j, 0, n) {
                    if (cnt[j] == 0)
                        continue;
                    FOR(k, 0, n) {
                        new_cnt[k] += cnt[j] * all[i].mat[j][k];
                        new_cnt[k] %= mod;
                    }
                }
                swap(cnt, new_cnt);
            }
        }
        printf("%lld\n", cnt[t - 1]);
    }

    return 0;
}