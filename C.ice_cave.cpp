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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(Point &b) {
        return (x == b.x && y == b.y);
    }
};
int row, col;
char mat[510][510];
bool vis[510][510];
Point startp, endp;

bool valid(int x, int y) {
    return (!vis[x][y] && (x >= 0 && x < row) && (y >= 0 && y < col) && (mat[x][y] == '.' || Point(x, y) == endp));
}

bool valid2(int x, int y) {
    return ((x >= 0 && x < row) && (y >= 0 && y < col) && mat[x][y] == '.');
}

void dfs(int x, int y) {
    vis[x][y] = true;
    for (auto dx : {1, 0, -1}) {
        for (auto dy : {1, 0, -1}) {
            if (abs(dx) == abs(dy))
                continue;
            if (valid(x + dx, y + dy)) {
                dfs(x + dx, y + dy);
            }
        }
    }
}

int main() {
    rii(row, col);
    FOR(i, 0, row) {
        scanf("%s\n", mat[i]);
    }
    int x, y;
    rii(x, y);
    startp = Point(x - 1, y - 1);
    rii(x, y);
    endp = Point(x - 1, y - 1);

    if (startp == endp) {
        for (auto dx : {1, 0, -1}) {
            for (auto dy : {1, 0, -1}) {
                if (abs(dx) == abs(dy))
                    continue;
                if (valid2(startp.x + dx, startp.y + dy)) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
        printf("NO\n");
    }
    else {
        dfs(startp.x, startp.y);
        if (vis[endp.x][endp.y]) {
            if (mat[endp.x][endp.y] == 'X') {
                printf("YES\n");
                return 0;
            }
            int cnt = 0;
            for (auto dx : {1, 0, -1}) {
                for (auto dy : {1, 0, -1}) {
                    if (abs(dx) == abs(dy))
                        continue;
                    if (valid2(endp.x + dx, endp.y + dy) || Point(endp.x + dx, endp.y + dy) == startp) {
                        cnt++;
                    }
                }
            }
            if (cnt >= 2) {
                printf("YES\n");
                return 0;
            }
        }
        printf("NO\n");
    }
    return 0;
}