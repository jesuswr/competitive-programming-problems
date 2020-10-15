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

int main() {
    ll xr, sm;
    rll(xr, sm);

    if (xr > sm) {
        printf("-1\n");
        return 0;
    }
    if (sm == 0) {
        printf("0\n");
        return 0;
    }

    vector<ll> ans;
    ans.pb(xr); ans.pb(0); ans.pb(0);
    sm -= xr;

    vector<ll> sm_bits;
    FOR(i, 0, 64) {
        if (sm & (1ll << (ll)i))
            sm_bits.pb(i);
    }

    int ans_sz = 1;
    for (auto b : sm_bits) {
        if (b == 0) {
            printf("-1\n");
            return 0;
        }
        if (xr & (1ll << (b - 1))) {
            ans_sz = 3;
            ans[1] |= (1ll << (b - 1));
            ans[2] |= (1ll << (b - 1));
        }
        else {
            ans_sz = max(2, ans_sz);
            ans[0] |= (1ll << (b - 1));
            ans[1] |= (1ll << (b - 1));
        }
    }

    printf("%d\n", ans_sz);
    FOR(i, 0, ans_sz) {
        printf("%lld%c", ans[i], " \n"[i == ans_sz - 1]);
    }

    return 0;
}