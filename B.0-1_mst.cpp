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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int n, m;
vi E[MAXN];

int father[MAXN], siz[MAXN], cnt[MAXN];
set<int> reprs;
int find(int x) {
    if (father[x] == -1) // -1 significa que es el representante del set
        return x;
    return father[x] = find(father[x]);
}
void unio(int x, int y) { // x y y tienen que ser los representantes
    if (siz[x] > siz[y]) {
        father[y] = x;
        cnt[x] += cnt[y];
    }
    else {
        father[x] = y;
        cnt[y] += cnt[x];
        if ( siz[x] == siz[y] ) siz[y]++;
    }
}


int main() {
    rii(n, m);
    FOR(i, 0, m) {
        int a, b; rii(a, b); a--, b--;
        if (a > b) swap(a, b);
        E[b].pb(a);
    }
    FOR(x, 0, n) {
        father[x] = -1;
        siz[x] = 0;
        cnt[x] = 1;

        map<int, int> one_edges;
        for (int y : E[x])
            one_edges[find(y)]++;

        for (auto y : reprs)
            if (cnt[y] > one_edges[y])
                unio(y, find(x));

        reprs.insert(x);
        vi deletes;
        for (auto y : reprs)
            if (y != find(y))
                deletes.pb(y);
            
        for (auto d : deletes)
            reprs.erase(d);
    }
    printf("%d\n", SZ(reprs) - 1);
    return 0;
}