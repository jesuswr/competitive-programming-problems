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
const int MAXN = 3e5; // CAMBIAR ESTE
const ll MOD = 998244353;

// GJNM
int N, M;
int A[MAXN], B[MAXN];

int main() {
    rii(N, M);
    FOR(i, 0, N) ri(A[N - i - 1]);
    FOR(i, 0, M) ri(B[M - i - 1]);
    int ni = 0, mi = 0;
    vi x, y;
    while (ni < N && mi < M) {
        if (A[ni] == B[mi]) {
            x.pb(ni);
            mi++;
        }
        else if (A[ni] < B[mi]) {
            printf("0\n");
            return 0;
        }
        ni++;
    }
    if (mi < M) {
        printf("0\n");
        return 0;
    }
    FOR(i, 0, M) {
        int j = x[i] + 1;
        while (j < N && A[j] >= B[i]) j++;
        y.pb(j);
    }
    //FOR(i, 0, N) printf("%d ", A[i]);
    //printf("\n");
    //FOR(i, 0, M) printf("%d ", B[i]);
    //printf("\n");
    //FOR(i, 0, M) printf("%d ", x[i]);
    //printf("\n");
    //FOR(i, 0, M) printf("%d ", y[i]);
    //printf("\n");
    if (y[M - 1] != N) {
        printf("0\n");
        return 0;
    }
    ll ans = 1;
    FOR(i, 0, M - 1) {
        ans *= (y[i] - x[i]);
        ans %= MOD;
        assert(y[i] <= x[i + 1]);
    }
    printf("%lld\n", ans);
    return 0;
}