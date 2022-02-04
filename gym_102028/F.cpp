#include <iostream>
#include <stdio.h>
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
#include <cstdio>
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
const int MAXN = 8e3; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int R, C;
char S[4000 + 5][6000 + 5];
bool CST[4000 + 5][6000 + 5];
int DST[4000 + 5][6000 + 5];
int DX[6] = {1, -1, 1, -1, 2, -2};
int DY[6] = {3, 3, -3, -3, 0, 0};

bool in(int x, int y) {
    return min(x, y) >= 0 && x < R && y < C;
}

bool valid(int x, int y) {
    return in(x, y) && (S[x][y] == ' ' || S[x][y] == 'T' || S[x][y] == 'S');
}


void solve() {
    rii(R, C);
    R = 4 * R + 3;
    C = 6 * C + 3;
    getchar();
    FOR(i, 0, R) fgets(S[i], INF, stdin);
    FOR(i, 0, R) FOR(j, 0, C) {
        DST[i][j] = INF;
        CST[i][j] = 0;
    }
    FOR(i, 0, R) FOR(j, 0, C) if (S[i][j] == '+') {
        if (in(i + 2, j + 2) && S[i + 2][j + 2] == '+' && S[i + 1][j + 1] == ' ')
            CST[i + 1][j + 1] = 1;
        if (in(i + 2, j - 2) && S[i + 2][j - 2] == '+' && S[i + 1][j - 1] == ' ')
            CST[i + 1][j - 1] = 1;
        if (in(i, j + 4) && S[i][j + 4] == '+' && S[i][j + 1] == ' ')
            CST[i][j + 1] = CST[i][j + 2] = CST[i][j + 3] = 1;
    }
    int sx = 0, sy = 0, tx = 0, ty = 0;
    FOR(i, 0, R) FOR(j, 0, C) {
        if (S[i][j] == 'S') {
            sx = i;
            sy = j;
        }
        if (S[i][j] == 'T') {
            tx = i;
            ty = j;
        }
    }

    deque<pii> q;
    q.push_front({sx, sy});
    DST[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        if (x == tx && y == ty) {
            printf("%d\n", DST[x][y] + 1);
            return;
        }
        FOR(i, 0, 6) {
            int new_x = x + DX[i], new_y = y + DY[i];
            if (valid(new_x, new_y) && DST[new_x][new_y] > DST[x][y] + CST[new_x][new_y] ) {
                DST[new_x][new_y] = DST[x][y] + CST[new_x][new_y];
                if (CST[new_x][new_y] == 1)
                    q.push_back({new_x, new_y});
                else
                    q.push_front({new_x, new_y});
            }
        }
    }
    printf("-1\n");
}


int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}