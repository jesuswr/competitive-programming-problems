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
const ll MOD = 998244353;

// GJNM
int N, M;
int DP[1010][12][12][12];

int f(int p, int a, int b, int c) {
    int &ret = DP[p][a][b][c];
    if (ret != -1)
        return ret;
    if (p == N)
        return ret = c <= M;
    ret = 0;
    for (int d = 1; d <= M; ++d) {
        if (d <= a)
            ret += f(p + 1, d, b, c);
        else if (d <= b)
            ret += f(p + 1, a, d, c);
        else if (d <= c)
            ret += f(p + 1, a, b, d);
        if (ret >= MOD)
            ret -= MOD;
    }
    return ret;
}


int main() {
    memset(DP, -1, sizeof(DP));
    rii(N, M);
    printf("%d\n", f(0, M + 1, M + 1, M + 1));
    return 0;
}