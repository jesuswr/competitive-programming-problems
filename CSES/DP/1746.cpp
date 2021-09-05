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
const int MAXN = 1e5 + 1; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
int X[MAXN];
int DP[MAXN][101];

int main() {
    rii(N, M);
    FOR(i, 0, N) ri(X[i]);
    for (int put = 1; put <= M; ++put) DP[N - 1][put] = (X[N - 1] == put || X[N - 1] == 0);
    for (int i = N - 2; i >= 0; --i) {
        for (int put = 1; put <= M; ++put) {
            if (X[i] != put && X[i] != 0)
                continue;
            int &ret = DP[i][put];
            ret = DP[i + 1][put];
            if (put + 1 <= M) {
                ret += DP[i + 1][put + 1];
                if (ret >= MOD)
                    ret -= MOD;
            }
            if (put - 1 >= 0) {
                ret += DP[i + 1][put - 1];
                if (ret >= MOD)
                    ret -= MOD;
            }
        }
    }
    int ans = 0;
    for (int put = 1; put <= M; ++put) {
        ans += DP[0][put];
        if (ans >= MOD)
            ans -= MOD;
    }
    printf("%d\n", ans);
    return 0;
}