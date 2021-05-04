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
struct SUF_AUT {
    static const int ASZ = 26;
    struct node { int len, link, cnt; array<int, ASZ> to;};
    vector<node> d = {{}};
    int last;
    void init(string S) {
        last = d[0].len = 0;
        d[0].link = -1;
        d[0].cnt = 0;
        for (auto C : S) {
            int c = C - 'a', v = SZ(d), p = last; // Be careful with mapping char to int
            d.emplace_back();
            d[v].len = d[last].len + 1;
            d[v].cnt = 1;
            for (; p > -1 && !d[p].to[c]; p = d[p].link)
                d[p].to[c] = v;
            if (p == -1) {
                d[v].link = 0;
            }
            else {
                int q = d[p].to[c];
                if (d[p].len + 1 == d[q].len) {
                    d[v].link = q;
                    d[q].cnt++;
                }
                else {
                    int qq = SZ(d);
                    d.emplace_back();
                    d[qq].len = d[p].len + 1;
                    d[qq].to = d[q].to;
                    d[qq].link = d[q].link;
                    d[qq].cnt = d[q].cnt + 1;
                    d[v].link = d[q].link = qq;
                    for (; p > -1 && d[p].to[c] == q; p = d[p].link)
                        d[p].to[c] = qq;
                }
            }
            last = v;
        }
    }
};

bool vis[10010][10010];

int main() {
    string a, b; cin >> a >> b;

    SUF_AUT saa; saa.init(a);
    SUF_AUT sab; sab.init(b);

    queue< tuple<int, int, int> > bfs; bfs.push({0, 0, 0});
    while (!bfs.empty()) {
        auto [pa, pb, len] = bfs.front(); bfs.pop();
        if (len > 0 && saa.d[pa].cnt == 1 && sab.d[pb].cnt == 1) {
            printf("%d\n", len);
            return 0;
        }

        FOR(c, 0, saa.ASZ) {
            if (saa.d[pa].to[c] != 0 && sab.d[pb].to[c] != 0 && !vis[saa.d[pa].to[c]][sab.d[pb].to[c]]) {
                vis[saa.d[pa].to[c]][sab.d[pb].to[c]] = true;
                bfs.push({saa.d[pa].to[c], sab.d[pb].to[c], len + 1});
            }
        }
    }
    printf("-1\n");
    return 0;
}