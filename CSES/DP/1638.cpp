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
const int MOD = 1e9 + 7;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
char M[MAXN][MAXN];
int DP[MAXN][MAXN];

bool valid(int r, int c) {
    return max(r, c) < N && M[r][c] != '*';
}

int main() {
    ri(N);
    FOR(i, 0, N) dadsadasda = scanf("%s", M[i]);

    DP[N - 1][N - 1] = valid(N - 1, N - 1);
    for (int r = N - 1; r >= 0; --r) for (int c = N - 1; c >= 0; --c) {
            if (!valid(r, c))
                continue;
            if (valid(r + 1, c))
                DP[r][c] += DP[r + 1][c];
            if (valid(r, c + 1))
                DP[r][c] += DP[r][c + 1];
            if (DP[r][c] >= MOD)
                DP[r][c] -= MOD;
        }
    printf("%d\n", DP[0][0]);
    return 0;
}