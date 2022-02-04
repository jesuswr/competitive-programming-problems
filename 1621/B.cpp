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
struct SEG
{
    int l, r, c;
};

void solve() {
    int n; ri(n);
    SEG mn, mx, lng;
    riii(mn.l, mn.r, mn.c);
    mx = lng = mn;
    printf("%d\n", mn.c);
    FOR(_, 1, n) {
        SEG a; riii(a.l, a.r, a.c);
        if (a.l < mn.l || (a.l == mn.l && a.c < mn.c))
            mn = a;
        if (a.r > mx.r || (a.r == mx.r && a.c < mx.c))
            mx = a;
        if ((a.r - a.l) > (lng.r - lng.l) || ((a.r - a.l) == (lng.r - lng.l) && a.c < lng.c))
            lng = a;
        if (lng.r - lng.l == mx.r - mn.l)
            printf("%d\n", min(lng.c, mx.c + mn.c));
        else
            printf("%d\n", mx.c + mn.c);
    }
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}