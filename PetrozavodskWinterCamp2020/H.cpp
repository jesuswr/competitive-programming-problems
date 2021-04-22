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
const int MAXN = 310; // CAMBIAR ESTE

// GJNM
int N, M;
double X[MAXN], Y[MAXN];
bool G[MAXN][MAXN];

double dist(int i, int j) {
    double dx = X[i] - X[j];
    double dy = Y[i] - Y[j];
    return sqrt(dx * dx + dy * dy);
}

bool VIS[MAXN][MAXN][2];
double DP[MAXN][MAXN][2];
double f(int c, int l, int d) {
    if (VIS[c][l][d]) return DP[c][l][d];
    VIS[c][l][d] = true;
    double ret = 0;
    if (d == 0) {
        for (int nxt = l; nxt != c; nxt = (nxt + 1) % N) {
            if (G[c][nxt]) {
                ret = max({
                    ret,
                    dist(c, nxt) + f(nxt, l, d),
                    dist(c, nxt) + f(nxt, (c - 1 + N) % N, 1)
                });
            }
        }
    }
    else {
        for (int nxt = l; nxt != c; nxt = (nxt - 1 + N) % N) {
            if (G[c][nxt]) {
                ret = max({
                    ret,
                    dist(c, nxt) + f(nxt, l, d),
                    dist(c, nxt) + f(nxt, (c + 1 + N) % N, 0)
                });
            }
        }
    }
    return DP[c][l][d] = ret;
}

void solve() {
    memset(VIS, false, sizeof(VIS));
    ri(N);
    FOR(i, 0, N) dadsadasda = scanf("%lF %lF", X + i, Y + i);
    FOR(i, 0, N) FOR(j, 0, N) G[i][j] = false;
    ri(M);
    FOR(i, 0, M) {
        int a, b; rii(a, b); --a, --b;
        G[a][b] = G[b][a] = true;
    }
    double mx = 0;
    FOR(i, 0, N) {
        mx = max(mx, f(i, (i + 1) % N, 0));
    }
    printf("%.10lF\n", mx);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}