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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
ll ans[MAXN];

int main() {
    int n, k;
    rii(n, k);

    ans[0] = 1;
    FOR(i, 1, MAXN) {
        ans[i] = (ans[i - 1] + (i - k >= 0 ? ans[i - k] : 0));
    }
    FOR(i, 1, MAXN) {
        ans[i] = (ans[i] + ans[i - 1]) % MOD;
    }

    FOR(i, 0, n) {
        int a, b;
        rii(a, b);
        printf("%lld\n", (ans[b] - ans[a - 1] + MOD) % MOD);
    }



    return 0;
}