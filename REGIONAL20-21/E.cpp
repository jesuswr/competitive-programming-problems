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
const int MAXN = 1e5 + 109; // CAMBIAR ESTE

// GJNM
int N;
pii H[MAXN];

int BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, int val) {
    p += 3;    // esto es porque el bit esta indexado desde 1
    for (; p < MAXN; p += p & -p) // se puede cambiar MAXN por n+5 si hace falta mas velocidad
        BIT[p] += val;
}
int sumBIT(int p) {
    p += 3;
    int ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(H[i].F), H[i].S = i;
    sort(H, H + N); reverse(H, H + N);

    set<int> used;
    FOR(o, 0, N) {
        int ind = H[o].S;

        auto it = used.lb(ind);
        int r = 1e7;
        if (it != used.end()) {
            r = *it;
        }
        int l = -1e7;
        if (it != used.begin()) {
            --it;
            l = *it;
        }

        l = max(0, l + (ind - l + 2) / 2);
        r = min(N - 1, ind + (r - ind - 1) / 2);

        updBIT(r + 1, -1);
        updBIT(l, 1);

        used.insert(ind);
    }

    FOR(i, 0, N) {
        printf("%d ", sumBIT(i) - 1);
    }
    printf("\n");
    return 0;
}