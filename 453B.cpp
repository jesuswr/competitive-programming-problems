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
const int MAXN = 102; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];
const vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int DP[MAXN][1 << 16];
int MSK[60];
int NXT[MAXN][1 << 16];
int NXT_MSK[MAXN][1 << 16];

int f(int p, int msk) {
    if (p == N) return 0;
    if (DP[p][msk] != -1) return DP[p][msk];
    int &ret = DP[p][msk] = INF;
    FOR(k, 1, 2*A[p]) {
        if (MSK[k] & msk) continue;
        if (ret > abs(k - A[p]) + f(p + 1, msk | MSK[k])) {
            ret = abs(k - A[p]) + f(p + 1, msk | MSK[k]);
            NXT[p][msk] = k;
            NXT_MSK[p][msk] = MSK[k];
        }
    }
    return ret;
}


int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(k, 2, 59) FOR(i, 0, SZ(primes)) if (k % primes[i] == 0) MSK[k] |= (1 << i);
    memset(DP, -1, sizeof(DP));
    f(0, 0);
    int p = 0, msk = 0;
    while (p != N) {
        printf("%d ", NXT[p][msk]);
        msk = msk | NXT_MSK[p][msk];
        p++;
    }
    printf("\n");
    return 0;
}