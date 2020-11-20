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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
ll a[MAXN];

void solve() {
    ri(n);
    ll mx = 0;
    ll sm = 0;
    FOR(i, 0, n) {
        rl(a[i]);
        mx = max(mx, a[i]);
        sm += a[i];
    }

    // tot sum has to be k*(n-1) for some k
    // k >= mx

    ll s = mx * (n - 1);
    if (s >= sm) {
        printf("%lld\n", s - sm);
        return;
    }

    // if mx * (n-1) < sm then k > mx, so look for k such that k*(n-1) >= sm
    s = (sm + n - 2) / (n - 1);
    s = s * (n - 1);
    printf("%lld\n", s - sm);
}

int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}