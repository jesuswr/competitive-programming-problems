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
void solve() {
    int n; ri(n);
    vi a;
    FOR(i, 0, n) {
        int tmp; ri(tmp); tmp--;
        if (a.empty() || a.back() != tmp)
            a.pb(tmp);
    }
    vi CNT(n), FIRST(n, INF), LAST(n, -1);
    FOR(i, 0, SZ(a)) {
        CNT[a[i]]++;
        FIRST[a[i]] = min(FIRST[a[i]], i);
        LAST[a[i]] = i;
    }
    int ans = INF;
    FOR(i, 0, SZ(a)) {
        ans = min(ans, CNT[a[i]] - 1 + (FIRST[a[i]] != 0) + (LAST[a[i]] != SZ(a) - 1));
    }
    printf("%d\n", ans);
}

int main() {
    int t; ri(t);
    while (t--)
        solve();

    return 0;
}