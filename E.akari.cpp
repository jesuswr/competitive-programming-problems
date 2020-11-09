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
int R, C, N, M;
int mat[1600][1600];
int ans[1600][1600];

void propagate_horizontal() {
    FOR(r, 0, R) {
        int curr_light = 0;
        FOR(c, 0, C) {
            if (mat[r][c] == 1) {
                curr_light = 1;
                ans[r][c] = 1;
            }
            else if (mat[r][c] == -1) {
                curr_light = 0;
            }
            else if (curr_light == 1) {
                ans[r][c] = 1;
            }
        }
    }
    FOR(r, 0, R) {
        int curr_light = 0;
        ROF(c, C - 1, -1) {
            if (mat[r][c] == 1) {
                curr_light = 1;
                ans[r][c] = 1;
            }
            else if (mat[r][c] == -1) {
                curr_light = 0;
            }
            else if (curr_light == 1) {
                ans[r][c] = 1;
            }
        }
    }
}

void propagate_vertical() {
    FOR(c, 0, C) {
        int curr_light = 0;
        FOR(r, 0, R) {
            if (mat[r][c] == 1) {
                curr_light = 1;
                ans[r][c] = 1;
            }
            else if (mat[r][c] == -1) {
                curr_light = 0;
            }
            else if (curr_light == 1) {
                ans[r][c] = 1;
            }
        }
    }
    FOR(c, 0, C) {
        int curr_light = 0;
        ROF(r, R - 1, -1) {
            if (mat[r][c] == 1) {
                curr_light = 1;
                ans[r][c] = 1;
            }
            else if (mat[r][c] == -1) {
                curr_light = 0;
            }
            else if (curr_light == 1) {
                ans[r][c] = 1;
            }
        }
    }
}

int main() {
    rii(R, C); rii(N, M);
    FOR(i, 0, N) {
        int r, c;
        rii(r, c);
        mat[r - 1][c - 1] = 1;
    }
    FOR(i, 0, M) {
        int r, c;
        rii(r, c);
        mat[r - 1][c - 1] = -1;
    }

    propagate_horizontal();
    propagate_vertical();

    int anss = 0;
    FOR(i, 0, R) FOR(j, 0, C) {
        anss += ans[i][j];
    }
    printf("%d\n", anss);


    return 0;
}