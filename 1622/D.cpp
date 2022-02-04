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
const int MAXN = 5010; // CAMBIAR ESTE
const int MOD = 998244353;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
string S;

int DP[MAXN][MAXN];
int pick(int n, int k) {
    if (k > n)
        return 0;
    if (DP[n][k] != 0)
        return DP[n][k];
    if (k == 0 || k == n)
        return DP[n][k] = 1;
    DP[n][k] = pick(n - 1, k) + pick(n - 1, k - 1);
    if (DP[n][k] >= MOD)
        DP[n][k] -= MOD;
    return DP[n][k];
}


int main() {
    rii(N, K);
    if (K == 0) {
        printf("1\n");
        return 0;
    }
    cin >> S;
    vector<pii> rs;
    int l = 0, r = -1;
    int cnt = 0;
    while (69) {
        while (r + 1 < N && cnt < K) {
            ++r;
            cnt += S[r] == '1';
        }
        if (cnt < K) break;
        while (r + 1 < N && S[r + 1] == '0') ++r;
        rs.pb({l, r});
        while (cnt == K) {
            cnt -= S[l] == '1';
            ++l;
        }
    }

    ll ans = 1;
    for (int i = 0; i < SZ(rs); ++i) {
        // printf("[%d, %d] (%d, %d) = %d\n", rs[i].F, rs[i].S, rs[i].S - rs[i].F + 1, K, pick(rs[i].S - rs[i].F + 1, K));
        ans = (ans + pick(rs[i].S - rs[i].F + 1, K) - 1) % MOD;
        if (i + 1 < SZ(rs)) {
            while (S[rs[i].F] == '0') rs[i].F++;
            ans = (ans - pick(rs[i].S - rs[i].F, K - 1) + 1 + MOD) % MOD;
        }
        // printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
    return 0;
}