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
const int MAXN = 1e7; // CAMBIAR ESTE

// GJNM
int N, Q;
ll A[MAXN];
ll DP[MAXN + 10];

int main() {
    rii(N, Q);
    FOR(i, 0, N) rl(A[i]);

    ll dp[N];
    FOR(i, 0, N) dp[i] = A[i];

    DP[1] = dp[0];
    for (int _ = 2; _ <= MAXN; ++_) {
        ll new_dp[N];
        FOR(i, 0, N) new_dp[i] = LLINF;
        FOR(i, 0, N - 1) new_dp[i] = min(new_dp[i], dp[i + 1] + 0);
        for (int i = 0; i < N; ++i)
            new_dp[N - 1] = min(new_dp[N - 1], dp[i] + A[N - 1 - i]);
        FOR(i, 0, N) dp[i] = new_dp[i];
        DP[_] = dp[0];
    }

    while (Q--) {
        ll k; rl(k);
        if (k <= MAXN) {
            printf("%lld\n", DP[k]);
        }
        else {
            ll ans = LLINF;
            for (ll i = 1; i <= N; ++i) {
                ll diff = k - MAXN;
                ll use = (diff + i - 1) / i;
                ans = min(ans, use * A[i - 1] + DP[k - use * i]);
            }
            printf("%lld\n", ans);
        }
    }



    return 0;
}