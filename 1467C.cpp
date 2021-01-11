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
const int MAXN = 3e5 + 10; // CAMBIAR ESTE

// GJNM
int N[3];
ll A[3][MAXN];
ll S[3];

ll f(int x) {
    FOR(i, 0, 3) {
        if (i == x) continue;
        if (N[i] == 1) return -LLINF;
    }

    ll tot = S[x];
    FOR(i, 0, 3) {
        if (i == x) continue;
        tot += S[i] - 2 * A[i][0];
    }
    return tot;
}

int main() {
    FOR(i, 0, 3) ri(N[i]);
    FOR(i, 0, 3) FOR(j, 0, N[i]) rl(A[i][j]);
    FOR(i, 0, 3) sort(A[i], A[i] + N[i]);
    FOR(i, 0, 3) FOR(j, 0, N[i]) S[i] += A[i][j];
    ll ans = 0;
    FOR(i, 0, 3) FOR(j, 0, 3) FOR(k, 0, 3) {
        if (i == j || j == k || i == k) continue;
        ans = max(ans, S[i] + S[j] - S[k]);
    }
    FOR(i, 0, 3) ans = max(ans, f(i));
    printf("%lld\n", ans);
    return 0;
}