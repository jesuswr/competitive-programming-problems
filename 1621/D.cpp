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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
ll MAT[400][400];


void solve() {
    ri(N);
    FOR(i, 0, 2 * N) FOR(j, 0, 2 * N) rl(MAT[i][j]);
    ll ans = 0;
    FOR(i, N, 2 * N) FOR(j, N, 2 * N) ans += MAT[i][j];
    ans += min({MAT[N][0], MAT[N][N - 1], MAT[0][N], MAT[N][N - 1], MAT[2 * N - 1][0], MAT[2 * N - 1][N - 1], MAT[0][2 * N - 1], MAT[N - 1][2 * N - 1]});
    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--)solve();
    return 0;
}