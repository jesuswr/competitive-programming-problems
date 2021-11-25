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
const int MAXN = 4e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int n, m;
vi a, b;
vi inds[2];

int look(int need, int ind) {
    auto it = lb(ALL(inds[need]), ind);
    int op1 = -1, op2 = -1;
    if (it != inds[need].end())
        op1 = *it;
    if (it != inds[need].begin()) {
        --it;
        op2 = *it;
    }
    if (op1 == -1 && op2 == -1)
        return -1;
    if (op2 == -1)
        return op1;
    if (op1 == -1)
        return op2;
    if (abs(ind - op1) <= abs(ind - op2))
        return op1;
    else
        return op2;
}

int main() {
    rii(n, m);
    a.resize(2 * n);
    FOR(i, 0, n) {
        ri(a[i]);
        a[i + n] = a[i];
    }
    b.resize(m);
    FOR(i, 0, m) ri(b[i]);
    FOR(i, 0, 2 * n) inds[a[i]].pb(i);

    int u = n;
    int ans = 0;
    FOR(i, 0, m) {
        int need = b[i];
        int nxt = look(need, u);
        if (nxt == -1) {
            printf("-1\n");
            return 0;
        }
        ans += abs(nxt - u);
        u = nxt;
    }
    printf("%d\n", ans + m);
    return 0;
}