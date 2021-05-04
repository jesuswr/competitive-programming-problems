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
    static const int ASZ = 27;
    struct node { int len, link, cnt, cnt2; array<int, ASZ> to;};
    vector<node> d = {{}};
    int last;
    void init(string S) {
        last = d[0].len = 0;
        d[0].link = -1;
        bool found = false;;
        for (auto C : S) {
            int c = C - 'a', v = SZ(d), p = last; // Be careful with mapping char to int
            d.emplace_back();
            d[v].len = d[last].len + 1;
            d[v].cnt = 1;
            found |= c == 26;
            d[v].cnt2 = !found;
            for (; p > -1 && !d[p].to[c]; p = d[p].link)
                d[p].to[c] = v;
            if (p == -1) {
                d[v].link = 0;
            }
            else {
                int q = d[p].to[c];
                if (d[p].len + 1 == d[q].len) {
                    d[v].link = q;
                }
                else {
                    int qq = SZ(d);
                    d.emplace_back();
                    d[qq].len = d[p].len + 1;
                    d[qq].to = d[q].to;
                    d[qq].link = d[q].link;
                    d[qq].cnt = 0;
                    d[qq].cnt2 = 0;
                    d[v].link = d[q].link = qq;
                    for (; p > -1 && d[p].to[c] == q; p = d[p].link)
                        d[p].to[c] = qq;
                }
            }
            last = v;
        }

        vector<pii> ord;
        FOR(i, 0, SZ(d)) ord.pb({ -d[i].len, i});
        sort(ALL(ord));
        for (auto [_, x] : ord) if (x > 0) {
                d[ d[x].link ].cnt += d[x].cnt;
                d[ d[x].link ].cnt2 += d[x].cnt2;
            }
        int mn = INF;
        FOR(i, 1, SZ(d)) {
            if (d[i].cnt == 2 && d[i].cnt2 == 1) {
                mn = min(mn, d[d[i].link].len + 1);
            }
        }
        printf("%d\n", (mn == INF ? -1 : mn));
    }
};

int main() {
    string a, b; cin >> a >> b;
    SUF_AUT sa; sa.init(a + (char)('a' + 26) + b);
    return 0;
}