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
const int MAXN = 1e6; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
const long double EPS = 0.0000001;

struct pto {
    ll x, y;
    pto(ll _x = 0, ll _y = 0): x(_x), y(_y) {}
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
    bool left(pto q, pto r) {return ((q - *this) ^ (r - *this)) >= 0;}
    bool left2(pto q, pto r) {return ((q - *this) ^ (r - *this)) > 0;}
    bool operator<(const pto &a) const {return x < a.x - EPS || (abs(x - a.x) < EPS && y < a.y - EPS);}
    bool operator==(pto a) {return abs(x - a.x) < EPS && abs(y - a.y) < EPS;}
};

int N;
pto A[MAXN];

bool compd(int i, int j) {
    if (A[i].x != A[j].x)
        return A[i].x < A[j].x;
    return A[i].y < A[j].y;
}
bool compu(int i, int j) {
    if (A[i].x != A[j].x)
        return A[i].x > A[j].x;
    return A[i].y > A[j].y;
}

void solve() {
    FOR(i, 0, N) rll(A[i].x, A[i].y);
    pto lft = A[0], rgt = A[0];
    FOR(i, 1, N) {
        if (A[i].x < lft.x)
            lft = A[i];
        else if (A[i].x == lft.x && A[i].y < lft.y)
            lft = A[i];
        if (A[i].x > rgt.x)
            rgt = A[i];
        else if (A[i].x == rgt.x && A[i].y > rgt.y)
            rgt = A[i];
    }
    vi d, u;
    FOR(i, 0, N) {
        if (A[i].left(lft, rgt)) {
            // printf("%d\n", i);
            u.pb(i);
        }
        else {
            // printf("\t%d\n", i);
            d.pb(i);
        }
    }
    if (d.empty()) {
        u.clear();
        d.clear();
        FOR(i, 0, N) {
            if (A[i].left2(lft, rgt))
                u.pb(i);
            else
                d.pb(i);
        }
    }


    sort(ALL(d), compd);
    sort(ALL(u), compu);
    printf("%d\n", N);
    for (auto i : d) printf("%lld %lld\n", A[i].x, A[i].y);
    for (auto i : u) printf("%lld %lld\n", A[i].x, A[i].y);
}


int main() {
    while (scanf("%d\n", &N) != EOF)
        solve();

    return 0;
}