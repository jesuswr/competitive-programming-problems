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
const int MAXN = 20010; // CAMBIAR ESTE

// GJNM
int N, Q;
string A[MAXN];

class CompClass {
public:
    bool operator() (int a, int b) {
        if (SZ(A[a]) != SZ(A[b]))
            return SZ(A[a]) < SZ(A[b]);
        int cmp = A[a].compare(A[b]);
        if (cmp != 0)
            return cmp < 0;
        return a < b;
    }
};

struct SUF_AUT {
    static const int ASZ = 27;
    struct node {
        int len, link; array<int, ASZ> to;
        priority_queue<int, vi, CompClass> pq;
    };
    vector<node> d = {{}};
    int last;
    void init(string S) {
        last = d[0].len = 0;
        d[0].link = -1;
        d[0].to.fill(0);
        int k = 0;
        for (auto C : S) {
            int c = C - 'a', v = SZ(d), p = last; // Be careful with mapping char to int
            d.emplace_back();
            d[v].len = d[last].len + 1;
            if (c == 26)
                ++k;
            else
                d[v].pq.push(k);
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

        for (auto [_, x] : ord) {
            if (x == 0) continue;
            set<int> inds;
            while (!d[x].pq.empty()) {
                inds.insert(d[x].pq.top());
                d[x].pq.pop();
            }
            for (auto i : inds) d[x].pq.push(i);

            int y = d[x].link;
            while (!d[y].pq.empty()) {
                inds.insert(d[y].pq.top());
                d[y].pq.pop();
            }

            for (auto i : inds) {
                d[y].pq.push(i);
                if (SZ(d[y].pq) > 10) d[y].pq.pop();
            }
        }
    }

    void query(string q) {
        int p = 0;
        for (char C : q) {
            int c = C - 'a';
            if (d[p].to[c] <= 0) {
                printf("-1\n");
                return;
            }
            p = d[p].to[c];
        }
        vi inds;
        while (!d[p].pq.empty()) {
            inds.pb(d[p].pq.top());
            d[p].pq.pop();
        }
        for (auto i : inds) d[p].pq.push(i);
        for (int i = SZ(inds) - 1; i >= 0; --i) printf("%d%c", inds[i] + 1, " \n"[i == 0]);
    }
};

int main() {
    ri(N);
    FOR(i, 0, N) cin >> A[i];
    string s;
    FOR(i, 0, N) {
        for (auto c : A[i]) s.pb(c);
        s.pb('a' + 26);
    }
    SUF_AUT sa; sa.init(s);
    ri(Q);
    FOR(i, 0, Q) {
        string q;
        cin >> q;
        sa.query(q);
    }
    return 0;
}