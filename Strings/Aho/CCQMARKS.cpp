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
struct ACfixed { // fixed alphabet
    static const int ASZ = 26;
    struct node { array<int, ASZ> to; int link; int leaf; int cnt;};
    vector<node> d = {{}};
    int add(const string &s) { // add word
        int v = 0;
        for (auto C : s) {
            int c = C - 'a';
            if (!d[v].to[c]) d[v].to[c] = SZ(d), d.emplace_back();
            v = d[v].to[c];
        }
        d[v].leaf++;
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
                d[v].cnt += d[d[v].link].cnt + d[v].leaf;
        }
    }
};

ll DP[1010][1010];

int main() {
    int t; ri(t);
    while (t--) {
        ACfixed aho;
        int n, m; rii(n, m);
        string txt; cin >> txt;
        FOR(_, 0, m) {
            string s; cin >> s;
            aho.add(s);
        }
        aho.init();

        m = SZ(aho.d);
        for (int j = 0; j < m; ++j) DP[n][j] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int curr = i, nxt = curr + 1;
            for (int j = 0; j < m; ++j) DP[curr][j] = 0;
            for (int j = 0; j < m; ++j) {
                if (txt[i] == '?') {
                    FOR(k, 0, 26) {
                        DP[curr][j] =
                            max(
                                DP[curr][j],
                                DP[nxt][aho.d[j].to[k]] + aho.d[aho.d[j].to[k]].cnt
                            );
                    }
                }
                else {
                    int k = txt[i] - 'a';
                    DP[curr][j] =
                        max(
                            DP[curr][j],
                            DP[nxt][aho.d[j].to[k]] + aho.d[aho.d[j].to[k]].cnt
                        );
                }
            }
        }
        printf("%lld\n", DP[0][0]);
        int curr = 0, j = 0;
        FOR(i, 0, n) {
            if (txt[i] == '?') {
                FOR(k, 0, 26) {
                    if (DP[curr][j] == DP[curr + 1][aho.d[j].to[k]] + aho.d[aho.d[j].to[k]].cnt) {
                        printf("%c", 'a' + k);
                        curr++;
                        j = aho.d[j].to[k];
                        break;
                    }
                }
            }
            else {
                int k = txt[i] - 'a';
                printf("%c", txt[i]);
                curr++;
                j = aho.d[j].to[k];
            }
        }
        printf("\n");
    }
    return 0;
}