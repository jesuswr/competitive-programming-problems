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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
vi G[MAXN];
int D[MAXN];
bool VIS[MAXN];
set<int> HOLA[MAXN];

int main() {
    int N, C, K; riii(N, C, K);
    FOR(_, 0, C) {
        int a, b; rii(a, b);
        G[a].pb(b);
        G[b].pb(a);
    }

    VIS[K] = 1;
    queue<int> ord; ord.push(K);

    while (!ord.empty()) {
        int u = ord.front(); ord.pop();
        for (auto v : G[u]) {
            if (!VIS[v]) {
                VIS[v] = 1;
                D[v] = D[u] + 1;
                ord.push(v);
            }
        }
    }
    FOR(i, 0, N) if (i != K) HOLA[D[i]].insert(i);

    FOR(i, 0, N) {
        if (!HOLA[i].empty()) {
            printf("%d:", i);
            for (auto x : HOLA[i]) printf(" %d", x);
            printf("\n");
        }
    }


    return 0;
}