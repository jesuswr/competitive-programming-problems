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
const int MAXN = 510; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int mark[MAXN], mat[MAXN][2];
int n;
vector<int> G[MAXN]; // [0,n) -> [0,n)

bool dfs(int v) {
    if (mark[v])  return 0;
    mark[v] = 1;
    for (auto u : G[v])
        if (mat[u][1] == -1 || dfs(mat[u][1]))
            return mat[v][0] = u, mat[u][1] = v, 1;
    return 0;
}
int maximum_matching() {
    memset(mat, -1, sizeof mat);
    bool br = 0;
    int ans = 0;
    while (br ^= 1) {
        memset(mark, 0, sizeof mark);
        for (int i = 0; i < n; i++)
            if (mat[i][0] == -1 && dfs(i))
                ans++, br = 0;
    }
    return ans;
}


int main() {
    int m, k; riii(n, m, k);
    FOR(_, 0, k) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
    }
    printf("%d\n", maximum_matching());
    FOR(i, 0, n) if (mat[i][0] != -1) printf("%d %d\n", i + 1, mat[i][0] + 1);
    return 0;
}