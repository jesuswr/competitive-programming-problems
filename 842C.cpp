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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
vi G[MAXN];
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
vi D[MAXN];
void f(int x) {
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            D[x].pb(i);
            if (i != x / i) D[x].pb(x / i);
        }
    }
}


int ANS[MAXN];
int CNT[MAXN];
void dfs(int x, int f = -1, int need = 0, int gcd = 0) {
    for (auto d : D[A[x]]) CNT[d]++;
    ANS[x] = gcd;
    for (auto d : D[A[x]])  if (CNT[d] >= need) ANS[x] = max(ANS[x], d);
    for (auto y : G[x]) {
        if (f == y) continue;
        dfs(y, x, need + 1, __gcd(gcd, A[x]));
    }
    for (auto d : D[A[x]]) CNT[d]--;
}



int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) if (SZ(D[A[i]]) == 0) f(A[i]);
    FOR(i, 1, N) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0);
    FOR(i, 0, N) printf("%d ", ANS[i]);
    printf("\n");

    return 0;
}