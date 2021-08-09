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
const int MAXN = (1 << 10) + 1; // CAMBIAR ESTE
const ll MOD = 1000009183ll;

// GJNM
int N, E;
string M[MAXN];
ll A[MAXN][MAXN][11];
ll B[MAXN][MAXN];
ll P = 31;
ll PI = 129033443ll;
ll MEM_P[MAXN * MAXN], MEM_PI[MAXN * MAXN];

ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e > 0) {
        if (e & 1) ret = (ret * b) % MOD;
        e >>= 1;
        b = (b * b) % MOD;
    }
    return ret;
}

ll q1(int i, int j, int l) {
    ll ret = B[i][j + l - 1];
    if (j > 0) {
        ret -= B[i][j - 1];
        ret %= MOD;
        if (ret < 0)
            ret += MOD;
        ret *= MEM_PI[j];
        ret %= MOD;
    }
    return ret;
}

void pre() {
    MEM_P[0] = 1;
    MEM_PI[0] = 1;

    FOR(i, 1, MAXN * MAXN) {
        MEM_P[i] = (MEM_P[i - 1] * P) % MOD;
        MEM_PI[i] = (MEM_PI[i - 1] * PI) % MOD;
    }

    FOR(i, 0, N) FOR(j, 0, N) {
        if (j > 0) B[i][j] = B[i][j - 1];
        B[i][j] += (M[i][j] - 'a' + 1) * MEM_P[j];
        B[i][j] %= MOD;
    }

    for (int i = N - 1; i >= 0; -- i) {
        for (int j = N / 2 - 1; j >= 0; -- j) {
            A[i][j][0] = q1(i, j, N / 2);
            for (int b = 1; b <= E && max(i, j) + (1 << b) <= N; b++) {
                A[i][j][b] = MEM_P[(N / 2) * (1ll << (b - 1))];
                A[i][j][b] *= A[i + (1 << (b - 1))][j][b - 1];
                A[i][j][b] += A[i][j][b - 1];
                A[i][j][b] %= MOD;
            }
        }
    }
}

// devuelve true si la matriz en i2,j2 es menor
bool cmp(int i, int j, int i2, int j2) {
    if (A[i][j][E] == A[i2][j2][E])
        return false;

    int k = E;
    while (k >= 0) {
        if (A[i][j][k] == A[i2][j2][k]) {
            i += (1 << k);
            i2 += (1 << k);
        }
        --k;
    }

    int lo = 0, hi = N / 2 - 1;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (q1(i, j, mi + 1) == q1(i2, j2, mi + 1))
            lo = mi + 1;
        else
            hi = mi;
    }
    return M[i2][j2 + lo] < M[i][j + lo];
}

int main() {

    while (cin >> M[N]) {
        M[N] += M[N];
        ++N;
    }
    FOR(i, 0, N) M[N + i] = M[i];
    N <<= 1;

    int k = N;
    while (k > 1) {
        ++E;
        k >>= 1;
    }
    E -= 1;
    pre();

    pii bst = {0, 0};
    FOR(i, 0, N / 2) FOR(j, 0, N / 2) {
        if (cmp(bst.F, bst.S, i, j))
            bst = {i, j};
    }
    FOR(i, bst.F, bst.F + N / 2) FOR(j, bst.S, bst.S + N / 2) {
        printf("%c", M[i][j]);
        if (j == bst.S + N / 2 - 1)
            printf("\n");
    }

    return 0;
}