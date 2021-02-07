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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int N;
pii A[MAXN];
ll DP[MAXN];
int NXT[MAXN];

ll f(int p) {
    if (DP[p] != -1) return DP[p];
    if (p == N) return DP[p] = 0;
    if (p > N) return DP[p] = LLINF;
    DP[p] = LLINF;
    for (int q = p + 2; q <= p + 4; q++)
        DP[p] = min(DP[p], A[q].F - A[p].F + f(q + 1));
    for (int q = p + 2; q <= p + 4; q++)
        if (DP[p] == A[q].F - A[p].F + f(q + 1)) NXT[p] = q + 1;


    return DP[p];
}

int ANS[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i].F);
    FOR(i, 0, N) A[i].S = i;
    sort(A, A + N);
    memset(DP, -1, sizeof(DP));
    ll ans = f(0);
    int g = 0, p = 0;
    while (p < N) {
        ++g;
        FOR(i, p, NXT[p]) ANS[A[i].S] = g;
        p = NXT[p];
    }
    printf("%lld %d\n", ans, g);
    FOR(i, 0, N) printf("%d ", ANS[i]);
    printf("\n");
    return 0;
}