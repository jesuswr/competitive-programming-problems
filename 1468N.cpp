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
ll c[4];
ll a[6];

int main() {
    int t; ri(t);
    while (t--) {
        FOR(i, 0, 3) rl(c[i]);
        FOR(i, 0, 5) rl(a[i]);
        FOR(i, 0, 3) c[i] -= a[i];
        bool ans = true;
        FOR(i, 0, 3) if (c[i] < 0) ans = false;

        a[3] -= min(c[0], a[3]); a[4] -= min(c[1], a[4]);
        if (a[3] + a[4] > c[2]) ans = false;

        if (ans) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}