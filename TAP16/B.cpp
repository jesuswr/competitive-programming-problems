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
const int MAXN = 4e3 + 10; // CAMBIAR ESTE

// GJNM
struct point {
    int x, y;
};
int N, E, S;

vi ORD[2];
vector<point> P;

double dist(int i, int j) {
    return sqrt((P[i].x - P[j].x) * (P[i].x - P[j].x) + (P[i].y - P[j].y) * (P[i].y - P[j].y));
}

double DP[2][MAXN][MAXN];
double f(int s, int u, int d) {
    if (s == 2) {
        double ret = 4e8;
        if (u + 1 == SZ(ORD[0]) && d + 1 == SZ(ORD[1]))
            ret = dist(E, S);
        if (u + 1 != SZ(ORD[0]))
            ret = min(ret, dist(E, ORD[0][u]) + f(0, u + 1, d));
        if (d + 1 != SZ(ORD[1]))
            ret = min(ret, dist(E, ORD[1][d]) + f(1, u, d + 1));
        return ret;
    }

    if (DP[s][u][d] >= 0) return DP[s][u][d];

    double &ret = DP[s][u][d] = 4e8;
    if (s == 0) {
        if (u + 1 == SZ(ORD[0]) && d + 1 == SZ(ORD[1]))
            ret = dist(ORD[0][u - 1], ORD[0][u]);
        if (u + 1 != SZ(ORD[0]))
            ret = min(ret, dist(ORD[0][u - 1], ORD[0][u]) + f(0, u + 1, d));
        if (d + 1 != SZ(ORD[1]))
            ret = min(ret, dist(ORD[0][u - 1], ORD[1][d]) + f(1, u, d + 1));
    }
    else if (s == 1) {
        if (u + 1 == SZ(ORD[0]) && d + 1 == SZ(ORD[1]))
            ret = dist(ORD[1][d - 1], ORD[1][d]);
        if (u + 1 != SZ(ORD[0]))
            ret = min(ret, dist(ORD[1][d - 1], ORD[0][u]) + f(0, u + 1, d));
        if (d + 1 != SZ(ORD[1]))
            ret = min(ret, dist(ORD[1][d - 1], ORD[1][d]) + f(1, u, d + 1));
    }
    return ret;
}

int main() {
    FOR(i, 0, 2) FOR(j, 0, MAXN) FOR(k, 0, MAXN) DP[i][j][k] = -1;
    riii(N, E, S); --E, --S;
    FOR(i, 0, N) {
        P.pb({0, 0});
        rii(P[i].x, P[i].y);
    }
    for (int i = (E + 1) % N; i != S; i = (i + 1) % N) ORD[0].pb(i);
    for (int i = (E - 1 + N) % N; i != S; i = (i - 1 + N) % N) ORD[1].pb(i);
    ORD[0].pb(S);
    ORD[1].pb(S);
    printf("%.6lF\n", f(2, 0, 0));
    return 0;
}