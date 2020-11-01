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
bool valid(ll a, ll b, ll c, ll d, ll mn) {
    ll need = 0;
    need += max(0ll, mn - a);
    need += max(0ll, mn - b);
    need += max(0ll, mn - c);
    return need <= d;
}

int main() {
    int n;
    ri(n);
    while (n--) {
        ll a, b, c, d;
        rll(a, b), rll(c, d);
        ll ans = 0;
        ll mnn = 0;
        while (mnn <= 1000 && valid(a, b, c, d, mnn)) {
            ll new_a = a;
            ll new_b = b;
            ll new_c = c;
            ll new_d = d;

            ll need = 0;

            need += max(0ll, mnn - new_a);
            new_a = max(new_a, mnn);
            need += max(0ll, mnn - new_b);
            new_b = max(new_b, mnn);
            need += max(0ll, mnn - new_c);
            new_c = max(new_c, mnn);

            new_d -= need;

            ll mn = min({new_a, new_b, new_c});
            ll mx = max({new_a, new_b, new_c});
            ll md = mn ^ mx ^ new_a ^ new_b ^ new_c;
            mx += new_d;

            ans = max(ans, mx * mx + md * md + mn * mn + 7 * mn);

            mnn++;
        }
        printf("%lld\n", ans);
    }

    return 0;
}