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

using namespace std;

typedef long long ll;
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
const int MAXN = 2e5 + 2; // CAMBIAR ESTE

// GJNM
int R, G;

bool valid(int h) {
    int aux_r = R, aux_g = G;
    for (int i = h; i >= 1; i--) {
        if (aux_r >= i)
            aux_r -= i;
        else if (aux_g >= i)
            aux_g -= i;
        else
            return false;
    }
    return true;
}

int bs() {
    int lo = 1, hi = 1e3;
    while (lo < hi) {
        int mi = lo + (hi - lo + 1) / 2;
        if (valid(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    return lo;
}

int mx_h;
const int MOD = 1e9 + 7;
int dp[2][MAXN];


int main() {
    rii(R, G);
    if (R > G)
        swap(R, G);
    mx_h = bs();
    FOR(i, 0, MAXN) dp[0][i] = 1;
    for (int h = 1; h <= mx_h; h++) {
        int curr = h & 1;
        int prev = curr ^ 1;

        for (int r = 0; r <= R; r++) {
            int used = (mx_h * mx_h + mx_h) / 2 - (h * h + h) / 2;
            int g = G - (used - (R - r));
            dp[curr][r] = 0;
            if (r >= h)
                dp[curr][r] += dp[prev][r - h];
            if (g >= h)
                dp[curr][r] += dp[prev][r];
            if (dp[curr][r] >= MOD)
                dp[curr][r] -= MOD;
        }
    }
    printf("%d\n", dp[mx_h & 1][R]);
    return 0;
}