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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi P;
vi ans = {INF};

void prnt(vi a) {
    printf("\t");
    for (auto x : a) printf("%d ", x);
    printf("\n");
}

void go(int p, vi n, vi x) { // x * x = n
    // printf("%d\n", p);
    // prnt(n);
    // prnt(x);

    if (SZ(x) <= p) {
        bool good = 1;
        for (auto a : n) if (a != 0) good = 0;
        if (good) {
            reverse(ALL(x));
            ans = min(ans, x);
        }
        return;
    }
    int need = (n[p] - x[p] + 10) % 10;
    for (int d = 0; d <= 9; ++d) {
        vi nx = x;
        nx[p] = d;
        if ( ((p == 0 ? 1 : 2) * nx[p] * nx[0]) % 10 == need ) {

            vi nn = n;
            nn[2 * p] = (nn[2 * p] - (nx[p] * nx[p]) % 10 + 10) % 10;
            FOR(i, 0, p) nn[i + p] = (nn[i + p] - (2 * nx[i] * nx[p]) % 10 + 10) % 10;

            go(p + 1, nn, nx);
        }
    }
}


int main() {
    int _aux;
    while (scanf("%1d", &_aux) != EOF) {
        ++N;
        P.pb(_aux);
    }
    reverse(ALL(P));
    if (N & 1) {
        vi _ans((N + 1) / 2);
        go(0, P, _ans);
    }
    if (ans[0] < 10) {
        for (auto d : ans) printf("%d", d);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}