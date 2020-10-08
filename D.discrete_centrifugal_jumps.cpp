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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 4e5; // CAMBIAR ESTE

// GJNM
int n;
int h[MAXN];
int cst[MAXN];
bool vis[MAXN];
vi G[MAXN];

void bfs(int v) {
    vis[v] = true;
    cst[v] = 0;
    queue<int> bfss;
    bfss.push(v);
    while (!bfss.empty()) {
        int u = bfss.front();
        bfss.pop();
        if (u == n - 1)
            break;
        for (auto x : G[u]) {
            if (!vis[x]) {
                vis[x] = true;
                cst[x] = cst[u] + 1;
                bfss.push(x);
            }
        }
    }
}

int main() {
    ri(n);
    FOR(i, 0, n) {
        ri(h[i]);
        G[i].pb(i + 1);
    }
    stack<int> st;
    ROF(i, n - 1, -1) {
        while (!st.empty() && h[st.top()] < h[i])
            st.pop();
        if (!st.empty())
            G[i].pb(st.top());
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    ROF(i, n - 1, -1) {
        while (!st.empty() && h[st.top()] > h[i])
            st.pop();
        if (!st.empty())
            G[i].pb(st.top());
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    FOR(i, 0, n) {
        while (!st.empty() && h[st.top()] > h[i])
            st.pop();
        if (!st.empty())
            G[st.top()].pb(i);
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    FOR(i, 0, n) {
        while (!st.empty() && h[st.top()] < h[i])
            st.pop();
        if (!st.empty())
            G[st.top()].pb(i);
        st.push(i);
    }
    //FOR(i,0,n){
    //    printf("%d %d %d %d\n", next_up[i], next_up2[i], next_down[i], next_down2[i]);
    //}

    bfs(0);
    printf("%d\n", cst[n - 1]);
    return 0;
}