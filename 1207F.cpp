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
const int MAXN = 500010; // CAMBIAR ESTE
const int SQRTN = 300;

// GJNM
ll A[MAXN];
ll SUM[SQRTN][SQRTN];

void upd(int i, int val) {
    FOR(j, 1, SQRTN) SUM[i % j][j] += val;
    A[i] += val;
}

ll query(int y, int x) {
    ll ret = 0;
    while (y < MAXN) {
        ret += A[y];
        y += x;
    }
    return ret;
}


int main() {
    int q; ri(q);
    while (q--) {
        int t, x, y;
        riii(t, x, y);
        if (t == 1) {
            upd(x, y);
        }
        else {
            if (x >= SQRTN) printf("%lld\n", query(y, x));
            else printf("%lld\n", SUM[y][x]);
        }
    }

    return 0;
}