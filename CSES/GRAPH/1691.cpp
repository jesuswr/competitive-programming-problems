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
const int MAXN = 1e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
int DEG[MAXN];
vector<tuple<int, bool, int>> G[MAXN];

bool V[MAXN];
bool check(int s) {
    FOR(i, 0, N) if (DEG[i] & 1)
        return false;
    queue<int> bfs; bfs.push(s);
    V[s] = true;
    while (!bfs.empty()) {
        int u = bfs.front(); bfs.pop();
        for (auto [v, _, __] : G[u]) if (!V[v]) {
                V[v] = 1;
                bfs.push(v);
            }
    }
    FOR(i, 0, N) if (DEG[i] > 0 && !V[i])
        return false;
    return true;
}

int FST_FREE[MAXN];

int main() {
    rii(N, M);
    int root = 0;
    FOR(i, 0, M) {
        int a, b; rii(a, b); a--; b--;
        int auxa = SZ(G[a]), auxb = SZ(G[b]);
        G[a].pb({b, true, auxb});
        G[b].pb({a, true, auxa});
        DEG[a]++;
        DEG[b]++;
    }


    if (!check(root)) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    vi ans;
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
        auto v = st.top();
        if (DEG[v] == 0) {
            ans.pb(v);
            st.pop();
        }
        else {
            FOR(i, FST_FREE[v], SZ(G[v])) {
                auto [u, used, aux] = G[v][i];
                if (!used) continue;
                st.push(u);
                G[v][i] = {u, false, aux};
                G[u][aux] = {v, false, i};
                DEG[u]--; DEG[v]--;
                FST_FREE[v] = i + 1;
                break;
            }
        }
    }
    for (auto x : ans) printf("%d ", x + 1);
    printf("\n");
    return 0;
}