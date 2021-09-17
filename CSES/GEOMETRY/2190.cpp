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
struct pto {
    ll x, y;
    pto(ll xx = 0, ll yy = 0): x(xx), y(yy) {}
    pto operator+(pto a) {return pto(x + a.x, y + a.y);}
    pto operator-(pto a) {return pto(x - a.x, y - a.y);}
    pto operator+(ll a) {return pto(x + a, y + a);}
    pto operator*(ll a) {return pto(x * a, y * a);}
    pto operator/(ll a) {return pto(x / a, y / a);}
    //dot product, producto interno:
    ll operator*(pto a) {return x * a.x + y * a.y;}
    //module of the cross product or vectorial product:
    //if a is less than 180 clockwise from b, a^b>0
    ll operator^(pto a) {return x * a.y - y * a.x;}
    //returns true if this is at the left side of line qr
    bool left(pto q, pto r) {return ((q - *this) ^ (r - *this)) > 0;}
    ld norm() {return sqrt(x * x + y * y);}
    ll norm_sq() {return x * x + y * y;}
};


void solve() {
    pto a, b, c, d;
    rll(a.x, a.y);
    rll(b.x, b.y);
    rll(c.x, c.y);
    rll(d.x, d.y);

    if (((b - a) ^ (d - c)) == 0) { // paralelas
        ll sgn1 = (a - c) ^ (b - c);
        if (sgn1 != 0) {
            printf("NO\n");
            return ;
        }
        FOR(_, 0, 2) {
            if (max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)) {
                printf("NO\n");
                return;
            }
            swap(a, c);
            swap(b, d);
        }
        printf("YES\n");
    }
    else {
        FOR(_, 0, 2) {
            ll sgn1 = (a - c) ^ (b - c), sgn2 = (a - d) ^ (b - d);
            if ((sgn1 > 0 && sgn2 > 0) || (sgn1 < 0 && sgn2 < 0)) {
                printf("NO\n");
                return;
            }
            swap(a, c);
            swap(b, d);
        }
        printf("YES\n");
    }
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}