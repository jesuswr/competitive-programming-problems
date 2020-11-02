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

// GJNM
ll n;
vector<ll> divs;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// esto da un x0 y y0 tal que a * x0 + b * y0 = c
// no maneja el caso b == 0 y a == 0
// para conseguir otras soluciones x0 += k*(b/g) y y0 -= k*(a/g)
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


void tryy(ll d) {
    ll a = d;
    ll b = n / d;
    ll x, y, g;
    if (!find_any_solution(a, b, n - 1, x, y, g))
        return;

    if (y < 0) {
        ll dist = (abs(y)) / (a / g);
        x -= dist * (b / g);
        y += dist * (a / g);
        if (y < 0) {
            x -= b / g;
            y += a / g;
        }
    }

    if (y < 0 || x < 0)
        return;

    swap(a, b);
    ll need_a = (x + a - 2) / (a - 1);
    ll need_b = (y + b - 2) / (b - 1);
    if (need_a + need_b > 100000)
        return;


    printf("YES\n");
    printf("%lld\n", need_a + need_b);
    FOR(i, 0, need_a) {
        ll out = min(x, a - 1);
        x -= out;
        printf("%lld %lld\n", out, a);
    }
    FOR(i, 0, need_b) {
        ll out = min(y, b - 1);
        y -= out;
        printf("%lld %lld\n", out, b);
    }

    exit(0);
}

int main() {
    rl(n);
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divs.pb(i);
            divs.pb(n / i);
        }
    }

    for (auto d : divs)
        tryy(d);

    printf("NO\n");
    return 0;
}