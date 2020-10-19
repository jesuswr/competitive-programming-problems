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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int n, k;
int a[MAXN];

bool valid_odd(int roof) {
    int cnt = 0;
    FOR(i, 0, n) {
        if (cnt & 1) {
            cnt++;
            continue;
        }
        if (a[i] <= roof)
            cnt++;
    }
    return cnt >= k;
}

bool valid_even(int roof) {
    int cnt = 0;
    FOR(i, 0, n) {
        if ((~cnt) & 1) {
            cnt++;
            continue;
        }
        if (a[i] <= roof)
            cnt++;
    }
    return cnt >= k;
}

int main() {
    rii(n, k);
    FOR(i, 0, n) {
        ri(a[i]);
    }

    int lo = 1, hi = 1e9;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (valid_odd(mi))
            hi = mi;
        else
            lo = mi + 1;
    }

    int ans = hi;

    lo = 1, hi = 1e9;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (valid_even(mi))
            hi = mi;
        else
            lo = mi + 1;
    }

    printf("%d\n", min(ans, hi));

    return 0;
}