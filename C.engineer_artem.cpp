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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int R, C;
int M[110][110];
int comp[110][110];

pii findd(int c) {
    FOR(i, 0, R) FOR(j, 0, C) {
        if (comp[i][j] == c)
            return {i, j};
    }
    return {0, 0};
}

int dist(int x, int y, int x2, int y2) {
    return (abs(x - x2) + abs(y - y2));
}

bool valid(int row, int col) {
    return min(row, col) >= 0 && row < R && col < C && comp[row][col] == -1;
}

void dfs(int r, int c, int cc) {
    comp[r][c] = cc;
    for (auto dr : {0, 1, -1}) {
        for (auto dc : {0, 1, -1}) {
            if (abs(dr) == abs(dc))
                continue;

            if (valid(r + dr, c + dc) && abs(M[r][c] - M[r + dr][c + dc]) < 2)
                dfs(r + dr, c + dc, cc);
        }
    }
}

void fill(int cmp, int r, int c) {
    int mn = 1e9 + 1;
    FOR(i, 0, R) {
        FOR(j, 0, C) {
            if (comp[i][j] == cmp)
                mn = min(mn, M[i][j]);
        }
    }

    FOR(i, 0, R) {
        FOR(j, 0, C) {
            if (comp[i][j] != cmp)
                continue;
            if (dist(i, j, r, c) & 1) {
                if ((M[i][j] - mn) & 1) {
                    M[i][j]++;
                }
            }
            else {
                if ( (~(M[i][j] - mn)) & 1) {
                    M[i][j]++;
                }
            }
        }
    }
}


void solve() {
    rii(R, C);
    int mx = 0;
    FOR(i, 0, R) {
        FOR(j, 0, C) {
            ri(M[i][j]);
            comp[i][j] = -1;
        }
    }

    int comp_n = 0;
    FOR(i, 0, R) {
        FOR(j, 0, C) {
            if (comp[i][j] == -1)
                dfs(i, j, comp_n++);
        }
    }

    FOR(i, 0, comp_n) {
        auto s = findd(i);
        fill(i, s.F, s.S);
    }

    FOR(i, 0, R) {
        FOR(j, 0, C) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}