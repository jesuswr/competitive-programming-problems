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
#define rii(a,b) dadsadasda=scanf("%d %d\n", &a, &b)
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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll ANS[MAXN];

struct ACfixed { // fixed alphabet
    static const int ASZ = 26;
    struct node { array<int, ASZ> to; int link; int out; bool leaf = false; vi inds; ll cnt = 0;};
    vector<node> d = {{}};
    vi ord;
    int add(string s, int ind) { // add word
        int v = 0;
        for (auto C : s) {
            int c = C - 'A';
            if (!d[v].to[c]) d[v].to[c] = SZ(d), d.emplace_back();
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
        while (SZ(q)) {
            int v = q.front(); q.pop();
            ord.pb(v);
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
        reverse(ALL(ord));
    }
    void f() {
        for (auto i : ord) {
            if (d[i].link >= 0)
                d[d[i].link].cnt += d[i].cnt;
            for (auto j : d[i].inds)
                ANS[j] = d[i].cnt;
        }

    }
};

int N, Q;
char C[MAXN];
int P[MAXN];

int IND[MAXN];

int main() {
    rii(N, Q);
    FOR(i, 0, N) dadsadasda = scanf("%c %d\n", C + i, P + i);
    ACfixed aho;
    FOR(i, 0, Q) {
        string s;
        cin >> s; reverse(ALL(s));
        aho.add(s, i);
    }
    aho.init();
    FOR(i, 0, N) {
        int u = 0;
        if (P[i] > 0)
            u = IND[P[i] - 1];
        u = aho.d[u].to[C[i] - 'A'];
        aho.d[u].cnt++;
        IND[i] = u;
    }
    aho.f();
    FOR(i, 0, Q) printf("%lld\n", ANS[i]);

    return 0;
}