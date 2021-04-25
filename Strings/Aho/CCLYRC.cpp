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
const int MAXN = 510; // CAMBIAR ESTE

// GJNM
int MP[300];

void pre() {
    int i = 0;
    for (char c = 'a'; c <= 'z'; c++) MP[(int)c] = i++;
    for (char c = 'A'; c <= 'Z'; c++) MP[(int)c] = i++;
    for (char c = '0'; c <= '9'; c++) MP[(int)c] = i++;
    MP['-'] = i;
}

ll CNT[MAXN];

struct ACfixed { // fixed alphabet
    static const int ASZ = 63;
    struct node { array<int, ASZ> to; int link; ll cnt; bool leaf = false; vi inds;};
    vector<node> d = {{}};
    vi bfs;
    int add(string s, int ind) { // add word
        int v = 0;
        for (auto C : s) {
            int c = MP[(int)C];
            if (!d[v].to[c]) d[v].to[c] = SZ(d), d.emplace_back();
            v = d[v].to[c];
        }
        d[v].inds.pb(ind);
        d[v].leaf = true;
        return v;
    }
    void init() { // generate links
        d[0].link = -1;
        queue<int> q; q.push(0);
        while (SZ(q)) {
            int v = q.front(); q.pop();
            bfs.pb(v);
            FOR(c, 0, ASZ) {
                int u = d[v].to[c]; if (!u) continue;
                d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
                q.push(u);
            }
            if (v) FOR(c, 0, ASZ) if (!d[v].to[c])
                    d[v].to[c] = d[d[v].link].to[c];
        }
    }
    void get_ans() {
        reverse(ALL(bfs));
        for (auto v : bfs) {
            if (d[v].link > 0) d[d[v].link].cnt += d[v].cnt;
            for (auto i : d[v].inds) CNT[i] = d[v].cnt;
        }
    }

};

int main() {
    pre();
    ACfixed aho;
    int n; ri(n);
    FOR(i, 0, n) {
        string s; cin >> s;
        aho.add(s, i);
    }

    aho.init();

    int m; ri(m);
    FOR(_, 0, m) {
        string s; cin >> s;
        int p = 0;
        for (auto x : s) {
            int c = MP[(int)x];
            p = aho.d[p].to[c];
            aho.d[p].cnt++;
        }
    }
    aho.get_ans();
    FOR(i, 0, n) printf("%lld\n", CNT[i]);
    return 0;
}