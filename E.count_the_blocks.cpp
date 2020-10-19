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
const ll MOD = 998244353;

// GJNM
ll bin_pow(ll b, ll e) {
    ll ret = 1;
    while (e > 0) {
        if (e & 1)
            ret = (ret * b) % MOD;
        e = e / 2;
        b = (b * b) % MOD;
    }
    return ret;
}

int main() {
    int n;
    ri(n);
    ll ans;
    FOR(i, 1, n) {
        ans = (2 * 10 * 9 * bin_pow(10, n - i - 1));
        ans = (ans + (n - i - 1) * 10 * 9 * 9 * bin_pow(10, n - i - 2)) % MOD;
        printf("%lld ", ans);
    }
    printf("10\n");

    return 0;
}