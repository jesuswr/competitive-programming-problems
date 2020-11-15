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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int n;
ll w;
ll a[MAXN];

void solve() {
    ri(n); rl(w);
    ll lo = (w + 1) / 2, hi = w;
    FOR(i, 0, n) {
        rl(a[i]);
    }

    FOR(i, 0, n) {
        if (a[i] > hi)
            a[i] = -1;
    }

    ll sm = 0, mn = LLINF, mx = 0;
    FOR(i, 0, n) {
        if (a[i] == -1)
            continue;
        sm += a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    if (sm < lo) {
        printf("-1\n");
        return;
    }

    priority_queue<pair<ll, int>> pq;

    sm = 0;
    FOR(i, 0, n) {
        if (a[i] == -1)
            continue;
        pq.push({ -a[i], i + 1});
        sm += a[i];
    }

    while (sm > hi && !pq.empty()) {
        auto p = pq.top();
        pq.pop(); p.F = -p.F;
        sm -= p.F;
    }

    if (sm < lo) {
        printf("-1\n");
    }
    else {
        set<int> inds;
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            inds.insert(p.S);
        }
        printf("%zu\n", inds.size());
        for (auto x : inds) {
            printf("%d ", x);
        } printf("\n");
    }

}


int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
    }
    return 0;
}