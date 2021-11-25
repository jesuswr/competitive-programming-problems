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
const int MAXN = 2003; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
string MAT[MAXN];
int LEN[MAXN][MAXN];
bool CYC[MAXN][MAXN];

pii GOT(int i, int j) {
    if (MAT[i][j] == 'L')
        return {0, -1};
    else if (MAT[i][j] == 'R')
        return {0, 1};
    else if (MAT[i][j] == 'U')
        return { -1, 0};
    else
        return {1, 0};
}

char V[MAXN][MAXN];
void dfs2(int x, int y) {
    if (min(x, y) < 0 || x >= N || y >= M)
        return;
    V[x][y] = 1;
    int _x = x + GOT(x, y).F, _y = y + GOT(x, y).S;
    if (min(_x, _y) < 0 || _x >= N || _y >= M) {
        V[x][y] = 2;
        return;
    }
    // printf("%d %d \t %d %d\n", x, y, _x, _y);
    if (V[_x][_y] == 1)
        CYC[_x][_y] = 1;
    else if (V[_x][_y] == 0)
        dfs2(_x, _y);
    V[x][y] = 2;
}


void get_cycles() {
    FOR(i, 0, N) FOR(j, 0, M) if (V[i][j] == 0)
        dfs2(i, j);
    FOR(i, 0, N) FOR(j, 0, M) if (CYC[i][j]) {
        int x = i, y = j;
        int cnt = 0;
        do {
            cnt++;
            int _x = x + GOT(x,y).F, _y = y + GOT(x,y).S;
            x = _x, y = _y;
        } while (x != i || y != j);

        x = i, y = j;
        do {
            LEN[x][y] = cnt;
            int _x = x + GOT(x,y).F, _y = y + GOT(x,y).S;
            x = _x, y = _y;
        } while (x != i || y != j);

    }
}

int dfs(int x, int y) {
    if (min(x, y) < 0 || x >= N || y >= M)
        return 0;
    if (LEN[x][y] != 0)
        return LEN[x][y];
    LEN[x][y] = 1 + dfs(x + GOT(x,y).F, y + GOT(x,y).S);
    return LEN[x][y];
}

void solve() {
    rii(N, M);
    FOR(i, 0, N) cin >> MAT[i];
    get_cycles();


    int bst = 0;
    int x = 0, y = 0;
    FOR(i, 0, N) FOR(j, 0, M) {
        if (LEN[i][j] == 0)
            dfs(i, j);
        if (LEN[i][j] > bst) {
            bst = LEN[i][j];
            x = i;
            y = j;
        }
    }
    printf("%d %d %d\n", x + 1, y + 1, bst);
    FOR(i, 0, N) FOR(j, 0, M) {
        LEN[i][j] = 0;
        CYC[i][j] = 0;
        V[i][j] = 0;
    }
    FOR(i, 0, N) MAT[i].clear();
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}