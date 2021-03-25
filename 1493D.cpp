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
const ll MOD = 1e9 + 7;

// GJNM
vi PRIMES;
int SIEVE[MAXN];
void pre() {
    FOR(i, 2, MAXN) {
        if (SIEVE[i] == 0) {
            PRIMES.pb(i);
            int j = i;
            while (j < MAXN) {
                SIEVE[j] = i;
                j += i;
            }
        }
    }
}

multiset<int> EXPS[MAXN];
unordered_map<int, int> DESC[MAXN];

ll bpow(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e & 1) ret = (ret * b) % MOD;
        e >>= 1;
        b = (b * b) % MOD;
    }
    return ret;
}

int main() {
    pre();
    int N, Q;
    rii(N, Q);
    FOR(i, 0, N) {
        DESC[i].reserve(50);
        int a; ri(a);
        while (a > 1) {
            int div = SIEVE[a];
            int cnt = 0;
            while (a % div == 0) {
                ++cnt;
                a /= div;
            }
            EXPS[div].insert(cnt);
            DESC[i][div] = cnt;
        }
    }

    ll gcd = 1;
    for (auto p : PRIMES) {
        if (SZ(EXPS[p]) != N) continue;
        int exp = *EXPS[p].begin();
        gcd = (gcd * bpow(p, exp)) % MOD;
    }

    while (Q--) {
        int i, x;
        rii(i, x);
        --i;
        while (x > 1) {
            int div = SIEVE[x];
            int cnt = 0;
            while (x % div == 0) {
                ++cnt;
                x /= div;
            }

            int old = DESC[i][div];
            DESC[i][div] += cnt;

            if (EXPS[div].find(old) != EXPS[div].end())
                EXPS[div].erase(EXPS[div].find(old));
            EXPS[div].insert(DESC[i][div]);

            if (SZ(EXPS[div]) == N) {
                int mn = *EXPS[div].begin();
                gcd = (gcd * bpow(div, max(mn - old, 0))) % MOD;
            }
        }
        printf("%lld\n", gcd);
    }
    return 0;
}