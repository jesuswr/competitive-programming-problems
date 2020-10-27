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
struct point_line {
    bool is_point;
    ll l, r;
};

bool comp(point_line &a, point_line &b) {
    if (a.l != b.l)
        return a.l < b.l;
    if (a.is_point)
        return false;
    if (b.is_point)
        return true;
    return a.r < b.r;
}

bool valid(ll n, ll s, vector<ll> &a, vector<ll> &b, ll d) {
    vector<point_line> swipe;
    ll points = 0, lines = 0;

    // a points, b lines
    int ai = 0, bi = 0, an = a.size(), bn = b.size();
    while (ai < an - 1 || bi < bn - 1) {
        point_line aux;
        if (a[ai] < max(0ll, b[bi] - d)) {
            if (a[ai] <= s) {
                aux.is_point = true;
                aux.l = a[ai];
                swipe.pb(aux);
                points++;
            }
            ai++;
        }
        else {
            if (b[bi] <= s) {
                aux.is_point = false;
                aux.l = max(0ll, b[bi] - d);
                aux.r = min(s - b[bi], b[bi] + d);
                swipe.pb(aux);
                lines++;
            }
            bi++;
        }
    }


    if (points < n || lines < n)
        return false;

    int cnt = 0;
    priority_queue<ll> pq;
    for (auto pl : swipe) {
        if (pl.is_point) {
            while (!pq.empty() && -pq.top() < pl.l)
                pq.pop();

            if (!pq.empty()) {
                pq.pop();
                cnt++;
            }
        }
        else {
            pq.push(-pl.r);
        }
        if (cnt >= n)
            return true;
    }
    return cnt >= n;
}



int main() {
    ll n, p, q, s; rll(n, p), rll(q, s);
    vector<ll> ps(p);
    FOR(i, 0, p) {
        rl(ps[i]);
    }
    vector<ll> qs(q);
    FOR(i, 0, q) {
        rl(qs[i]);
    }
    sort(ps.begin(), ps.end());
    sort(qs.begin(), qs.end());
    ps.pb(LLINF), qs.pb(LLINF);

    ll lo = 0, hi = s + 1;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        if (valid(n, s, ps, qs, mi) || valid(n, s, qs, ps, mi))
            hi = mi;
        else
            lo = mi + 1;
    }

    if (hi == s + 1)
        printf("-1\n");
    else
        printf("%lld\n", hi);


    return 0;
}