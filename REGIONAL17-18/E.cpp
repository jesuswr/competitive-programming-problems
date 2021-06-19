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

// GJNM
int N, MOD;
char A[MAXN];
ll POW10[MAXN];
bool VIS[MAXN][MAXN];
char NXT[MAXN][MAXN];
int NXTRST[MAXN][MAXN];
bool DP[MAXN][MAXN];

bool f(int p, int rst) {
    if (p == N)
        return rst == 0;
    if (VIS[p][rst])
        return DP[p][rst];
    VIS[p][rst] = true;

    if (A[p] != '?') {
        NXT[p][rst] = A[p];
        NXTRST[p][rst] = (1ll * rst + POW10[N - 1 - p] * (A[p] - '0')) % MOD;
        return DP[p][rst] = f(p + 1, (1ll * rst + POW10[N - 1 - p] * (A[p] - '0')) % MOD);
    }
    for (int i = (p == 0); i < 10; ++i) {
        if (f(p + 1, (1ll * rst + POW10[N - 1 - p]*i) % MOD)) {
            NXT[p][rst] = i + '0';
            NXTRST[p][rst] = (1ll * rst + POW10[N - 1 - p] * i) % MOD;
            return DP[p][rst] = true;
        }
    }
    return DP[p][rst] = false;
}

int main() {
    dadsadasda = scanf("%s %d", A, &MOD);
    N = strlen(A);

    POW10[0] = 1;
    for (int i = 1; i < MAXN; ++i) POW10[i] = (POW10[i - 1] * 10ll) % MOD;

    if (!f(0, 0)) {
        printf("*\n");
        return 0;
    }
    int p = 0, rst = 0;
    while (p < N) {
        printf("%c", NXT[p][rst]);
        rst = NXTRST[p][rst];
        ++p;
    }
    printf("\n");
    return 0;
}