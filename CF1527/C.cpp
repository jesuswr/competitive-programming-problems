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

// GJNM
int N;
int A[MAXN];
ll CNT[MAXN];
ll DP[MAXN];

void comp() {
    map<int, int> new_a;
    FOR(i, 0, N) new_a[A[i]] = i;
    FOR(i, 0, N) A[i] = new_a[A[i]];
    FOR(i, 0, N) DP[i] = CNT[i] = 0;
}

void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    comp();
    ll ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        DP[i] = CNT[A[i]];
        CNT[A[i]] += N - i;
        ans = ans + (i + 1ll) * DP[i];
    }
    printf("%lld\n", ans);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}