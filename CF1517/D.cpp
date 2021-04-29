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
const int MAXN = 510; // CAMBIAR ESTE
const int MAXK = 22; // CAMBIAR ESTE

// GJNM
int N, M, K;
vii G[MAXN * MAXN];
int DP[MAXN * MAXN][MAXK];

int main() {
    riii(N, M, K);
    FOR(i, 0, N) FOR(j, 0, M - 1) {
        int aux; ri(aux);
        int from = MAXN * i + j, to = MAXN * i + j + 1;
        G[from].pb({to, aux});
        G[to].pb({from, aux});
    }
    FOR(i, 0, N - 1) FOR(j, 0, M) {
        int aux; ri(aux);
        int from = MAXN * i + j, to = MAXN * (i + 1) + j;
        G[from].pb({to, aux});
        G[to].pb({from, aux});
    }
    for (int k = 2; k <= 20; k += 2) {
        FOR(i, 0, N) FOR(j, 0, M) {
            int a = MAXN * i + j;
            DP[a][k] = 1e9;
            for (auto aux : G[a]) {
                int b = aux.F;
                DP[a][k] = min(DP[a][k], 2 * aux.S + DP[b][k - 2]);
            }
        }
    }

    FOR(i, 0, N) {
        FOR(j, 0, M) {
            if (K & 1) printf("-1 ");
            else printf("%d ", DP[MAXN * i + j][K]);
        }
        printf("\n");
    }


    return 0;
}