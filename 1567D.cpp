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
#include <assert.h>
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll P10[11];
bool is_p10(ll x) {
    FOR(i, 0, 11) if (x == P10[i])
        return true;
    return false;
}
ll split(ll x) {
    FOR(i, 0, 11) if (x <= P10[i])
        return P10[i] / 10;
}
void solve() {
    int s, n; rii(s, n);
    vi have; have.pb(s);
    while (SZ(have) < n) {
        ll x = -1;
        FOR(i, 0, SZ(have)) {
            if (!is_p10(have[i])) {
                x = have[i];
                have.erase(have.begin() + i);
                break;
            }
        }
        if (x == -1) {
            ll mn = 1e10;
            FOR(i, 0, SZ(have)) {
                if (have[i] != 1)
                    mn = min(mn, 1ll * have[i]);
            }
            FOR(i, 0, SZ(have)) {
                if (have[i] == mn) {
                    x = mn;
                    have.erase(have.begin() + i);
                    break;
                }
            }
        }

        have.pb(split(x));
        have.pb(x - split(x));
    }
    for (auto x : have) cout << x << " ";
    cout << endl;
}

int main() {
    P10[0] = 1;
    FOR(i, 1, 11) P10[i] = P10[i - 1] * 10;
    int t; ri(t);
    while (t--) solve();
    return 0;
}