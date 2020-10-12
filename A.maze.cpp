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
const int MAXN = 510; // CAMBIAR ESTE

// GJNM
int n, m, k;
int good;
int cnt;
bool vis[MAXN][MAXN];
char mat[MAXN][MAXN];

bool valid(int r, int c) {
    return (min(r, c) >= 0 && r < n && c < m && mat[r][c] == '.');
}
void dfs(int r, int c) {
    cnt++;
    vis[r][c] = true;

    for (auto dr : {1, -1, 0}) {
        for (auto dc : {1, -1, 0}) {
            if (cnt == good - k)
                return;
            if (abs(dr) == abs(dc) || !valid(r + dr, c + dc) || vis[r + dr][c + dc])
                continue;
            dfs(r + dr, c + dc);
        }
    }
}

int main() {
    riii(n, m, k);
    FOR(i, 0, n) {
        scanf("%s", mat[i]);
        FOR(j, 0, m) {
            good += (mat[i][j] == '.');
        }
    }
    FOR(i, 0, n) {
        bool found = false;
        FOR(j, 0, m) {
            if (mat[i][j] == '.') {
                found = true;
                dfs(i, j);
                break;
            }
        }
        if (found)
            break;
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (mat[i][j] == '#')
                printf("#");
            else if (!vis[i][j])
                printf("X");
            else
                printf(".");
        }
        printf("\n");
    }

    return 0;
}