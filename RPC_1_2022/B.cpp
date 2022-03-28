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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct ACfixed { // fixed alphabet
    static const int ASZ = 26;
    struct node { array<int, ASZ> to; int link; int out; bool leaf = false; vector<int> inds;};
    vector<node> d = {{}};
    int add(string s) { // add word
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
            if (v) {
                if (d[d[v].link].leaf) d[v].out = d[v].link;
                else d[v].out = d[d[v].link].out;
            }
        }
    }
};

int K[MAXN];
int P[MAXN];
int ANS[MAXN];
int szz[MAXN];

int main() {
    string S;
    cin >> S;
    ACfixed aho;
    int q; ri(q);
    FOR(_q, 0, q) {
        string t; cin >> t;
        int k; ri(k);
        --k;
        ANS[_q] = -2;
        szz[_q] = SZ(t);
        P[_q] = aho.add(t);
        K[_q] = k;
    }
    aho.init();
    int p = 0;
    FOR(i, 0, SZ(S)) {
        int nxt = S[i] - 'a';
        p = aho.d[p].to[nxt];
        int pp = p;
        while (pp > 0) {
            aho.d[pp].inds.pb(i);
            pp = aho.d[pp].out;
        }
    }
    FOR(_q, 0, q) {
        p = P[_q];
        if ((int)aho.d[p].inds.size() > K[_q]) {
            ANS[_q] = aho.d[p].inds[K[_q]] - szz[_q] + 1;
        }
    }
    FOR(i, 0, q) printf("%d\n", ANS[i] + 1);
    return 0;
}