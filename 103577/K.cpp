#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i=n; i < (int)m; i++)
#define ROF(i,n,m) for(int i=n; i > (int)m; i--)
#define pb push_back
#define ri(a) qwerty = scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) qwerty = scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define riii(a, b, c) ri(a), ri(b), ri(c)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()

int qwerty;

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

typedef tuple<ll,ll,int,bool> point;

int n, m;
vector<point> ps;

struct SegmentTree {
    struct STN {
        ll xy, _xy, x_y, _x_y;
        void merge(STN &L, STN &R) {
            xy = min(L.xy, R.xy);
            _xy = min(L._xy, R._xy);
            x_y = min(L.x_y, R.x_y);
            _x_y = min(L._x_y, R._x_y);
        }
        void operator=(point &p) {
            auto &[x, y, id, isGood] = p;
            if (!isGood) xy = _xy = x_y = _x_y = INFLL;
            else {
                xy = x + y;
                x_y = x - y;
                _xy = - x + y;
                _x_y = - x - y;
            }
        }
    };

    int N = 0;
    vector<STN> ST;


    SegmentTree(vector<point> &ps) {
        N = ps.size();
        ST.resize(4*N);
        STB(ps, 1, 0, N);
    }

    void STB(vector<point> &ps, int id, int l, int r) {
        if (r - l < 2) { ST[id] = ps[l]; return; }
        int m = (l+r)>>1, L = id<<1, R = L|1;
        STB(ps,L,l,m); STB(ps,R,m,r);
        ST[id].merge(ST[L], ST[R]);
    }

    STN query(int x, int y) { return STQ(x, y, 1, 0, N); }

    STN STQ(int x, int y, int id, int l, int r) {
        if(x == l && r == y) { return ST[id]; }
        int m = (l+r)>>1, L = id<<1, R = L|1;
        if(x >= m) return STQ(x, y, R, m, r);
        if(y <= m) return STQ(x, y, L, l, m);
        STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
        return res.merge(ln, rn), res;
    }

    void update(int pos, point &p) { STU(pos, p, 1, 0, N); }

    void STU(int pos, point &p, int id, int l, int r) {
        if(r - l < 2) { ST[id] = p; return; }
        int m = (l+r)>>1, L = id<<1, R = L|1;
        if(pos < m) STU(pos, p, L, l, m);
        else STU(pos, p, R, m, r);
        ST[id].merge(ST[L], ST[R]);
    }
};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    rii(n,m);
    FOR(i,0,n) {
        ll x, y;
        lrii(x, y);
        ps.pb({y, x, 0, false});
    }
    FOR(i,0,m) {
        ll x, y;
        lrii(x, y);
        ps.pb({y, x, 0, true});
    }

    sort(all(ps));
    FOR(i,0,ps.size()) {
        auto &[y, x, id, isGood] = ps[i];
        id = i;
        swap(x, y);
    }
    vector<point> aux(ps.size(), {0,0,0,false});
    SegmentTree leftST(aux), rightST(ps);
    sort(all(ps));

    ll sum = 0;
    for (auto &p : ps) {
        auto &[x, y, id, isGood] = p;
        if (isGood) {
            point q = {0,0,0,false};
            rightST.update(id, q);
            leftST.update(id, p);
        }
        else {
            SegmentTree::STN cI = rightST.query(id, ps.size());
            SegmentTree::STN cII = leftST.query(id, ps.size());
            SegmentTree::STN cIII = leftST.query(0, id+1);
            SegmentTree::STN cIV = rightST.query(0, id+1);

            ll ans = INFLL;
            ans = min(ans, cI.xy - x - y);
            ans = min(ans, cII._xy + x - y);
            ans = min(ans, cIII._x_y + x + y);
            ans = min(ans, cIV.x_y - x + y);
            sum += ans;
        }
    }

    printf("%lld\n", sum);



    return 0;
}