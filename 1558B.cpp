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
#include <random>
#include <chrono>

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
const int MAXN = 4e6 + 10; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int n, MOD;
int dp[MAXN];
int carry[MAXN];

int main() {
    rii(n, MOD);
    dp[1] = 1;
    int prv = 1;
    int crry = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i] += prv;
        if (dp[i] >= MOD) dp[i] -= MOD;

        {
            carry[i] += dp[1];
            if (carry[i] >= MOD) carry[i] -= MOD;
            if (i + i <= n) {
                carry[i + i] -= dp[1];
                if (carry[i + i] < 0) carry[i + i] += MOD;
            }
        }

        crry += carry[i];
        if (crry >= MOD) crry -= MOD;

        dp[i] += crry;
        if (dp[i] >= MOD) dp[i] -= MOD;

        prv += dp[i];
        if (prv >= MOD) prv -= MOD;

        int j = i + i;
        while (j <= n) {
            if (j / i <= i) {
                carry[j] += dp[j / i];
                if (carry[j] >= MOD) carry[j] -= MOD;
                if (j + i <= n) {
                    carry[j + i] -= dp[j / i];
                    if (carry[j + i] < 0) carry[j + i] += MOD;
                }
            }
            j += i;
        }
        j = i + i;
        while (j <= n) {
            if (j / i < i) {
                carry[j] += dp[i];
                if (carry[j] >= MOD) carry[j] -= MOD;
                if (j + j / i <= n) {
                    carry[j + j / i] -= dp[i];
                    if (carry[j + j / i] < 0) carry[j + j / i] += MOD;
                }
            }
            j += i;
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}