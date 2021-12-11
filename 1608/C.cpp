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
const int MAXN = 2e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[MAXN], B[MAXN];
bool W[MAXN];
set<pii> As, Bs;

void goB(int j);

void goA(int i) {
    // printf("en A con %d\n", i);
    vii upd;
    W[i] = 1;
    As.erase({A[i], i});
    Bs.erase({B[i], i});
    for (auto it = Bs.lower_bound({B[i], -1}); it != Bs.end(); ++it )
        upd.pb(*it);
    for (auto p : upd) {
        // printf("\tactualizo %d\n", p.S);
        Bs.erase(p);
        As.erase({A[p.S], p.S});
    }
    for (auto [_, j] : upd) {
        // printf("%d %d\n", i,j);
        goB(j);
    }
}

void goB(int i) {
    // printf("en B con %d %d\n", i, B[i]);
    vii upd;
    W[i] = 1;
    As.erase({A[i], i});
    Bs.erase({B[i], i});
    for (auto it = As.lower_bound({A[i], -1}); it != As.end(); ++it )
        upd.pb(*it);
    for (auto p : upd) {
        // printf("\tactualizo %d\n", p.S);
        As.erase(p);
        Bs.erase({B[p.S], p.S});
    }
    for (auto [_, j] : upd) {
        // printf("%d %d\n", i,j);
        goA(j);
    }
}

void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) ri(B[i]);
    FOR(i, 0, N) As.insert({A[i], i});
    FOR(i, 0, N) Bs.insert({B[i], i});
    int mxi = 0;
    FOR(i, 0, N) if (A[i] > A[mxi])
        mxi = i;
    goA(mxi);
    mxi = 0;
    FOR(i, 0, N) if (B[i] > B[mxi])
        mxi = i;
    goB(mxi);

    FOR(i, 0, N) printf("%d", W[i]);
    printf("\n");

    As.clear();
    Bs.clear();
    FOR(i, 0, N) W[i] = 0;
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}