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
const int MAXN = 1010; // CAMBIAR ESTE

// GJNM
pii REP[MAXN][MAXN];
int H[MAXN][MAXN];
pii find(int x, int y) {
    if (REP[x][y] == make_pair(-1, -1))
        return {x, y};
    else
        return REP[x][y] = find(REP[x][y].F, REP[x][y].S);
}
void unio(int x, int y, int a, int b) {
    if (H[x][y] >= H[a][b]) {
        REP[a][b] = {x, y};
        if (H[x][y] == H[a][b]) H[x][y]++;
    }
    else {
        REP[x][y] = {a, b};
    }
}

int R, C, Q;
int XY[10100][4];
int MAT[MAXN][MAXN];

bool valid(int r, int c) {
    return min(r, c) >= 0 && r < R && c < C && (MAT[r][c] >= 0);
}

int main() {
    riii(R, C, Q);
    FOR(i, 0, Q) {
        FOR(j, 0, 4) ri(XY[i][j]);
        FOR(j, 0, 4) XY[i][j]--;
        if (XY[i][0] != XY[i][2]) {
            FOR(x, XY[i][0], XY[i][2] + 1) MAT[x][XY[i][1]]--;
        }
        else {
            FOR(y, XY[i][1], XY[i][3] + 1) MAT[XY[i][0]][y]--;
        }
    }
    int CMP = 0;
    FOR(r, 0, R) FOR(c, 0, C) {
        if (MAT[r][c] == 0) {
            REP[r][c] = { -1, -1};
            ++CMP;
            for (int dr : { -1, 0})
                for (int dc : { -1, 0}) {
                    if (abs(dr) == abs(dc)) continue;
                    if (valid(r + dr, c + dc)) {
                        auto p1 = find(r + dr, c + dc), p2 = find(r, c);
                        if (p1 != p2) {
                            --CMP;
                            unio(p1.F, p1.S, p2.F, p2.S);
                        }
                    }
                }
        }
    }

    vi ans;
    for (int q = Q - 1; q >= 0; --q) {
        ans.pb(CMP);
        if (XY[q][0] != XY[q][2]) {
            int c = XY[q][1];
            FOR(r, XY[q][0], XY[q][2] + 1) {
                MAT[r][c]++;
                if (MAT[r][c] == 0) {
                    REP[r][c] = { -1, -1};
                    ++CMP;
                    for (int dr : { -1, 0, 1})
                        for (int dc : { -1, 0, 1}) {
                            if (abs(dr) == abs(dc)) continue;
                            if (valid(r + dr, c + dc)) {
                                auto p1 = find(r + dr, c + dc), p2 = find(r, c);
                                if (p1 != p2) {
                                    --CMP;
                                    unio(p1.F, p1.S, p2.F, p2.S);
                                }
                            }
                        }
                }
            }
        }
        else {
            int r = XY[q][0];
            FOR(c, XY[q][1], XY[q][3] + 1) {
                MAT[r][c]++;
                if (MAT[r][c] == 0) {
                    REP[r][c] = { -1, -1};
                    ++CMP;
                    for (int dr : { -1, 0, 1})
                        for (int dc : { -1, 0, 1}) {
                            if (abs(dr) == abs(dc)) continue;
                            if (valid(r + dr, c + dc)) {
                                auto p1 = find(r + dr, c + dc), p2 = find(r, c);
                                if (p1 != p2) {
                                    --CMP;
                                    unio(p1.F, p1.S, p2.F, p2.S);
                                }
                            }
                        }
                }
            }
        }
    }
    reverse(ALL(ans));
    for (auto x : ans) printf("%d\n", x);
    return 0;
}