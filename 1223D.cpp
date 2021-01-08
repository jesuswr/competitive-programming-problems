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
// v.resize(distance(v.begin(), unique(all(v)))
int N;
vi v;
int A[MAXN];
int MN[MAXN], MX[MAXN];
int DP[MAXN];

int f(int p) {
    if (p == SZ(v) - 1) return 1;
    if (DP[p] != 0) return DP[p];
    DP[p] = 1;
    if (MX[v[p]] < MN[v[p + 1]]) DP[p] = 1 + f(p + 1);
    return DP[p];
}

void solve() {
    ri(N);
    FOR(i, 0, N) MN[i] = INF, MX[i] = -1, DP[i] = 0;
    FOR(i, 0, N) {
        ri(A[i]); --A[i];
        v.pb(A[i]);
        MN[A[i]] = min(MN[A[i]], i);
        MX[A[i]] = max(MX[A[i]], i);
    }
    sort(ALL(v));
    v.resize(distance(v.begin(), unique(ALL(v))));
    int mn = N;
    FOR(i, 0, SZ(v)) mn = min(mn, SZ(v) - f(i));
    printf("%d\n", mn);
    v.clear();
}



int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}