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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, q;
pii A[MAXN];
int B[MAXN];
struct STN {
    vector<int> p;
    void merge(STN& L, STN& R) {
        p.clear();
        int pl = 0, pr = 0;
        while ( pl < L.p.size() && pr < R.p.size()) {
            if ( L.p[pl] <= R.p[pr] )
                p.pb(L.p[pl++]);
            else
                p.pb(R.p[pr++]);
        }
        while ( pl < L.p.size() )
            p.pb(L.p[pl++]);
        while ( pr < R.p.size() )
            p.pb(R.p[pr++]);
    }
    void operator=(int a) {
        p.clear();
        p.pb(a);
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = A[l].S;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int cnt(int l, int r, int id) {
    return ub(ST[id].p.begin(), ST[id].p.end(), r) - lb(ST[id].p.begin(), ST[id].p.end(), l);
}

int STQ(int x, int y, int k, int id = 1, int l = 0, int r = N) {
    if ( r - l < 2 ) {
        return ST[id].p[0];
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    int l_cnt = cnt(x, y, L);
    if ( l_cnt >= k )
        return STQ(x, y, k, L, l, m);
    else
        return STQ(x, y, k - l_cnt, R, m, r);

    //if (x == l && y == r) return ST[id];
    //int m = (l + r) >> 1, L = id << 1, R = L | 1;
    //if (x >= m) return STQ(x, y, R, m, r);
    //if (y <= m) return STQ(x, y, L, l, m);
    //STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    //return res.merge(ln, rn), res;
}




int main() {
    while (scanf("%d %d", &N, &q) != EOF) {
        FOR(i, 0, N) {
            ri(A[i].F);
            A[i].S = i + 1;
            B[i] = A[i].F;
        }
        sort(A, A + N);
        STB();
        FOR(i, 0, q) {
            int l, r, k;
            riii(l, r, k);
            printf("%d\n", B[STQ(l, r, k) - 1]);
        }
    }

    return 0;
}