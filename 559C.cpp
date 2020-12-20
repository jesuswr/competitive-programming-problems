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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
const int MOD = 1e9 + 7;

// GJNM
int R, C, N;
int DP[2010];
pii A[2010];
int FACT[MAXN];
int INVF[MAXN];

int bpow(int b, int e) {
    int ret = 1;
    while (e) {
        if (e & 1)
            ret = (1ll * ret * b) % MOD;

        b = (1ll * b * b) % MOD;
        e >>= 1;
    }
    return ret;
}

void precomp() {
    FACT[0] = INVF[0] = 1;
    FOR(i, 1, MAXN) FACT[i] = (1ll * FACT[i - 1] * i) % MOD;
    FOR(i, 1, MAXN) INVF[i] = bpow(FACT[i], MOD - 2) % MOD;
}

int pick(int n, int k) {
    return (1ll * FACT[n] * ((1ll * INVF[k] * INVF[n - k]) % MOD)) % MOD;
}

int main() {
    precomp();
    riii(R, C, N);
    FOR(i, 0, N) rii(A[i].F, A[i].S);
    A[N].F = R, A[N].S = C;
    N++;
    sort(A, A + N);

    for (int i = 0; i < N; i++) {
        DP[i] = pick(A[i].F + A[i].S - 2, A[i].F - 1);
        for (int j = 0; j < i; j++) {
            if (A[j].S <= A[i].S) {
                DP[i] -= (1ll * DP[j] * pick(A[i].F + A[i].S - A[j].F - A[j].S, A[i].F - A[j].F)) % MOD;
                DP[i] %= MOD;
            }
            DP[i] = (DP[i] + MOD) % MOD;
        }
    }
    printf("%d\n", DP[N - 1]);
    return 0;
}