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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
bool good[MAXN];
ll pre[MAXN];

void solve() {
    int a, b, q; riii(a, b, q);
    FOR(i, 0, a * b) {
        good[i] = ((i % a) % b) != ((i % b) % a);
    }
    pre[0] = good[0];
    FOR(i, 1, a * b) {
        pre[i] = pre[i - 1];
        pre[i] += good[i];
    }

    while (q--) {
        ll l, r; rll(l, r);
        ll ans = 0;

        ll cab = (l + a * b - 1) / (a * b);
        ll kab = r / (a * b);
        cab = cab * a * b;
        kab = kab * a * b;

        ans += pre[a * b - 1] * ((kab - cab) / (a * b));
        ans += pre[r - kab];
        ans += pre[(cab - 1) % (a * b)] - pre[(l - 1) % (a * b)];


        printf("%lld ", ans);
    }
    printf("\n");
}


int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
    }
    return 0;
}