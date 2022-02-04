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

int N;
vi A;

struct STN {
    ll val;
    void merge(STN& L, STN& R) {
        val = L.val + R.val;
    }
    void operator=(ll a) {
        val = a;
    }
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    lzy[id] = -1;
    if (r - l < 2) {
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, ll x) {
    lzy[id] = x;
    ST[id].val = x * (r - l);
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    lzy[id] = -1;
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    if (lzy[id] != -1)
        shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int x, int y, int v, int id = 1, int l = 0, int r = N) {
    if (x >= r || y <= l) return;
    if (x <= l && y >= r) {
        upd(id, l, r, v);
        return;
    }
    if (lzy[id] != -1)
        shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int PRV[MAXN];



struct SUF_AUT {
    static const int ASZ = 26;
    struct node { int len, link, ind, cnt; map<int, int> to;};
    struct rge {int l, r, mult;};
    vector<node> d = {{}};
    int last;
    void init(vi S) {
        last = d[0].len = 0;
        int _i = 0;
        d[0].link = -1;
        for (auto c : S) {
            int v = SZ(d), p = last; // Be careful with mapping char to int
            d.emplace_back();
            d[v].len = d[last].len + 1;
            d[v].ind = _i++;
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
                    d[qq].ind = d[q].ind;
                    d[v].link = d[q].link = qq;
                    for (; p > -1 && d[p].to[c] == q; p = d[p].link)
                        d[p].to[c] = qq;
                }
            }
            last = v;
        }
    }

    void go() {
        FOR(i, 1, SZ(d)) {
            d[i].cnt++;
            d[d[i].link].cnt--;
        }
        vector<rge> a;
        FOR(i, 1, SZ(d)) a.pb({d[i].ind - d[i].len + 1, d[i].ind, d[i].cnt});
        sort(ALL(a), [](rge x, rge y) {
            return x.r < y.r;
        });
        STB();
        int curr_r = -1;
        ll ans = 0;
        FOR(i, 0, SZ(a)) {
            while (curr_r < a[i].r) {
                ++curr_r;
                STU(PRV[curr_r], curr_r + 1, A[curr_r]);
            }
            // printf("%d %d %d %lld\n", a[i].l, a[i].r, a[i].mult, STQ(a[i].l, a[i].r + 1).val);
            ans += a[i].mult * STQ(a[i].l, a[i].r + 1).val;
        }
        printf("%lld\n", ans);
    }
};


void solve() {
    ri(N);
    A.resize(N);
    FOR(i, 0, N) ri(A[i]);

    stack<int> st;
    FOR(i, 0, N) {
        while (!st.empty() && A[st.top()] < A[i])
            st.pop();
        if (st.empty())
            PRV[i] = 0;
        else
            PRV[i] = st.top() + 1;
        st.push(i);
    }

    SUF_AUT sa;
    sa.init(A);
    sa.go();
}


int main() {
    int t; ri(t);
    while (t--) solve();
}