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
const int MAXN = 4e6; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int X[MAXN], Y[MAXN];
vi COMP;
void comp() {
    COMP.resize(2 * N);
    FOR(i, 0, N) {
        COMP[2 * i] = X[i];
        COMP[2 * i + 1] = Y[i];
    }
    sort(ALL(COMP));
}

ll BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < MAXN; p += p & -p) // se puede cambiar maxN por n+5 si hace falta mas velocidad
        BIT[p] += val;
}
ll sumBIT(int p) {
    p++;
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}


void solve() {
    FOR(i, 0, N) {
        ri(X[i]);
        ri(Y[i]);
        Y[i] += X[i];
    }
    comp();
    FOR(i, 0, 4 * N) BIT[i] = 0;
    FOR(i, 0, N) {
        int ind = lb(ALL(COMP), X[i]) - COMP.begin();
        updBIT(ind, 1);
    }
    int ans = 0, bst = 0;
    FOR(i, 0, N) {
        int l = lb(ALL(COMP), X[i]) - COMP.begin();
        int r = lb(ALL(COMP), Y[i]) - COMP.begin();
        int curr = sumBIT(r - 1) - sumBIT(l);
        if (curr > ans) {
            ans = curr;
            bst = i;
        }
    }
    printf("%d %d\n", X[bst], ans);
}

int main() {
    while (scanf("%d\n", &N) != EOF)
        solve();
    return 0;
}