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

// GJNM
int cst[6];
int typ[MAXN];

int solve(int n, int k, int btmsk) {
    int cnt = 0;
    FOR(i, 0, n) {
        if ((1 << typ[i]) & btmsk) {
            if (cst[typ[i]] <= k) {
                k -= cst[typ[i]];
                cnt++;
            }
        }
    }
    return cnt;
}


int main() {
    int n, k; rii(n, k);
    FOR(i, 0, 6) {
        ri(cst[i]);
    }
    FOR(i, 0, n) {
        ri(typ[i]);
        typ[i]--;
    }
    int ans = 0;
    FOR(b, 1, (1 << 6)) {
        ans = max(ans, solve(n, k, b));
    }
    printf("%d\n", ans);


    return 0;
}