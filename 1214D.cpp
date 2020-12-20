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
const int MAXN = 2e6; // CAMBIAR ESTE

// GJNM
int n, m;
vector<vector<bool>> vis;
string M[MAXN];
int moves[2][2] = {{0, 1}, {1, 0}};

bool valid(int r, int c) {
    return min(r, c) >= 0 && r < n && c < m && !vis[r][c] && M[r][c] == '.';
}

bool dfs(int row, int col, int m1, int m2) {
    if (row == n - 1 && col == m - 1)
        return true;
    vis[row][col] = true;
    int r1 = row + moves[m1][0], c1 = col + moves[m1][1];
    if (valid(r1, c1) && dfs(r1, c1, m1, m2))
        return true;
    r1 = row + moves[m2][0], c1 = col + moves[m2][1];
    if (valid(r1, c1) && dfs(r1, c1, m1, m2))
        return true;
    return false;
}

int main() {
    rii(n, m);
    FOR(i, 0, n) {
        cin >> M[i];
    }
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    if (!dfs(0, 0, 0, 1))
        printf("0\n");
    else if (!dfs(0, 0, 1, 0))
        printf("1\n");
    else
        printf("2\n");

    return 0;
}