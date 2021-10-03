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
#include <unordered_set>

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

void solve() {
    int n, m; rii(n, m);
    priority_queue< pii > pq;
    FOR(i, 0, m) {
        int a; ri(a);
        pq.push({0, a});
    }
    FOR(_, 0, n) {
        priority_queue< pii > new_pq;
        unordered_multiset<int> cnt;
        vi rem;
        FOR(i, 0, m) {
            int a; ri(a);
            cnt.insert(a);
        }

        while (!pq.empty()) {
            auto [cu, u] = pq.top(); pq.pop();
            if (cnt.find(u) != cnt.end()) {
                cnt.erase(cnt.find(u));
                new_pq.push({cu, u});
            }
            else {
                rem.pb(cu);
            }
        }
        for (auto cu : rem) {
            int u = *cnt.begin();
            cnt.erase(cnt.find(u));
            new_pq.push({cu + 1, u});
        }
        swap(pq, new_pq);
    }
    ll ans = 0;
    while (!pq.empty()) {
        ans += max(pq.top().F - 1, 0);
        pq.pop();
    }
    printf("%lld\n", ans);
}



int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}