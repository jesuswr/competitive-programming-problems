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
ll l[MAXN];
int ans[MAXN];

int main() {
    int n, m;
    rii(n, m);
    memset(ans, -1, sizeof(ans));

    ll tot = 0;
    FOR(i, 0, m) {
        rl(l[i]);
        tot += l[i];
    }

    if (tot < n) {
        printf("-1\n");
        return 0;
    }
    FOR(i, 0, m) {
        if (n - l[i] < i){
            printf("-1\n");
            return 0;
        }
    }

    FOR(i, 0, m) {
        ans[i] = (i == m - 1 ? l[i] : 1);
        n -= ans[i];
    }
    ROF(i, m - 2, -1) {
        ans[i] += min((int)l[i] - 1, n);
        n = n - min((int)l[i] - 1, n);
    }
    int curr = 1;
    FOR(i, 0, m) {
        printf("%d ", curr);
        curr = curr + ans[i];
    } printf("\n");


    return 0;
}