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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM

vector<pair<int, int>> G[MAXN]; int n;

int H[MAXN];
void dfs(int u, int f = -1) {
    for (auto [w, x] : G[u]) if (w != f) {
            H[w] = H[u] ^ x;
            dfs(w, u);
        }
}


int T;
int TRIE[MAXN * 30 * 10][2];
void add(int i, int xr) {
    for (int b = 30; b >= 0; b--) {
        int nxt = 1 & (xr >> b);
        if (TRIE[i][nxt] == 0) TRIE[i][nxt] = T++;
        i = TRIE[i][nxt];
    }
}

int go(int i, int xr) {
    int ans = 0;
    for (int b = 30; b >= 0; b--) {
        int nxt = 1 & (xr >> b);
        nxt = nxt ^ 1;
        if (TRIE[i][nxt] == 0) {
            i = TRIE[i][nxt ^ 1];
        }
        else {
            i = TRIE[i][nxt];
            ans |= (1 << b);
        }
    }
    return ans;
}

int main() {
    ri(n);
    T = n;
    FOR(i, 1, n) {
        int a, b, c;
        riii(a, b, c);
        --a, --b;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }
    dfs(0);
    FOR(i, 0, n) {
        add(0, H[i]);
    }
    FOR(i, 0, n) {
        printf("%d\n", go(0, H[i]));
    }

    return 0;
}