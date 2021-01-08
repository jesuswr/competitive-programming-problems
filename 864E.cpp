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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
struct OBJECT {
    int t, d, p, ind;

    bool operator<(OBJECT other) {
        return d < other.d;
    }
};
int N;
OBJECT A[110];
int DP[110][20 * 110];

int f(int p, int sm) {
    if (p == N) return 0;
    if (DP[p][sm] != -1) return DP[p][sm];
    DP[p][sm] = f(p + 1, sm);
    if (sm + A[p].t < A[p].d) DP[p][sm] = max(DP[p][sm], A[p].p + f(p + 1, sm + A[p].t));
    return DP[p][sm];
}

int main() {
    ri(N);
    FOR(i, 0, N) riii(A[i].t, A[i].d, A[i].p), A[i].ind = i;
    sort(A, A + N);
    memset(DP, -1, sizeof(DP));
    printf("%d\n", f(0, 0));
    int bst = f(0, 0);
    int p = 0, sm = 0;
    vi ans;
    while (p < N) {
        if (f(p + 1, sm) == bst) p++;
        else {
            ans.pb(A[p].ind + 1);
            bst -= A[p].p;
            sm += A[p].t;
            p++;
        }
    }
    printf("%d\n", SZ(ans));
    for (auto x : ans) printf("%d ", x);
    printf("\n");

    return 0;
}