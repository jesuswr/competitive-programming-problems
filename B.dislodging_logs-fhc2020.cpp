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
const int maxN = 1000010; // CAMBIAR ESTE

// GJNM
ll n, m, k, s;
ll Ap, Bp, Cp, Dp, Aq, Bq, Cq, Dq;
ll p[maxN], q[maxN];
ll mn[maxN], mx[maxN], rem[maxN], act[maxN];

bool valid(ll moves) {
    FOR(i, 0, n) {
        mn[i] = mx[i] = act[i] = p[i];
    }

    int q_i = 0, p_i = 0;
    while (q_i < m && p_i < n) {
        if ( mn[p_i] <= q[q_i] && q[q_i] <= mx[p_i] ) {
            q_i++;
            continue;
        }

        mn[p_i] = min(mn[p_i], q[q_i]);
        mx[p_i] = max(mx[p_i], q[q_i]);
        ll need = 2ll * min(p[p_i] - mn[p_i], mx[p_i] - p[p_i]) + max(p[p_i] - mn[p_i], mx[p_i] - p[p_i]);
        if ( need > moves )
            p_i++;
        else
            q_i++;
    }

    return q_i == m;
}


void solve(int t) {
    rll(n, m), rll(k, s);
    FOR(i, 0, k) {
        rl(p[i]);
    }
    rll(Ap, Bp), rll(Cp, Dp);
    FOR(i, 0, k) {
        rl(q[i]);
    }
    rll(Aq, Bq), rll(Cq, Dq);
    FOR(i, k, n) {
        p[i] = ((Ap * p[i - 2] + Bp * p[i - 1] + Cp) % Dp) + 1;
    }
    FOR(i, k, m) {
        q[i] = ((Aq * q[i - 2] + Bq * q[i - 1] + Cq) % Dq) + 1;
    }
    sort(p, p + n);
    sort(q, q + m);

    ll lo = 0, hi = 5500000000ll;
    while (lo < hi) {
        ll mi = lo + ((hi - lo) >> 1);
        if ( valid(mi) )
            hi = mi;
        else
            lo = mi + 1;
    }
    printf("Case #%d: %lld\n", t, hi);
}

int main() {
    int t;
    ri(t);
    FOR(i, 0, t) {
        solve(i + 1);
    }

    return 0;
}