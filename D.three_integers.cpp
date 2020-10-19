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
    int t;
    ri(t);
    while (t--) {
        ll a, b, c;
        ll aux_a, aux_b, aux_c;
        rll(a, b), rl(c);
        ll ans = LLINF;

        FOR(new_b, max(1ll, b - 10000), b + 10000) {
            ll new_a, new_c;
            ll cost_a = LLINF, cost_b, cost_c;

            cost_b = abs(b - new_b);

            if (cost_b >= ans)
                continue;

            for (ll j = 1; j * j <= new_b; j++) {
                if (new_b % j == 0) {
                    if ( abs(a - j) <= cost_a) {
                        cost_a = abs(a - j);
                        new_a = j;
                    }
                    if ( abs(a - new_b / j) <= cost_a) {
                        cost_a = abs(a - new_b / j);
                        new_a = new_b / j;
                    }
                }
            }

            if (cost_a + cost_b >= ans)
                continue;

            if (c - (c / new_b)*new_b <= ((c + new_b - 1) / new_b) * new_b - c) {
                cost_c = c - (c / new_b) * new_b;
                new_c = (c / new_b) * new_b;
            }
            else {
                cost_c = ((c + new_b - 1) / new_b) * new_b - c;
                new_c = ((c + new_b - 1) / new_b) * new_b;
            }

            if (ans > cost_a + cost_b + cost_c) {
                aux_a = new_a;
                aux_b = new_b;
                aux_c = new_c;
                ans = cost_a + cost_b + cost_c;
            }
        }
        printf("%lld\n", ans);
        printf("%lld %lld %lld\n", aux_a, aux_b, aux_c);
    }

    return 0;
}