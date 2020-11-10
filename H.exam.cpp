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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
ll dp[10010];

int main() {
    ll n, k;
    rll(n, k);
    FOR(x, 2, n) {
        dp[1] = 1;
        FOR(i, 2, n + 1) {
            dp[i] = dp[i - 1];
            if (i % 7 == 0)
                dp[i] += dp[i / 7];
            if (i - x >= 1)
                dp[i] += dp[i - x];
        }
        if (dp[n] == k){
            printf("%d\n", x);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}