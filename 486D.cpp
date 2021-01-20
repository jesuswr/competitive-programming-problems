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
const int MAXN = 2001; // CAMBIAR ESTE
const int MOD = 1e9 + 7;

// GJNM
int D, N;
int A[MAXN];
vi G[MAXN];
bool VIS[MAXN];

int f(int x, int r) {
    int ret = 1;
    VIS[x] = true;
    for (auto y : G[x]) {
        if (VIS[y] || A[y] > A[r] + D || A[y] < A[r]) continue;
        if (A[r] == A[y] && y < r) continue;
        ret = (1ll * ret * (f(y, r) + 1)) % MOD;
    }
    return ret;
}

int main() {
    rii(D, N);
    FOR(i, 0, N) ri(A[i]);
    FOR(_, 1, N) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    int ans = 0;
    FOR(i, 0, N) {
        memset(VIS, false, sizeof(VIS));
        ans = (ans + f(i, i)) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}