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
typedef long double ld;
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
const int MAXN = 1010; // CAMBIAR ESTE

// GJNM
ld EPS = 1e-18;

struct pto {
    ld x, y;
    pto(ld x = 0, ld y = 0): x(x), y(y) {}
    pto operator+(pto a) {return pto(x + a.x, y + a.y);}
    pto operator-(pto a) {return pto(x - a.x, y - a.y);}
    pto operator+(ld a) {return pto(x + a, y + a);}
    pto operator*(ld a) {return pto(x * a, y * a);}
    pto operator/(ld a) {return pto(x / a, y / a);}
    //dot product, producto interno:
    ld operator*(pto a) {return x * a.x + y * a.y;}
    //module of the cross product or vectorial product:
    //if a is less than 180 clockwise from b, a^b>0
    ld operator^(pto a) {return x * a.y - y * a.x;}
    //returns true if this is at the left side of line qr
    bool left(pto q, pto r) {return ((q - *this) ^ (r - *this)) > 0;}
    bool operator<(const pto &a) const {return x < a.x - EPS || (abs(x - a.x) < EPS && y < a.y - EPS);}
    bool operator==(pto a) {return abs(x - a.x) < EPS && abs(y - a.y) < EPS;}
    ld norm() {return sqrt(x * x + y * y);}
    ld norm_sq() {return x * x + y * y;}
};

int n;
pto points[MAXN];
vector<pto> poly[10];
ld pi = 2 * acos(0);
ld bigger_area[10];
ld smaller_area[10];

void normalize(vector<pto> &pt) { //delete collinear points first!
    //this makes it clockwise:
    if (pt[2].left(pt[0], pt[1])) reverse(pt.begin(), pt.end());
    int n = pt.size(), pi = 0;
    FOR(i, 0, n)
    if (pt[i].x < pt[pi].x || (pt[i].x == pt[pi].x && pt[i].y < pt[pi].y))
        pi = i;
    vector<pto> shift(n);//puts pi as first point
    FOR(i, 0, n) shift[i] = pt[(pi + i) % n];
    pt.swap(shift);
}
bool inPolygon(pto p, const vector<pto> &pt) {
    //call normalize first!
    if (p.left(pt[0], pt[1]) || p.left(pt[pt.size() - 1], pt[0])) return false;
    int a = 1, b = pt.size() - 1;
    while (b - a > 1) {
        int c = (a + b) / 2;
        if (!p.left(pt[0], pt[c])) a = c;
        else b = c;
    }
    return !p.left(pt[a], pt[a + 1]);
}

ld calc_area(int k, ld mi) {
    ld alpha = (2 * pi) / k;
    ld side = sin(alpha / 2) * mi * 2;
    ld ap = cos(alpha / 2) * mi;
    side = k * side;
    return (side * ap) / 2;

}
// 2.56 1.43
int main() {
    ri(n);
    FOR(i, 0, n) {
        ld a, b;
        scanf("%Lf %Lf", &a, &b);
        points[i] = pto(a, b);
    }

    FOR(i, 3, 9) {
        ld jump = (2 * pi) / i;
        FOR(j, 0, i) {
            ld x = cos(j * jump), y = sin(j * jump);
            poly[i].pb(pto(x, y));
        }
    }

    FOR(i, 3, 9) {
        ld lo = 0, hi = 1e15;
        FOR(_, 0, 200) { // bigger that doesnt contain
            vector<pto> aux;
            ld mi = (hi + lo) / 2;

            for (auto p : poly[i])
                aux.pb(pto(p.x * mi, p.y * mi));
            normalize(aux);


            bool good = true;
            FOR(j, 0, n) {
                if (inPolygon(points[j], aux))
                    good = false;
            }

            if (good)
                lo = mi;
            else
                hi = mi;
        }
        bigger_area[i] = lo;
    }

    FOR(i, 3, 9) {
        ld lo = 0, hi = 1e15;
        FOR(_, 0, 200) { // smaller that contains all
            vector<pto> aux;
            ld mi = (hi + lo) / 2;

            for (auto p : poly[i])
                aux.pb(pto(p.x * mi, p.y * mi));
            normalize(aux);


            bool good = true;
            FOR(j, 0, n) {
                if (!inPolygon(points[j], aux))
                    good = false;
            }

            if (good)
                hi = mi;
            else
                lo = mi;
        }
        smaller_area[i] = hi;
    }

    int ind;
    long double ans = 0;
    FOR(i, 3, 9) {
        ld temp = calc_area(i, bigger_area[i]) / calc_area(i, smaller_area[i]);
        if (temp > ans) {
            ans = temp;
            ind = i;
        }
    }
    printf("%d %Lf\n", ind, ans);

    return 0;
}