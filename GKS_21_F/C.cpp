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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct pto {
    long long x, y;
    pto(ld _x = 0, ld _y = 0): x(_x), y(_y) {}
    pto operator+(pto a) {return pto(x + a.x, y + a.y);}
    pto operator-(pto a) {return pto(x - a.x, y - a.y);}
    pto operator+(ld a) {return pto(x + a, y + a);}
    pto operator*(ld a) {return pto(x * a, y * a);}
    pto operator/(ld a) {return pto(x / a, y / a);}
    //dot product, producto interno:
    ld operator*(pto a) {return x * a.x + y * a.y;}
    //module of the cross product or vectorial product:
    //if a is less than 180 clockwise from b, a^b>0
    ll operator^(pto a) {return x * a.y - y * a.x;}
    //returns true if this is at the left side of line qr
    bool left(pto q, pto r) {return ((q - *this) ^ (r - *this)) > 0;}
    double norm() {return sqrt(x * x + y * y);}
    ld norm_sq() {return x * x + y * y;}
    void prnt() {
        cout << x << " " << y << " | ";
    }
};

void solve() {
    int n; ri(n);
    vector<pto> a(n);
    FOR(i, 0, n) {
        int x, y; rii(x, y);
        a[i].x = x, a[i].y = y;
    }
    FOR(i, 0, n) swap(a[i], a[rand() % n]);
    pto b;
    {
        int x, y; rii(x, y);
        b.x = x, b.y = y;
    }

    double ans = LLINF;
    bool fnd = false;
    for (auto &p1 : a) {
        for (auto &p2 : a) {
            if ((p2 - p1).norm() >= ans || !b.left(p1, p2))
                continue;
            for (auto &p3 : a) {
                if (b.left(p1, p2) && b.left(p2, p3) && b.left(p3, p1)) {
                    double perm = (p2 - p1).norm() + (p3 - p2).norm() + (p1 - p3).norm();
                    ans = min(ans, perm);
                    fnd = 1;
                }
            }
        }
    }
    for (auto &p1 : a) {
        for (auto &p2 : a) {
            if ((p2 - p1).norm() >= ans || !b.left(p1, p2))
                continue;
            for (auto &p3 : a) {
                if ((p3 - p2).norm() + (p2 - p1).norm() >= ans || !b.left(p1, p2) || !b.left(p2, p3))
                    continue;
                for (auto &p4 : a) {
                    if (b.left(p1, p2) && b.left(p2, p3) && b.left(p3, p4) && b.left(p4, p1)) {
                        double perm = (p2 - p1).norm() + (p3 - p2).norm() + (p4 - p3).norm() + (p1 - p4).norm();
                        ans = min(ans, perm);
                        fnd = 1;
                    }
                }
            }
        }
    }
    if (fnd)
        printf("%.9lF\n", ans);
    else
        printf("IMPOSSIBLE\n");
}


int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}