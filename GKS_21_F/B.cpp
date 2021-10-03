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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

ll solve() {
    int d, n, k; riii(d, n, k);
    vector<vi> add(d + 69), del(d + 69);
    FOR(_, 0, n) {
        int h, s, e; riii(h, s, e);
        add[s].pb(h); del[e].pb(h);
    }
    ll ans = 0;
    ll cnt = 0;
    multiset<int> use, others;
    FOR(i, 1, d + 1) {
        for (auto h : add[i]) {
            if (SZ(use) < k) {
                use.insert(h);
                cnt += h;
            }
            else if (h > *use.begin()) {
                others.insert(*use.begin());
                cnt -= *use.begin();
                use.erase(use.begin());
                cnt += h;
                use.insert(h);
            }
            else
                others.insert(h);
        }

        ans = max(ans, cnt);

        for (auto h : del[i]) {
            if (others.find(h) != others.end())
                others.erase(others.find(h));
            else {
                cnt -= h;
                use.erase(use.find(h));
            }
        }
        while (SZ(use) < k && SZ(others) > 0) {
            int mx = *others.rbegin();
            cnt += mx;
            use.insert(mx);
            others.erase(others.find(mx));
        }

    }
    return ans;
}

int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: %lld\n", i, solve());
    }
    return 0;
}