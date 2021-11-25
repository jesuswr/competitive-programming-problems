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
const int MAXN = 1010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K, M;
ll P10K[MAXN];
ll P10M[MAXN];
void pre() {
    P10M[0] = 1 % M;
    FOR(i, 1, MAXN) P10M[i] = 10 * P10M[i - 1] % M;
    P10K[0] = 1 % K;
    FOR(i, 1, MAXN) P10K[i] = 10 * P10K[i - 1] % K;
}

ll DP[MAXN][110][2];
ll f(int p, int rst, int z) {
    if (DP[p][rst][z] != -1)
        return DP[p][rst][z];
    if (p == N)
        return DP[p][rst][z] = rst == 0;
    if (z == 1 && rst == 0)
        return DP[p][rst][z] = P10M[N - p - 1] * 9 % M;
    DP[p][rst][z] = 0;
    FOR(d, p + 1 == N, 10) DP[p][rst][z] = (DP[p][rst][z] + f(p + 1, (rst + P10K[p] * d) % K, z | (d != 0))) % M;
    return DP[p][rst][z];
}


int main() {
    memset(DP, -1, sizeof(DP));
    riii(N, K, M);
    pre();
    printf("%lld\n", f(0, 0, 0));
    return 0;
}