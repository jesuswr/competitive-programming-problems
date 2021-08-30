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
const int MAXN = 120; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int D[MAXN][MAXN];

int main() {
    int N, L, Q;
    riii(N, L, Q);
    FOR(i, 0, N) FOR(j, 0, N) D[i][j] = (i == j ? 0 : INF);
    FOR(_, 0, L) {
        int a, b, c; riii(a, b, c); --a, --b;
        D[a][b] = min(D[a][b], c);
        D[b][a] = min(D[b][a], c);
    }
    FOR(k, 0, N) FOR(i, 0, N) FOR(j, 0, N) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    while (Q--) {
        int a, b; rii(a, b);
        printf("%d\n", D[a - 1][b - 1]);
    }

    return 0;
}