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
const int MAXN = 10010; // CAMBIAR ESTE

// GJNM
map<string, int> str_to_int;

int b, n;

vector<tuple<int, int, int>> G[MAXN];
bool vis[MAXN];
int cost[MAXN], prest[MAXN];

int deg[MAXN];

void topo() {
    queue<int> topo_ord;
    FOR(i, 0, n) {
        if (deg[i] == 0) {
            topo_ord.push(i);
        }
        else {
            cost[i] = 1e9 + 10;
        }
    }

    while (!topo_ord.empty()) {
        int v = topo_ord.front(); topo_ord.pop();

        for (auto tmp : G[v]) {
            int u, edge_c, edge_p;
            tie(u, edge_c, edge_p) = tmp;

            if (cost[u] > cost[v] + edge_c) {
                cost[u] = cost[v] + edge_c;
                prest[u] = prest[v] + edge_p;
            }
            else if (cost[u] == cost[v] + edge_c)
                prest[u] = max(prest[u], prest[v] + edge_p);

            deg[u]--;
            if (deg[u] == 0) {
                topo_ord.push(u);
            }
        }
    }
}

int dp[MAXN][MAXN];


int f(int pos, int cst) {
    if (cst < 0)
        return -INF;
    if (pos == n)
        return 0;

    if (dp[pos][cst] != -1)
        return dp[pos][cst];

    return dp[pos][cst] = max(f(pos + 1, cst), f(pos + 1, cst - cost[pos]) + prest[pos]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> b >> n;
    int n_cnt = 0;
    FOR(i, 0, n) {
        string der, bas, tmp;
        int c, p;
        cin >> der >> bas >> tmp >> c >> p;
        if (str_to_int.find(bas) == str_to_int.end())
            str_to_int[bas] = n_cnt++;
        if (str_to_int.find(der) == str_to_int.end())
            str_to_int[der] = n_cnt++;

        int der_n = str_to_int[der], bas_n = str_to_int[bas];
        G[bas_n].pb(make_tuple(der_n, c, p));
        deg[der_n]++;
    }


    n = n_cnt;

    topo();

    dp[n][0] = 0;
    for (int pos = n - 1; pos >= 0; pos--) {
        for (int cst = 0; cst <= b; cst++) {
            dp[pos][cst] = dp[pos + 1][cst];
            if (cst - cost[pos] >= 0)
                dp[pos][cst] = max(dp[pos][cst], dp[pos + 1][cst - cost[pos]] + prest[pos]);
        }
    }
    int ans = -1;
    int ans2;
    FOR(i, 0, b + 1) {
        if (dp[0][i] > ans) {
            ans = dp[0][i];
            ans2 = i;
        }
    }

    cout << ans << "\n" << ans2 << "\n";
    return 0;
}