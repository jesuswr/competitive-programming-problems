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
const int MAXN = 1069; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int x, y;
int X[MAXN], Y[MAXN];
int MAT[MAXN][MAXN];

void move(int dx, int dy) {
    x += dx; y += dy;
    assert(min(x, y) >= 1 && max(x, y) < 1000);
    printf("%d %d\n", x, y);
    fflush(stdout);
    int k, a, b; riii(k, a, b);
    if (k == -1 && a == -1 && b == -1)
        exit(0);
    if (k == 0 && a == 0 && b == 0)
        exit(0);
    MAT[X[k]][Y[k]]--;
    X[k] = a; Y[k] = b;
    MAT[X[k]][Y[k]]++;
}

int count(int x1, int y1, int x2, int y2) {
    int sm = 0;
    for (int _x = x1; _x <= x2; ++_x) for (int _y = y1; _y <= y2; ++_y)
            sm += MAT[_x][_y];
    return sm;
}

int main() {
    rii(x, y);
    FOR(i, 1, 666 + 1) {
        rii(X[i], Y[i]);
        MAT[X[i]][Y[i]]++;
    }
    while (x < 500)
        move(1, 0);
    while (x > 500)
        move(-1, 0);
    while (y < 500)
        move(0, 1);
    while (y > 500)
        move(0, -1);
    int ul = count(1, 1, 499, 499), ur = count(1, 501, 499, 999);
    int dl = count(501, 1, 999, 499), dr = count(501, 501, 999, 999);
    int dx, dy;
    int mn = min({ul, ur, dl, dr});
    if (mn == ul)
        dx = 1, dy = 1;
    else if (mn == ur)
        dx = 1, dy = -1;
    else if (mn == dl)
        dx = -1, dy = 1;
    else
        dx = -1, dy = -1;
    int mx_moves = 499;
    while (mx_moves--) {
        if (MAT[x + dx][y + dy] == 0) 
            move(dx, dy);
        else 
            move(dx, 0);
    }

    return 0;
}