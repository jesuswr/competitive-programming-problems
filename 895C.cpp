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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
int N;
int A[MAXN];
vi Ps;
int CNT[75];
ll DP[1 << 19], NEW_DP[1 << 19];
ll FACT[MAXN];
ll INVFACT[MAXN];

ll bpow(ll b, ll e) {
    ll ret = 1;
    while (e > 0) {
        if (e & 1) ret = (ret * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ret;
}

ll pick(int n, int k) {
    if (k > n) return 0;
    return (FACT[n] * ((INVFACT[k] * INVFACT[n - k]) % MOD)) % MOD;
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 2, 70) {
        bool good = true;
        FOR(d, 2, i) good &= i % d != 0;
        if (good) Ps.pb(i);
    }
    FACT[0] = 1;
    FOR(i, 1, N + 1) FACT[i] = (FACT[i - 1] * i) % MOD;
    INVFACT[N] = bpow(FACT[N], MOD - 2);
    for (int i = N - 1; i >= 0; --i) INVFACT[i] = (INVFACT[i + 1] * (i + 1)) % MOD;
    FOR(i, 0, N) CNT[A[i]]++;
    DP[0] = 1;
    FOR(n, 1, 71) {
        int msk = 0;
        FOR(i, 0, SZ(Ps)) {
            int aux_n = n;
            int cnt = 0;
            while (aux_n % Ps[i] == 0) {
                aux_n /= Ps[i];
                cnt++;
            }
            if (cnt & 1) msk |= (1 << i);
        }
        ll odd = 0, even = 0;
        FOR(c, 0, CNT[n] + 1) {
            if (c & 1) {
                odd = odd + pick(CNT[n], c);
                if (odd >= MOD) odd -= MOD;
            }
            else {
                even = even + pick(CNT[n], c);
                if (even >= MOD) even -= MOD;
            }
        }
        FOR(i, 0, 1 << 19) NEW_DP[i] = (DP[i] * even + DP[i ^ msk] * odd) % MOD;
        FOR(i, 0, 1 << 19) DP[i] = NEW_DP[i];
    }
    printf("%lld\n", DP[0] - 1);

    return 0;
}