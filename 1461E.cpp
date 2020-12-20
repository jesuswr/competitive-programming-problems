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
typedef __int128 lll;

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
const int MAXN = 2e6 + 10; // CAMBIAR ESTE

// GJNM
lll k, l, r, t, x, y;

void inp() {
    ll kk, LL, rr, tt, xx, yy; rll(kk, LL), rll(rr, tt), rll(xx, yy);
    k = kk; l = LL; r = rr; t = tt; x = xx; y = yy;
    r -= l;
    k -= l;
    l = 0;
}

void YES() {
    printf("YES\n");
    exit(0);
}
void NO() {
    printf("NO\n");
    exit(0);
}

void solve_equal() {
    if (k + y <= r)
        YES();
    if (k - x < 0)
        NO();
    YES();
}

void solve_greater() { // x > y
    if (k + y > r) {
        k -= x;
        if (x < 0)
            NO();
        t--;
        solve_greater();
    }
    lll loss = x - y;
    loss = loss * t;
    if (loss > k)
        NO();
    else
        YES();
}

bool vis[MAXN];

void simulate() {
    while (t > 0) {
        if (k <= r - y) {
            if (vis[k])
                YES();
            vis[k] = true;
            k += y;
            k -= x;
            t--;
        }
        else if (k > r - y && k < x)
            NO();
        else { // k >= x
            lll dist = k - (x - 1);
            lll moves = (dist + x - 1) / x;
            t -= moves;
            k -= moves * x;
        }
    }
    YES();
}

void solve_less() { // x < y
    if (r - y >= x)
        YES();
    else
        simulate();

}


int main() {
    inp();
    if (x == y)
        solve_equal();
    else if (x > y)
        solve_greater();
    else
        solve_less();

    return 0;
}