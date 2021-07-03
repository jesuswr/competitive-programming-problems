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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N;
ll X[MAXN], V[MAXN];
set<int> LIVING;

int main() {
    ri(N);
    FOR(i, 0, N) rll(X[i], V[i]);
    FOR(i, 0, N) LIVING.insert(i);

    priority_queue< tuple<ld, int, int>> pq;

    FOR(i, 0, N - 1) {
        ld dst = X[i + 1] - X[i];
        ld v_dst = V[i] - V[i + 1];
        if (v_dst <= 0)
            continue;
        pq.push({ -dst / v_dst, i, i + 1});
    }

    while (!pq.empty()) {
        auto [t, x, y] = pq.top();
        t = -t;
        pq.pop();

        if (LIVING.find(x) == LIVING.end())
            continue;
        if (LIVING.find(y) == LIVING.end())
            continue;

        LIVING.erase(x);
        LIVING.erase(y);

        auto itx = LIVING.lb(x);
        auto ity = LIVING.ub(y);
        if (itx == LIVING.begin() || ity == LIVING.end())
            continue;
        itx--;

        x = *itx;
        y = *ity;

        ld dst = X[y] - X[x];
        ld v_dst = V[x] - V[y];
        if (v_dst <= 0)
            continue;
        pq.push({ -dst / v_dst, x, y});
    }

    printf("%d\n", SZ(LIVING));
    for (auto i : LIVING) printf("%d ", i + 1);
    printf("\n");

    return 0;
}