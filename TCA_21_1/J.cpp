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
const int MAXN = 110; // CAMBIAR ESTE
const int MAXM = 10010; // CAMBIAR ESTE

// GJNM
int N, M;

vi SH[MAXN];

int PRE_DP[MAXN][MAXN];
int AUX_DP[MAXN][MAXN];
void pre_calc(int a) {
    FOR(i, 0, MAXN) FOR(j, 0, MAXN) AUX_DP[i][j] = 1e9;

    int SM = 0;
    FOR(i, 0, SZ(SH[a])) {
        SM += SH[a][i];
        AUX_DP[i][0] = 0;
        AUX_DP[i][1] = SH[a][i];
        int j = 2;
        while (i - j + 1 >= 0) {
            AUX_DP[i][j] = SH[a][i] + AUX_DP[i - 1][j - 1];
            ++j;
        }
    }

    FOR(i, 0, SZ(SH[a])) {
        FOR(j, 0, i + 2) {
            PRE_DP[a][SZ(SH[a]) - j] = max(PRE_DP[a][SZ(SH[a]) - j], SM - AUX_DP[i][j]);
        }
    }
}

int DP[MAXN][MAXM];
int f(int p, int l) {
    if (DP[p][l] != -1)
        return DP[p][l];
    if (p >= N)
        return 0;

    DP[p][l] = 0;
    for (int t = 0; t <= min(SZ(SH[p]), l); ++t) {
        DP[p][l] = max(DP[p][l], PRE_DP[p][t] + f(p + 1, l - t));
    }
    return DP[p][l];
}

int main() {
    memset(DP, -1, sizeof(DP));
    rii(N, M);
    FOR(i, 0, N) {
        int n; ri(n);
        FOR(_, 0, n) {
            int aux; ri(aux);
            SH[i].pb(aux);
        }
        pre_calc(i);
    }

    printf("%d\n", f(0, M));

    return 0;
}