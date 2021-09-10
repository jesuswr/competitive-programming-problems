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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int main() {
    int n, m; rii(n, m);
    vector<tuple<int, int, ll>> edges(m);
    FOR(i, 0, m) {
        int a, b, c; riii(a, b, c);
        edges[i] = {a - 1, b - 1, c};
    }
    vector<ll> D(n);
    vi F(n);
    bool change = true;
    for (int i = 0; i < n - 1 && change; ++i) {
        change = false;
        for (auto [a, b, c] : edges) {
            if (D[a] + c < D[b]) {
                D[b] = D[a] + c;
                F[b] = a;
                change = true;
            }
        }
    }

    for (auto [a, b, c] : edges) {
        if (D[a] + c < D[b]) {
            printf("YES\n");
            vi cyc;
            FOR(i, 0, n) a = F[a];
            int u = a;
            do {
                cyc.pb(u + 1);
                u = F[u];
            } while (u != a);
            cyc.pb(u + 1);
            reverse(ALL(cyc));
            for (auto v : cyc) printf("%d ", v);
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}