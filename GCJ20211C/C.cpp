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
const int MAXN = 1 << 16; // CAMBIAR ESTE

// GJNM
int D[MAXN];

void read(int &ret) {
    string s; cin >> s;
    ret = 0;
    for (int i = 0; i < SZ(s); ++i) ret = ret * 2 + (s[i] == '1');
}

void solve() {
    FOR(i, 0, MAXN) D[i] = INF;
    int s, e; read(s), read(e);
    queue<int> bfs; bfs.push(s); D[s] = 0;

    while (!bfs.empty()) {
        int u = bfs.front();
        //for (int b = 15; b >= 0; --b) printf("%d", 1 & (u >> b) );
        //printf("\n");
        bfs.pop();
        if (u == e) {
            printf("%d\n", D[e]);
            return;
        }

        int v = u << 1;
        if (v < MAXN && D[v] > D[u] + 1) {
            D[v] = D[u] + 1;
            bfs.push(v);
        }
        int mx = 0;
        for (int b = 0; b < 16; ++b) if (u & (1 << b)) mx = b;
        int xr = (1 << (mx + 1)) - 1;
        v = u ^ xr;
        if (v < MAXN && D[v] > D[u] + 1) {
            D[v] = D[u] + 1;
            bfs.push(v);
        }
    }
    printf("IMPOSSIBLE\n");
}

int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}