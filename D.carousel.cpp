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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN];
bool vis[MAXN][3];
bool valid[MAXN][3];

bool dfs(int v, int col, int max_col, int first_col) {
    if (vis[v][col])
        return valid[v][col];
    vis[v][col] = true;
    if (v == n - 1) {
        if (a[n - 1] != a[0])
            return valid[v][col] = (first_col != col);
        else
            return valid[v][col] = true;
    }
    FOR(next_col, 0, max_col) {
        if (next_col == col && a[v] != a[v + 1])
            continue;
        valid[v][col] |= dfs(v + 1, next_col, max_col, first_col);
    }
    return valid[v][col];
}

void prnt(int max_col, int curr) {
    printf("%d\n", max_col);
    FOR(i, 0, n) {
        printf("%d ", curr + 1);
        if (i == n - 1) {
            printf("\n");
            return;
        }
        FOR(next_col, 0, max_col) {
            if (next_col == curr && a[i] != a[i + 1])
                continue;
            if (valid[i + 1][next_col]) {
                curr = next_col;
                break;
            }
        }
    }
}


void solve() {
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }

    for (int cols : {1, 2, 3}) {
        FOR(first_col, 0, cols) {
            FOR(i, 0, n + 1) {
                FOR(c, 0, cols) {
                    vis[i][c] = valid[i][c] = false;
                }
            }
            if (dfs(0, first_col, cols, first_col)) {
                prnt(cols, first_col);
                return;
            }
        }

    }


}



int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
    }

    return 0;
}