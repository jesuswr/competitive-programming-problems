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
const ll mod = 998244353;

// GJNM

void solve() {
    int n, k;
    rii(n, k);
    set<pii> have;
    vector<bool> need(n);
    vi index_of(n);
    vi ord;
    FOR(i, 0, n) {
        int aux;
        ri(aux);
        aux--;
        index_of[aux] = i;
        have.insert({i, aux});
    }
    FOR(i, 0, k) {
        int aux;
        ri(aux);
        aux--;
        ord.pb(aux);
        need[aux] = true;
    }
    ll ans = 1;
    for (auto x : ord) {
        int ind = index_of[x];
        auto it = have.find({ind, x});

        int lft = 0, right = 0;

        if (it != have.end()) {
            auto it2 = it;
            it2++;
            if (it2 != have.end()) {
                int y = it2->second;
                if (!need[y])
                    lft++;
            }
        }
        if (it != have.begin()) {
            auto it2 = it;
            it2--;
            int y = it2->second;
            if (!need[y])
                right++;
        }

        if (lft + right == 0) {
            printf("0\n");
            return;
        }

        ans = (ans * (lft + right)) % mod;
        have.erase(it);
    }
    printf("%lld\n", ans);
}


int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
    }

    return 0;
}