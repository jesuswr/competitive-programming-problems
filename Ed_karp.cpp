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
int v, e;
int s, t;
int M[100][100];
bool vis[MAXN];

int dfs(int x, int mn_cap = INF) {
    if (x == t)
        return mn_cap;
    vis[x] = true;

    FOR(y, 0, v) {
        if (vis[y] || M[x][y] == 0)
            continue;

        int flow = dfs(y, min(mn_cap, M[x][y]));
        if (flow > 0) {
            M[x][y] -= flow;
            M[y][x] += flow;
            return flow;
        }
    }

    return 0;
}

int max_flow() {
    int tot_flow = 0;
    int new_flow = 0;

    while (new_flow = dfs(0), new_flow > 0) {
        tot_flow += new_flow;
        new_flow = 0;
        FOR(i, 0, v) {
            vis[i] = false;
        }
    }

    return tot_flow;
}


int main() {
    rii(v, e);
    s = 0, t = v - 1;
    FOR(i, 0, e) {
        int a, b, c;
        riii(a, b, c);
        M[a][b] = c;
    }

    printf("%d\n", max_flow());

    FOR(i, 0, e) {
        int a, b, c;
        riii(a, b, c);
        printf("De %d a %d : %d %d\n", a, b, M[a][b], M[b][a]);
    }
    return 0;
}