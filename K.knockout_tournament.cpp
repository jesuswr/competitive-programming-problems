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
struct node {
    vector<pair<int, long double>> players;
};

node merge(node &a, node &b) {
    node c;
    for (auto px : a.players) {
        long double prob = 0;
        for (auto py : b.players) {
            if (abs(px.F) + abs(py.F) == 0)
                continue;
            prob += (py.S * px.S * ((long double)abs(px.F) / (long double)(abs(px.F) + abs(py.F))));
        }
        c.players.pb({px.F, prob});
    }

    for (auto px : b.players) {
        long double prob = 0;
        for (auto py : a.players) {
            if (abs(px.F) + abs(py.F) == 0)
                continue;
            prob += (py.S * px.S * ((long double)abs(px.F) / (long double)(abs(px.F) + abs(py.F))));
        }
        c.players.pb({px.F, prob});
    }

    return c;
}




int n;
vector<node> a;

bool comp(node &a, node &b) {
    return a.players[0].F < b.players[0].F;
}

int main() {
    ri(n);
    FOR(i, 0, n) {
        int aux; ri(aux);
        node help;
        if (i == 0)
            help.players.pb({ -aux, 1});
        else
            help.players.pb({aux, 1});
        a.pb(help);
    }
    sort(all(a), comp);

    if (__builtin_popcount(n) > 1) {
        int aux = 1;
        while (2 * aux < n)
            aux = aux * 2;
        int extra = n - aux;
        int not_extra = n - extra - extra;
        vector<node> b;
        FOR(i, 0, not_extra) {
            b.pb(a[i]);
        }
        int ind = not_extra;
        while (extra--) {
            b.pb(merge(a[ind], a[ind + 1]));
            ind += 2;
        }
        swap(a, b);
    }

    int n = a.size();
    while (n > 1) {
        n = n / 2;
        vector<node> b;
        FOR(i, 0, n) {
            b.pb(merge(a[2 * i], a[2 * i + 1]));
        }
        swap(a, b);
    }
    long double ans;
    for (auto n : a) {
        for (auto p : n.players) {
            if (p.F < 0)
                ans = p.S;
        }
    }
    printf("%.8Lf\n", ans);

    return 0;
}