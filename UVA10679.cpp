#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct ACfixed { // fixed alphabet
    static const int ASZ = 52;
    struct node { array<int, ASZ> to; int link; int out; bool leaf = false; vi inds; bool fnd = false;};
    vector<node> d = {{}};
    stack<int> ord;
    int add(string s, int ind) { // add word
        int v = 0;
        for (auto C : s) {
            if ((int)C >= 97) C -= 6;
            int c = C - 'A';
            if (!d[v].to[c]) d[v].to[c] = sz(d), d.emplace_back();
            v = d[v].to[c];
        }
        d[v].inds.pb(ind);
        d[v].leaf = true;
        return v;
    }
    void init() { // generate links
        d[0].link = -1;
        d[0].out = -1;
        queue<int> q; q.push(0);
        while (sz(q)) {
            int v = q.front(); q.pop();
            ord.push(v);
            FOR(c, 0, ASZ) {
                int u = d[v].to[c]; if (!u) continue;
                d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
                q.push(u);
            }
            if (v) FOR(c, 0, ASZ) if (!d[v].to[c])
                    d[v].to[c] = d[d[v].link].to[c];
            if (v) {
                if (d[d[v].link].leaf) d[v].out = d[v].link;
                else d[v].out = d[d[v].link].out;
            }
        }
    }
};


void solve() {
    string s; cin >> s;
    int q; ri(q);
    vi inds(q);
    ACfixed aho;
    FOR(i, 0, q) {
        string t; cin >> t;
        inds[i] = aho.add(t, i);
    }
    aho.init();

    int p = 0;
    for (char C : s) {
        if ((int)C >= 97) C -= 6;
        int c = C - 'A';
        p = aho.d[p].to[c];
        aho.d[p].fnd = 1;
    }

    while (!aho.ord.empty()) {
        int u = aho.ord.top(); aho.ord.pop();
        if (aho.d[u].out != -1) aho.d[ aho.d[u].out ].fnd |= aho.d[u].fnd;
    }

    FOR(i,0,q) printf("%c\n", (aho.d[ inds[i] ].fnd ? 'y' : 'n') );
}

int main() {
    int k; ri(k);
    while (k--) solve();
    return 0;
}
