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
const int MAXN = 5e5; // CAMBIAR ESTE

// GJNM
int N;
ll A[MAXN];
ll SUF[MAXN][32];

int main() {
    ri(N);
    FOR(i, 0, N) rl(A[i]);
    for (int i = N - 1; i >= 0; --i) {
        for (int b = 0; b < 32; ++b) {
            SUF[i][b] = 1ll & (A[i] >> b);
            SUF[i][b] += SUF[i + 1][b];
        }
    }
    ll ans = 0;
    FOR(i, 0, N - 1) FOR(b, 0, 32) {
        if (1ll & (A[i] >> b)) ans += (N - i - 1 - SUF[i + 1][b]) * (1ll << b);
        else ans += SUF[i + 1][b] * (1ll << b);
    }
    printf("%lld\n", ans);
    return 0;
}