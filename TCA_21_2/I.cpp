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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N, M;

int main() {
    rii(N, M);
    set<int> hola;
    hola.insert(0);
    FOR(_, 0, N / 2) {
        vi ins;
        int x; ri(x);
        x %= M;
        if (x == 0)
            continue;
        for (auto y : hola) {
            int z = x + y;
            if (z >= M) z -= M;
            ins.pb(z);
        }
        for (auto y : ins)
            hola.insert(y);
    }

    set<int> chao;
    chao.insert(0);
    FOR(_, 0, (N + 1) / 2) {
        vi ins;
        int x; ri(x);
        x %= M;
        if (x == 0)
            continue;
        for (auto y : chao) {
            int z = x + y;
            if (z >= M) z -= M;
            ins.pb(z);
        }
        for (auto y : ins)
            chao.insert(y);
    }

    int mx = max(*hola.rbegin(), *chao.rbegin());

    for (auto x : hola) {
        auto it = chao.ub(M - 1 - x);
        if (it != chao.begin()) {
            --it;
            mx = max(mx, x + *it);
        }
    }
    for (auto x : chao) {
        auto it = hola.ub(M - 1 - x);
        if (it != hola.begin()) {
            --it;
            mx = max(mx, x + *it);
        }
    }
    printf("%d\n", mx);
    return 0;
}