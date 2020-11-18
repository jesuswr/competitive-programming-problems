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
int n, m, k;
vi G[MAXN];
int deg[MAXN];
bool erased[MAXN];
queue<int> pos_cliq, pos_set;

void erase(int v) {
    erased[v] = true;
    for (auto u : G[v]) {
        if (erased[u])
            continue;
        m--;
        deg[u]--;
        if (deg[u] < k - 1)
            erase(u);
    }
}

void erase2(int v) {
    erased[v] = true;
    for (auto u : G[v]) {
        if (erased[u])
            continue;
        deg[u]--;
        if (deg[u] < k - 1)
            erase2(u);
        if (deg[u] == k - 1)
            pos_cliq.push(u);
    }
}

bool check_clique(int a) {
    ll aux = k;
    aux = (aux * (aux - 1)) >> 1;
    if (aux > (ll)m)
        return false;
    for (auto b : G[a]) {
        if (erased[b])
            continue;

        int found = 0;
        for (auto c : G[a]) {
            if (erased[c])
                continue;

            auto it = lb(ALL(G[b]), c);
            if (it == G[b].end())
                continue;
            if (*it == c)
                found++;
        }
        if (found < k - 2)
            return false;
    }

    printf("2\n");
    printf("%d ", a + 1);
    for (auto b : G[a]) {
        if (erased[b])
            continue;
        printf("%d ", b + 1);
    }
    printf("\n");
    return true;
}



void solve() {
    riii(n, m, k);

    FOR(i, 0, m) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
        deg[a]++, deg[b]++;
    }


    ll aux = k;
    aux = (aux * (aux - 1)) >> 1;
    if (aux > m) {
        printf("-1\n");
        return;
    }

    FOR(i, 0, n) {
        if (!erased[i] && deg[i] < k - 1)
            erase(i);
    }

    FOR(i, 0, n) {
        sort(ALL(G[i]));
        if (deg[i] == k - 1)
            pos_cliq.push(i);
        else
            pos_set.push(i);
    }


    while (!pos_cliq.empty()) {
        int v = pos_cliq.front(); pos_cliq.pop();
        if (erased[v])
            continue;

        if (check_clique(v))
            return;
        else
            erase2(v);
    }

    while (!pos_set.empty()) {
        int v = pos_set.front(); pos_set.pop();
        if (erased[v])
            continue;
        vi ans;
        FOR(i, 0, n) {
            if (!erased[i])
                ans.pb(i);
        }
        printf("%d %d\n", 1, SZ(ans));
        for (auto x : ans) {
            printf("%d ", x + 1);
        } printf("\n");
        return;
    }
    printf("-1\n");
}

int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
        FOR(i, 0, n) {
            erased[i] = false;
            G[i].clear();
            deg[i] = 0;
            while (!pos_set.empty())
                pos_set.pop();
            while (!pos_cliq.empty())
                pos_cliq.pop();
        }
    }

    return 0;
}