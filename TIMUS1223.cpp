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
const int MAXN = 1001; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int E, F;

int LG[2 * MAXN];
void pre_log() {
    for (int i = 1; i < MAXN; ++i) {
        int p2 = 0;
        while ( (1 << p2) <= i) p2++;
        LG[i] = p2;
    }
}


int DP[MAXN][MAXN];
int go(int e, int f) {
    if (DP[e][f] != -1)
        return DP[e][f];
    if (f == 0)
        return DP[e][f] = 0;
    if (e == 0)
        return DP[e][f] = INF;
    DP[e][f] = INF;
    for (int nf = 1; nf <= f; ++nf)
        DP[e][f] = min(DP[e][f], 1 + max(go(e - 1, nf - 1), go(e, f - nf)));
    return DP[e][f];
}

int main() {
    pre_log();
    FOR(i, 0, MAXN) FOR(j, 0, MAXN) DP[i][j] = -1;
    while (rii(E, F), (E != 0 || F != 0)) {
        if (E >= 11)
            printf("%d\n", LG[F]);
        else
            printf("%d\n", go(E, F));
    }
    return 0;
}