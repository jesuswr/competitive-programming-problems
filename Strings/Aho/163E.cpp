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
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
int Q, K;
int IND[MAXN];
bool ADD[MAXN];
vi G[MAXN];

struct ACfixed { // fixed alphabet
    static const int ASZ = 26;
    struct node { array<int, ASZ> to; int link; bool leaf = false;};
    vector<node> d = {{}};
    int add(const string &s) { // add word
        int v = 0;
        for (auto C : s) {
            int c = C - 'a';
            if (!d[v].to[c]) d[v].to[c] = SZ(d), d.emplace_back();
            v = d[v].to[c];
        }
        d[v].leaf = true;
        return v;
    }
    void init() { // generate links
        d[0].link = -1;
        queue<int> q; q.push(0);
        while (SZ(q)) {
            int v = q.front(); q.pop();
            FOR(c, 0, ASZ) {
                int u = d[v].to[c]; if (!u) continue;
                d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
                q.push(u);
            }
            if (v) FOR(c, 0, ASZ) if (!d[v].to[c])
                    d[v].to[c] = d[d[v].link].to[c];
            if (v)
                G[d[v].link].pb(v);
        }
    }
};

ll BIT[2 * MAXN];
void updBIT(int p, ll val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < 2 * MAXN; p += p & -p) // se puede cambiar maxN por n+5 si hace falta mas velocidad
        BIT[p] += val;
}
ll sumBIT(int p) {
    p++;
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

int IN[2 * MAXN], OUT[2 * MAXN], T;
void dfs(int u) {
    IN[u] = T++;
    for (auto v : G[u]) dfs(v);
    OUT[u] = T++;
}


int main() {
    rii(Q, K);
    ACfixed aho;
    FOR(i, 0, K) {
        string s; cin >> s;
        IND[i] = aho.add(s);
        ADD[i] = true;
    }
    aho.init();
    dfs(0);
    FOR(i, 0, K) {
        updBIT(IN[IND[i]], 1);
        updBIT(OUT[IND[i]], -1);
    }

    while (Q--) {
        char t;
        dadsadasda = scanf("%*c%c", &t);
        if (t == '-') {
            int v; ri(v); --v;
            if (ADD[v]) {
                ADD[v] = false;
                updBIT(IN[IND[v]], -1);
                updBIT(OUT[IND[v]], 1);
            }
        }
        else if (t == '+') {
            int v; ri(v); --v;
            if (!ADD[v]) {
                ADD[v] = true;
                updBIT(IN[IND[v]], 1);
                updBIT(OUT[IND[v]], -1);
            }
        }
        else {
            string s; cin >> s;
            ll ans = 0;
            int p = 0;
            for (auto c : s) {
                p = aho.d[p].to[c - 'a'];
                ans += sumBIT(IN[p]);
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}