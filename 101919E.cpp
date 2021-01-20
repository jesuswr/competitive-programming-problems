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

using namespace std;

typedef long long ll;
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
const int MAXN = 2010; // CAMBIAR ESTE

// GJNM
int M;
long double PL[MAXN], PR[MAXN];
long double DP[MAXN][MAXN][2];
bool VIS[MAXN][MAXN][2];

long double f(int l, int r, int s, long double acum = 0.0) {
    if (l == M && r == M) return 0;
    if (VIS[l][r][s]) return DP[l][r][s];
    VIS[l][r][s] = true;

    long double &ret = DP[l][r][s] = LLINF;
    long double xl = PL[l] / (1 - acum);
    long double xr = PR[r] / (1 - acum);
    if (s == 0) {
        if (l < M) ret = min(ret, 1 + (1 - xl) * f(l + 1, r, 0, acum + PL[l]));
        if (r < M) ret = min(ret, l + r + 1 + (1 - xr) * f(l, r + 1, 1, acum + PR[r]));
    }
    else {
        if (l < M) ret = min(ret, l + r + 1 + (1 - xl) * f(l + 1, r, 0, acum + PL[l]));
        if (r < M) ret = min(ret, 1 + (1 - xr) * f(l, r + 1, 1, acum + PR[r]));
    }
    return ret;
}


int main() {
    ri(M);
    FOR(i, 0, M) dadsadasda = scanf("%Lf", PL + i);
    reverse(PL, PL + M);
    FOR(i, 0, M) dadsadasda = scanf("%Lf", PR + i);
    long double acum = 0;
    FOR(i, 0, M) acum += PL[i] + PR[i];
    printf("%.6Lf\n", f(0, 0, 1));
    return 0;
}