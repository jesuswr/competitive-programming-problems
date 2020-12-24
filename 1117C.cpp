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
const int MAXN = 1e5 + 1; // CAMBIAR ESTE

// GJNM
struct POINT {
    ll x, y;
    POINT operator+(POINT &b) {
        return {x + b.x, y + b.y};
    }
    POINT operator*(ll k) {
        return {k * x, k * y};
    }
    ll dist(POINT &b) {
        return abs(x - b.x) + abs(y - b.y);
    }
};

int n;
string s;
POINT PRE[MAXN];

void precompute() {
    FOR(i, 0, n) {
        PRE[i + 1].x = PRE[i + 1].y = 0;
        if (s[i] == 'U')
            PRE[i + 1].y = 1;
        else if (s[i] == 'D')
            PRE[i + 1].y = -1;
        else if (s[i] == 'L')
            PRE[i + 1].x = -1;
        else
            PRE[i + 1].x = 1;
    }
    FOR(i, 1, n + 1) PRE[i] = PRE[i] + PRE[i - 1];
}
POINT a, b;

bool valid(ll d) {
    POINT tmp = PRE[n] * (d / n);
    tmp = tmp + PRE[d % n];
    tmp = tmp + a;
    return b.dist(tmp) <= d;
}

int main() {
    rll(a.x, a.y);
    rll(b.x, b.y);
    ri(n);
    cin >> s;
    precompute();


    ll lo = 0, hi = 2e16;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        if (valid(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    if (hi > 2e15)
        printf("-1\n");
    else
        printf("%lld\n", hi);

    return 0;
}