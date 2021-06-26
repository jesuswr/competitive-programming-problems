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
const int MAXN = 210; // CAMBIAR ESTE

// GJNM
int n;
map<string, int> mp;
vi G[MAXN];

int ans = 0;

int dfs(int u, int start, int mx) {
    if (G[u].size() == 0)
        return -INF;
    else {
        if (G[u][0] == start)
            return mx;
        else
            return dfs(G[u][0], start, mx + 1);
    }
}


int main() {
    ri(n);
    int aux = 0;
    FOR(i, 0, n) {
        string a, b, c;
        cin >> a >> b >> c;
        if (mp.find(b) == mp.end())
            mp[b] = aux++;
        if (mp.find(c) == mp.end())
            mp[c] = aux++;
        G[mp[b]].pb(mp[c]);
    }

    FOR(i, 0, aux) {
        ans = max(ans, dfs(i, i, 1));
    }

    if (ans <= 0)
        printf("No trades possible\n");
    else
        printf("%d\n", ans);

    return 0;
}