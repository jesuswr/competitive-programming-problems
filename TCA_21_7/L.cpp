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
const int MAXN = 1e5; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, L;
pii P[100][2];

int DP[3690][100][2];
int f(int len, int lst, int rev) {
    if (DP[len][lst][rev] != -1)
        return DP[len][lst][rev];
    int &ret = DP[len][lst][rev] = 0;
    if (len >= L)
        return ret = len == L;
    FOR(i, 0, N) {
        if (i == lst) continue;

        if (P[lst][rev].S == P[i][0].F) {
            ret += f(len + P[i][0].F, i, 0);
            if (ret >= MOD)
                ret -= MOD;
        }
        if (P[i][0].F != P[i][0].S && P[lst][rev].S == P[i][1].F) {
            ret += f(len + P[i][1].F, i, 1);
            if (ret >= MOD)
                ret -= MOD;
        }
    }
    // printf("%d %d %d : %d\n", len, lst, rev, ret);
    return ret;
}

int main() {
    memset(DP, -1, sizeof(DP));
    rii(N, L);
    FOR(i, 0, N) {
        rii(P[i][0].F, P[i][0].S);
        P[i][1].F = P[i][0].S;
        P[i][1].S = P[i][0].F;
    }
    int ans = 0;
    FOR(i, 0, N) {
        ans += f(P[i][0].F, i, 0);
        if (ans >= MOD)
            ans -= MOD;
        if (P[i][0].F != P[i][0].S) {
            ans += f(P[i][1].F, i, 1);
            if (ans >= MOD)
                ans -= MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}