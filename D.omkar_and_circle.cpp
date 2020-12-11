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
int n;
int a[MAXN];
vi b;

int main() {
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    for (int i = 0; i < n; i += 2)
        b.pb(a[i]);
    for (int i = 1; i < n; i += 2)
        b.pb(a[i]);

    int k = (n + 1) >> 1;
    ll sm = 0;
    FOR(i, 0, k) {
        sm += b[i];
    }
    FOR(i, 0, n) {
        b.pb(b[i]);
    }

    ll mx = sm;
    FOR(i, k, 2 * n) {
        sm += b[i];
        sm -= b[i - k];
        mx = max(mx, sm);
    }

    printf("%lld\n", mx);
    return 0;
}