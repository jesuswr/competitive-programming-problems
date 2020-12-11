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

using namespace std;

typedef long long ll;
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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int n; ll S;
ll l[MAXN], r[MAXN];

bool valid(ll cst) {
    ll s = S;
    int cnt = 0;
    int need = (n + 1) / 2;
    priority_queue<ll> pq;

    FOR(i, 0, n) {
        if (r[i] < cst)
            s -= l[i];
        else if (cst < l[i]) {
            cnt++;
            s -= l[i];
        }
        else
            pq.push(l[i]);
    }

    if (cnt + SZ(pq) < need)
        return false;

    while (cnt < need) {
        pq.pop();
        cnt++;
        s -= cst;
    }

    while (!pq.empty()) {
        s -= pq.top();
        pq.pop();
    }
    return s >= 0;
}



void solve() {
    ri(n); rl(S);
    FOR(i, 0, n) {
        rll(l[i], r[i]);
    }

    ll lo = 1, hi = 2e14;
    while (lo < hi) {
        ll mi = lo + (hi - lo + 1) / 2;
        if (valid(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    printf("%lld\n", lo);
}


int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}