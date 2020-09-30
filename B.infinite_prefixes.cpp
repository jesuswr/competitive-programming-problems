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

void solve() {
    int n; ri(n);
    ll x; rl(x);
    string s; cin >> s;
    ll tot_cnt = 0;
    for (auto c : s) {
        tot_cnt += (c == '0' ? 1 : -1);
    }
    ll curr_cnt = 0;
    FOR(i, 0, n) {
        curr_cnt += (s[i] == '0' ? 1 : -1);
        if (tot_cnt == 0 && curr_cnt == x) {
            printf("-1\n");
            return;
        }
    }

    curr_cnt = 0;
    ll ans = 0;
    if (x == 0)
        ans++;
    if (x == 0 && tot_cnt == 0){
        printf("-1\n");
        return;
    }
    FOR(i, 0, n) {
        curr_cnt += (s[i] == '0' ? 1 : -1);
        ll need = x - curr_cnt;
        if (need == 0)
            ans++;
        if (need < 0 && tot_cnt < 0) {
            if ( abs(need) % abs(tot_cnt) == 0)
                ans++;
        }
        if (need > 0 && tot_cnt > 0) {
            if ( need % tot_cnt == 0 )
                ans++;
        }
    }
    printf("%lld\n", ans);
}


int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}