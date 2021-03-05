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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
struct pt {
    int x, y;
};
pt perp(pt p) {return { -p.y, p.x};}
pt sum(pt p1, pt p2) {return{p1.x + p2.x, p1.y + p2.y};}
pt subs(pt p1, pt p2) {return{p1.x - p2.x, p1.y - p2.y};}

pt PUNTOS[4][4];

ll dst(pt a, pt b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool valid(int a, int b, int c, int d) {
    vi aux = {a, b, c, d};
    vector<multiset<ll>> help;
    FOR(i, 0, 4) {
        multiset<ll> curr;
        FOR(j, 0, 4) {
            if (i == j) continue;
            if (dst(PUNTOS[i][aux[i]], PUNTOS[j][aux[j]]) == 0ll) return false;
            curr.insert(dst(PUNTOS[i][aux[i]], PUNTOS[j][aux[j]]));
        }
        help.pb(curr);
    }
    FOR(i, 0, 3) if (help[i] != help[i + 1]) return false;
    set<int> alo;
    for (auto x : help[0]) alo.insert(x);
    if (SZ(alo) > 2) return false;
    return true;
}

int main() {
    int t; ri(t);
    while (t--) {
        FOR(i, 0, 4) {
            pt pto, cntr;
            rii(pto.x, pto.y); rii(cntr.x, cntr.y);
            pto = subs(pto, cntr);

            PUNTOS[i][0] = pto;
            FOR(j, 1, 4) PUNTOS[i][j] = perp(PUNTOS[i][j - 1]);
            FOR(j, 0, 4) PUNTOS[i][j] = sum(PUNTOS[i][j], cntr);
        }
        int ans = INF;
        FOR(a, 0, 4)FOR(b, 0, 4)FOR(c, 0, 4)FOR(d, 0, 4) {
            if (valid(a, b, c, d)) ans = min(ans, a + b + c + d);
        }
        if (ans == INF) printf("-1\n");
        else printf("%d\n", ans);
    }

    return 0;
}