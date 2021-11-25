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
#include <unordered_set>
#include <unordered_map>
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
const int MAXN = 6e4; // CAMBIAR ESTE
const int SQ = 600;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int V, E, Q;
bool ON[MAXN];
int ANS[MAXN];
unordered_set<int> G[MAXN], GH[MAXN];

void calc(int u) {
    ANS[u] = 0;
    for (auto v : G[u]) {
        GH[v].insert(u);
        ANS[u] += ON[v];
    }
}
void clean(int u) {
    ANS[u] = 0;
    for (auto v : G[u])
        GH[v].erase(u);
}

void add_edge(int u, int v) {
    ANS[u] += ON[v];
    ANS[v] += ON[u];

    G[u].insert(v);
    G[v].insert(u);

    if (SZ(G[u]) == SQ)
        calc(u);
    else if (SZ(G[u]) > SQ)
        GH[v].insert(u);

    if (SZ(G[v]) == SQ)
        calc(v);
    else if (SZ(G[v]) > SQ)
        GH[u].insert(v);
}

void del_edge(int u, int v) {
    ANS[u] -= ON[v];
    ANS[v] -= ON[u];

    G[u].erase(v);
    G[v].erase(u);

    if (SZ(G[u]) < SQ)
        clean(u);
    else if (SZ(G[u]) >= SQ)
        GH[v].erase(u);

    if (SZ(G[v]) < SQ)
        clean(v);
    else if (SZ(G[v]) >= SQ)
        GH[u].erase(v);
}

void turn_on(int u) {
    ON[u] = 1;
    for (auto v : GH[u])
        ANS[v]++;
}
void turn_off(int u) {
    ON[u] = 0;
    for (auto v : GH[u])
        ANS[v]--;
}

void go(int u) {
    if (SZ(G[u]) >= SQ)
        printf("%d\n", ANS[u]);
    else {
        int ans = 0;
        for (auto v : G[u]) ans += ON[v];
        printf("%d\n", ans);
    }
}

int main() {
    riii(V, E, Q);
    int _o; ri(_o);
    while (_o--) {
        int a; ri(a);
        ON[a - 1] = 1;
    }
    FOR(_, 0, E) {
        int a, b; rii(a, b);
        add_edge(a - 1, b - 1);
    }

    char s[5]; int u, v;
    while (Q--) {
        dadsadasda = scanf("%s", s);
        if (s[0] == 'O') {
            ri(u); --u;
            turn_on(u);
        }
        else if (s[0] == 'F') {
            ri(u); --u;
            turn_off(u);
        }
        else if (s[0] == 'A') {
            rii(u, v); --u; --v;
            add_edge(u, v);
        }
        else if (s[0] == 'D') {
            rii(u, v); --u; --v;
            del_edge(u, v);
        }
        else if (s[0] == 'C') {
            ri(u); --u;
            go(u);
        }

    }
    return 0;
}