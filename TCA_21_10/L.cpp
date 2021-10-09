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
vii G[MAXN];

int V[MAXN], C[MAXN];
int dfs(int x, int c, int v, vi &on) {
    V[x] = v;
    C[x] = c;
    if (c == 1)
        on.pb(x);

    for (auto [y, e] : G[x]) {
        if (V[y] != v) {
            if (dfs(y, e ^ c, v, on) == -1)
                return -1;
        }
        else {
            if (C[y] != (e ^ c))
                return -1;
        }
    }
    return 0;
}

int main() {
    rii(N, M);
    FOR(_, 0, M) {
        int a, b; char c;
        cin >> a >> b >> c;
        --a, --b;
        G[a].pb({b, (c == 'B' ? 0 : 1)});
        G[b].pb({a, (c == 'B' ? 0 : 1)});
    }
    int ans = 0;
    vi out;
    FOR(i, 0, N)if (V[i] == 0) {
        vi a, b;
        int op1 = dfs(i, 0, 1, a);
        int op2 = dfs(i, 1, 2, b);
        if (op1 < 0 && op2 < 0) {
            ans = -1;
            break;
        }
        if (SZ(a) < SZ(b) || op2 == -1) {
            ans += SZ(a);
            for (auto x : a)
                out.pb(x);
        }
        else {
            ans += SZ(b);
            for (auto x : b)
                out.pb(x);
        }
    }


    FOR(i, 0, N) {
        V[i] = 0;
        for (auto &p : G[i])
            p.S = 1 ^ p.S;
    }
    int ans2 = 0;
    vi out2;
    FOR(i, 0, N)if (V[i] == 0) {
        vi a, b;
        int op1 = dfs(i, 0, 1, a);
        int op2 = dfs(i, 1, 2, b);
        if (op1 < 0 && op2 < 0) {
            ans2 = -1;
            break;
        }
        if (SZ(a) < SZ(b) || op2 == -1) {
            ans2 += SZ(a);
            for (auto x : a)
                out2.pb(x);
        }
        else {
            ans2 += SZ(b);
            for (auto x : b)
                out2.pb(x);
        }
    }

    if (ans2 != -1 && (ans == -1 || ans2 <= ans) ) {
        printf("%d\n", ans2);
        for (auto p : out2) printf("%d ", p + 1);
        printf("\n");
        return 0;
    }
    if (ans != -1) {
        printf("%d\n", ans);
        for (auto p : out) printf("%d ", p + 1);
        printf("\n");
        return 0;
    }

    printf("-1\n");

    return 0;
}