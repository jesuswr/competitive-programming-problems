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
const int MAXN = 4e5 + 10; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct range {
    int l, r, i;
};
int N;
range SWEEP[MAXN];

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

void comp() {
    vi qlq;
    FOR(i, 0, N) {
        qlq.pb(SWEEP[i].l);
        qlq.pb(SWEEP[i].r);
    }
    sort(ALL(qlq));
    map<int, int> new_x;
    FOR(i, 0, 2 * N) new_x[qlq[i]] = i + 2;
    FOR(i, 0, N) {
        SWEEP[i].l = new_x[SWEEP[i].l];
        SWEEP[i].r = new_x[SWEEP[i].r];
    }
}

int IS_CONT[MAXN], CONT[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) {
        rii(SWEEP[i].l, SWEEP[i].r);
        SWEEP[i].i = i;
    }
    comp();

    {
        sort(SWEEP, SWEEP + N,
        [](const range a, const range b) {
            if (a.r != b.r)
                return a.r < b.r;
            return a.l > b.l;
        });
        FOR(i, 0, N) {
            range e = SWEEP[i];
            CONT[e.i] = sumBIT(e.r) - sumBIT(e.l - 1);
            updBIT(e.l, 1);
        }
    }
    {
        memset(BIT, 0, sizeof(BIT));
        sort(SWEEP, SWEEP + N,
        [](const range a, const range b) {
            if (a.l != b.l)
                return a.l < b.l;
            return a.r > b.r;
        });
        FOR(i, 0, N) {
            range e = SWEEP[i];
            IS_CONT[e.i] = sumBIT(2 * N + 7) - sumBIT(e.r - 1);
            updBIT(e.r, 1);
        }
    }

    FOR(i, 0, N) printf("%d ", CONT[i]);
    printf("\n");
    FOR(i, 0, N) printf("%d ", IS_CONT[i]);
    printf("\n");

    return 0;
}