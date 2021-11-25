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
struct ACfixed { // fixed alphabet
    static const int ASZ = 26;
    struct node { array<int, ASZ> to; int link; int out; int mn, mx; bool leaf = false; vi inds;};
    vector<node> d = {{}};
    stack<int> ord;
    int add(string s, int ind) { // add word
        int v = 0;
        d[v].mn = 1e9;
        d[v].mx = -1e9;
        for (auto C : s) {
            int c = C - 'A';
            if (!d[v].to[c]) d[v].to[c] = SZ(d), d.emplace_back();
            v = d[v].to[c];
            d[v].mn = 1e9;
            d[v].mx = -1e9;
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
            ord.push(v);
            FOR(c, 0, ASZ) {
                int u = d[v].to[c]; if (!u) continue;
                d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
                q.push(u);
            }
            if (v) FOR(c, 0, ASZ) if (!d[v].to[c])
                    d[v].to[c] = d[d[v].link].to[c];
            if (d[d[v].link].leaf) d[v].out = d[v].link;
            else d[v].out = d[d[v].link].out;
        }
    }

    void f() {
        while (!ord.empty()) {
            int v = ord.top(); ord.pop();
            if (v) {
                d[ d[v].link ].mx = max( d[d[v].link].mx, d[v].mx );
                d[ d[v].link ].mn = min( d[d[v].link].mn, d[v].mn );
            }
        }
    }
};

string PAT[100];
int MN[100][1010], MX[100][1010];

int main() {
    string TXT; cin >> TXT;
    int m; ri(m);
    ACfixed aho, ahor;
    FOR(i, 0, m) {
        string pat; cin >> pat;
        PAT[i] = pat;
        aho.add(pat, i);
        reverse(ALL(pat));
        ahor.add(pat, i);
    }
    aho.init();
    ahor.init();
    int v = 0;
    FOR(i, 0, SZ(TXT)) {
        int c = TXT[i] - 'A';
        v = aho.d[v].to[c];
        aho.d[v].mx = max(aho.d[v].mx, i);
        aho.d[v].mn = min(aho.d[v].mn, i);
        // printf("%d : %d %d\n", v, aho.d[v].mn, aho.d[v].mx);
    }
    aho.f();

    v = 0;
    for (int i = SZ(TXT) - 1; i >= 0; --i) {
        int c = TXT[i] - 'A';
        v = ahor.d[v].to[c];
        ahor.d[v].mx = max(ahor.d[v].mx, i);
        ahor.d[v].mn = min(ahor.d[v].mn, i);
        // printf("%d : %d %d\n", v, ahor.d[v].mn, ahor.d[v].mx);
    }
    ahor.f();

    int ans = 0;
    FOR(i, 0, m) {
        // cout << PAT[i] << endl;
        v = 0;
        for (int j = 0; j < SZ(PAT[i]); ++j) {
            int c = PAT[i][j] - 'A';
            v = aho.d[v].to[c];
            MN[i][j] = aho.d[v].mn;
        }
        v = 0;
        for (int j = SZ(PAT[i]) - 1; j >= 0; --j) {
            int c = PAT[i][j] - 'A';
            v = ahor.d[v].to[c];
            MX[i][j] = ahor.d[v].mx;
        }
        FOR(j, 0, SZ(PAT[i]) - 1) if (MN[i][j] < MX[i][j + 1]) {
            ans++;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}