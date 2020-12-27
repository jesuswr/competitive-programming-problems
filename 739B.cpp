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
const int MAXN = 2e5 + 1; // CAMBIAR ESTE
const int LOGN = 22;

// GJNM
int N;
ll A[MAXN];
vii G[MAXN];

ll D[MAXN];
int H[MAXN], ANC[MAXN][LOGN];

ll dist(int a, int b) {
    return D[b] - D[a];
}

void pre(int x, int f) {
    ANC[x][0] = f;

    for (int l = 1; l < LOGN; l++) ANC[x][l] = ANC[ ANC[x][l - 1] ][l - 1];
    for (auto y : G[x]) {
        D[y.F] = D[x] + y.S;
        H[y.F] = H[x] + 1;
        pre(y.F, x);
    }
}


int ans[MAXN];
int CNT[MAXN];
int dfs(int x) {
    int up = x;
    for (int l = LOGN - 1; l >= 0; l--) if (dist(ANC[up][l], x) <= A[x]) up = ANC[up][l];

    int cnt = 0;
    for (auto y : G[x]) cnt += dfs(y.F);

    ans[x] = cnt;
    cnt -= CNT[x];

    if (up != x) {
        CNT[up]++;
        cnt++;
    }
    return cnt;

}


int main() {
    ri(N);
    FOR(i, 0, N) rl(A[i]);
    FOR(i, 1, N) {
        int pi, ci; rii(pi, ci);
        G[pi - 1].pb({i, ci});
    }
    pre(0, 0);


    dfs(0);
    FOR(i, 0, N) printf("%d ", ans[i]);
    printf("\n");

    return 0;
}