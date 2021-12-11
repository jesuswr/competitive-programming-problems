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
const int MAXN = 3010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

int N;
int A[MAXN];
ll DP[MAXN][MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, MAXN) FOR(j, 0, MAXN) DP[i][j] = -LLINF;
    DP[N - 1][1] = A[N - 1];

    for (int p = N - 1; p >= 0; --p) {
        for (int s = 1; s < N; ++s) {
            //printf("%d %d : %lld\n", p, s, DP[p][s]);
            if (p - s >= 0) {
                DP[p - s][s] = max(DP[p - s][s], DP[p][s] + A[p - s]);
                //printf("\t%d %d : %lld\n", p - s, s, DP[p - s][s]);
            }
            if (s + 1 < N) {
                DP[p][s + 1] = max(DP[p][s + 1], DP[p][s]);
                //printf("\t\t%d %d : %lld\n", p, s + 1, DP[p][s + 1]);
            }
        }
    }

    ll mx = -LLINF;
    FOR(i, 1, N) mx = max(mx, DP[0][i]);
    printf("%lld\n", mx);

    return 0;
}