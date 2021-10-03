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
struct P {
    ll x, y;
    int i;
    P(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
    ld abs() {
        return sqrt(x * x + y * y);
    }
    ll cross(P b) {
        return std::abs(x * b.y - y * b.x);
    }
    ld dst(P b) {
        return cross(b) / (abs() * b.abs());
    }
    ld norm_dst(P b) {
        ld _x = x / abs(), _y = y / abs();
        ld _x2 = b.x / b.abs(), _y2 = b.y / b.abs();
        ld dx = (_x - _x2), dy = (_y - _y2);
        // printf("(%lld, %lld) (%lld, %lld) : %Lf\n", x, y, b.x, b.y, sqrt(dx * dx + dy * dy));
        return sqrt(dx * dx + dy * dy);
    }
    int top() {
        if (x > 0 && y >= 0) return 0;
        if (x <= 0 && y > 0) return 1;
        if (x < 0 && y <= 0) return 2;
        return 3;
    }
    bool operator<(P b) {
        if (top() != b.top())
            return top() < b.top();
        if (top() == 0) {
            P r(1, 0);
            return dst(r) < b.dst(r);
        }
        else if (top() == 1) {
            P r(0, 1);
            return dst(r) < b.dst(r);
        }
        else if (top() == 2) {
            P r(-1, 0);
            return dst(r) < b.dst(r);
        }
        else if (top() == 3) {
            P r(0, -1);
            return dst(r) < b.dst(r);
        }
    }
};

int main() {
    int n; ri(n);
    vector<P> a;
    FOR(i, 0, n) {
        int x, y; rii(x, y);
        a.pb(P(x, y));
        a[i].i = i;
    }
    sort(ALL(a));
    ld mn = INF; int u, v;
    FOR(i, 0, n) if (a[i].norm_dst(a[(i + 1) % n]) < mn) {
        mn = a[i].norm_dst(a[(i + 1) % n]);
        u = a[i].i + 1;
        v = a[(i + 1) % n].i + 1;
    }
    printf("%d %d\n", u, v);
    return 0;
}