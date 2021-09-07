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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
ll A[MAXN];
ll DP[MAXN][MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) {
        rl(A[i]);
        if (i > 0) A[i] += A[i - 1];
    }
    for (int len = 1; len <= N; ++len) {
        for (int l = 0; l + len - 1 < N; ++l) {
            int r = l + len - 1;
            ll sm = A[r] - (l > 0 ? A[l - 1] : 0);
            if (l == r)
                DP[l][r] = sm;
            else
                DP[l][r] = max(sm - DP[l + 1][r], sm - DP[l][r - 1]);
        }
    }
    printf("%lld\n", DP[0][N - 1]);
    return 0;
}