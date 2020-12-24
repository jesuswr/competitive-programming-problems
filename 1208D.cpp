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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int N;
ll P[MAXN];

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    ll sm;
    void merge(STN& L, STN& R) {
        sm = L.sm + R.sm;
    }
    void operator=(int a) {
        sm = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = l + 1;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
int STQ(ll sm, int id = 1, int l = 0, int r = N) {
    if (l == r - 1)
        return l;
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (ST[L].sm >= sm)
        return STQ(sm, L, l, m);
    else
        return STQ(sm - ST[L].sm, R, m, r);
}
void STU(int p, int x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
int A[MAXN];


int main() {
    ri(N);
    FOR(i, 0, N) rl(P[i]);
    STB();
    for (int i = N - 1; i >= 0; i--) {
        int j = STQ(P[i] + 1);
        A[i] = j + 1;
        STU(j, 0);
    }
    FOR(i, 0, N) printf("%d ", A[i]);
    printf("\n");

    return 0;
}