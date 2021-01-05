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
const int MAXN = 1e5 + 20; // CAMBIAR ESTE

// GJNM
int BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, int val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < MAXN; p += p & -p) // se puede cambiar MAXN por n+1 si hace falta mas velocidad
        BIT[p] += val;
}
int sumBIT(int p) {
    p++;
    int ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}


int N, M;
vi G[MAXN];

int T = 1;
int IN[MAXN], OUT[MAXN], AT[MAXN], COL[MAXN];
void pre(int x, int f = -1) {
    AT[T] = COL[x];
    IN[x] = T++;
    for (auto y : G[x]) {
        if (y == f) continue;
        pre(y, x);
    }
    OUT[x] = T - 1;
}

struct QUERY {
    int l, r, k, ind;

    bool operator<(const QUERY &other) {
        if (l / 210 != other.l / 210) return l < other.l;
        return r < other.r;
    }
};
QUERY Q[MAXN];

int CNT[MAXN];
void add(int p) {
    updBIT(CNT[AT[p]], -1);
    CNT[AT[p]]++;
    updBIT(CNT[AT[p]], 1);
}
void erase(int p) {
    if (p == 0) return;
    updBIT(CNT[AT[p]], -1);
    CNT[AT[p]]--;
    updBIT(CNT[AT[p]], 1);
}

int ANS[MAXN];
int main() {
    rii(N, M);
    FOR(i, 0, N) ri(COL[i]);
    FOR(i, 1, N) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    pre(0);
    FOR(i, 0, M) {
        int x, k; rii(x, k); --x;
        Q[i].l = IN[x]; Q[i].r = OUT[x];
        Q[i].k = k; Q[i].ind = i;
    }
    sort(Q, Q + M);
    int l = 0, r = 0;
    updBIT(0, N);
    FOR(i, 0, M) {
        while (r < Q[i].r) {
            r++;
            add(r);
        }
        while (l > Q[i].l) {
            l--;
            add(l);
        }
        while (l < Q[i].l) {
            erase(l);
            l++;
        }
        while (r > Q[i].r) {
            erase(r);
            r--;
        }
        ANS[ Q[i].ind ] = sumBIT(N) - sumBIT(Q[i].k - 1);
    }
    FOR(i, 0, M) printf("%d\n", ANS[i]);

    return 0;
}