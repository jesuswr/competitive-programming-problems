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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
string N;

int DP[10][25][11];
int f(int p, int rst, int x) {
    if (p == SZ(N))
        return rst == 0;
    if (DP[p][rst][x] != -1)
        return DP[p][rst][x];
    int &ret = DP[p][rst][x] = 0;
    if (N[p] == '_')
        FOR(d, p == 0, 10) ret += f(p + 1, (10 * rst + d) % 25, x);
    else if (N[p] == 'X') {
        if (x == 10)
            FOR(d, p == 0, 10) ret += f(p + 1, (10 * rst + d) % 25, d);
        else
            ret += f(p + 1, (10 * rst + x) % 25, x);
    }
    else
        ret += f(p + 1, (10 * rst + (N[p] - '0')) % 25, x);
    return DP[p][rst][x];
}

int main() {
    memset(DP, -1, sizeof(DP));
    cin >> N;
    if (N[0] == '0') {
        if (SZ(N) == 1)
            printf("1\n");
        else
            printf("0\n");
        return 0;
    }
    if ((N[0] == '_' || N[0] == 'X') && SZ(N) == 1) {
        printf("1\n");
        return 0;
    }
    printf("%d\n", f(0, 0, 10));
    return 0;
}