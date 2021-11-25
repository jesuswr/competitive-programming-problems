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
const int MAXV = 1010;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
pii A[MAXN];
int DP[MAXV][MAXV];
void build() {
    FOR(i, 0, MAXV) FOR(j, 0, MAXV) {
        if (i > 0)
            DP[i][j] += DP[i - 1][j];
        if (j > 0)
            DP[i][j] += DP[i][j - 1];
        if (i > 0 && j > 0)
            DP[i][j] -= DP[i - 1][j - 1];
    }
}
ll query(int a, int b, int c, int d) {
    int ret = DP[c][d];
    if (a > 0)
        ret -= DP[a - 1][d];
    if (b > 0)
        ret -= DP[c][b - 1];
    if (a > 0 && b > 0)
        ret += DP[a - 1][b - 1];
    // cout << ret << endl;
    return ret;
}

int main() {
    ri(N);
    FOR(i, 0, N) {
        rii(A[i].F, A[i].S);
        DP[A[i].F][A[i].S]++;
    }
    build();
    ll ans = 0;
    FOR(i, 0, N)
    ans += 1ll * query(0, 0, A[i].F - 1, A[i].S - 1) * query(A[i].F + 1, A[i].S + 1, MAXV - 1, MAXV - 1);
    printf("%lld\n", ans);
    return 0;
}