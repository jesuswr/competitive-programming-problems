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
const int MAXN = 1e6 + 1; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int DP[MAXN][3];

int main() {
    DP[1][1] = 1; DP[1][0] = 1; DP[1][2] = 2;
    for (int i = 2; i < MAXN; ++i) {
        DP[i][0] = (4ll * DP[i - 1][0] + DP[i - 1][1]) % MOD;
        DP[i][1] = (DP[i - 1][0] + 2ll * DP[i - 1][1]) % MOD;
        DP[i][2] = (DP[i][0] + DP[i][1]) % MOD;
    }
    int t; ri(t);
    while (t--) {
        int n; ri(n);
        printf("%d\n", DP[n][2]);
    }
    return 0;
}