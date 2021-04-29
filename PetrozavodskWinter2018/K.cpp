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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
struct ACfixed { // fixed alphabet
    static const int ASZ = 26;
    struct node { array<int, ASZ> to; int link; int out; bool leaf = false; vi inds;};
    vector<node> d = {{}};
    int add(string s, int ind) { // add word
        int v = 0;
        for (auto C : s) {
            int c = C - 'a';
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
            FOR(c, 0, ASZ) {
                int u = d[v].to[c]; if (!u) continue;
                d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
                q.push(u);
            }
            if (v) FOR(c, 0, ASZ) if (!d[v].to[c])
                    d[v].to[c] = d[d[v].link].to[c];
            if (v) FOR(c, 0, ASZ) {
                if (d[d[v].link].leaf) d[v].out = d[v].link;
                else d[v].out = d[d[v].link].out;
            }
        }
    }
};

int N, M;
string S;
int SZs[MAXN];
int ANS[MAXN], PREV[MAXN];


int main() {
    rii(N, M);
    cin >> S;
    ACfixed aho;
    FOR(i, 0, M) {
        string tmp; cin >> tmp;
        aho.add(tmp, i);
        SZs[i] = SZ(tmp);
        PREV[i] = -INF;
    }
    aho.init();

    int p = 0;
    FOR(i, 0, SZ(S)) {
        int c = S[i] - 'a';
        p = aho.d[p].to[c];
        int auxp = p;
        while (auxp != -1) {
            for (auto ind : aho.d[auxp].inds) {
                if (i - PREV[ind] >= SZs[ind]) {
                    ++ANS[ind];
                    PREV[ind] = i;
                }
            }
            auxp = aho.d[auxp].out;
        }
    }

    FOR(i, 0, M) printf("%d\n", ANS[i]);

    return 0;
}