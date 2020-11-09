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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 200010; // CAMBIAR ESTE

// GJNM
int n;
ll a[MAXN];


int main() {
    ri(n);
    FOR(i, 0, n) {
        rl(a[i]);
    }
    FOR(i, 1, n) {
        a[i] += a[i - 1];
    }
    ll x = 0;
    ll ans = 0;
    ll mx_move = 0;
    FOR(i, 0, n) {
        ans = max(ans, x + mx_move);
        mx_move = max(mx_move, a[i]);
        ans = max(ans, x + a[i]);
        x += a[i];
    }
    printf("%lld\n", ans);

    return 0;
}