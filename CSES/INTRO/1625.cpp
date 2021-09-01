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
const int MAXN = 1e5; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
const int N = 7;
vii mv;
pii MV[4] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
int ans;

bool V[7][7];
void dfs(int r, int c, int m) {
    // FOR(i, 0, m) printf("\t");
    // printf("%d %d\n", r, c);

    if (r == N - 1 && c == 0) {
        ans += m == N * N - 1;
        return;
    }


    bool a = V[r - 1][c], b = V[r + 1][c], d = V[r][c + 1], e = V[r][c - 1];
    if (((r + 1 == N || (a && b)) && c - 1 >= 0 && c + 1 < N && !e && !d) ||
            ((c + 1 == N || (e && d)) && r - 1 >= 0 && r + 1 < N && !a && !b) ||
            ((r == 0 || (b && a)) && c - 1 >= 0 && c + 1 < N && !e && !d) ||
            ((c == 0 || (d && e)) && r - 1 >= 0 && r + 1 < N && !a && !b))
        return;

    V[r][c] = 1;
    if (mv[m].F == -69) {
        FOR(i, 0, 4) {
            int new_r = r + MV[i].F, new_c = c + MV[i].S;
            if (max(new_r, new_c) < N && min(new_r, new_c) >= 0 && !V[new_r][new_c])
                dfs(new_r, new_c, m + 1);
        }
    }
    else {
        int new_r = r + mv[m].F, new_c = c + mv[m].S;
        if (max(new_r, new_c) < N && min(new_r, new_c) >= 0 && !V[new_r][new_c])
            dfs(new_r, new_c, m + 1);
    }
    V[r][c] = 0;
}

int main() {
    string s; cin >> s;
    for (auto &c : s) {
        if (c == '?')
            mv.pb({ -69, 69});
        if (c == 'R')
            mv.pb({0, 1});
        if (c == 'L')
            mv.pb({0, -1});
        if (c == 'U')
            mv.pb({ -1, 0});
        if (c == 'D')
            mv.pb({1, 0});
    }
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}