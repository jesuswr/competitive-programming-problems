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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N; ll K;
ll A[MAXN];
ll PRE[MAXN], SUF[MAXN];

bool valid(ll l, ll r) {
    ll need = 0;
    int li = lb(A, A + N, l) - A;
    if (li > 0) need += l * li - PRE[li - 1];
    int ri = ub(A, A + N, r) - A;
    if (ri < N) need += SUF[ri] - r * (N - ri);
    return need <= K;
}

int main() {
    ri(N), rl(K);
    FOR(i, 0, N) rl(A[i]);
    sort(A, A + N);
    FOR(i, 0, N) PRE[i] = A[i] + (i > 0 ? PRE[i - 1] : 0);
    ROF(i, N - 1, -1) SUF[i] = A[i] + SUF[i + 1];

    ll ans = LLINF;
    FOR(i, 0, N) { // looking for [L,R] with L in A
        ll lo = A[i], hi = 1e9 + 2;
        while (lo < hi) {
            ll mi = lo + (hi - lo) / 2;
            if (valid(A[i], mi)) hi = mi;
            else lo = mi + 1;
        }
        if (hi != 1e9 + 2) ans = min(ans, hi - A[i]);
    }
    ROF(i, N - 1, -1) {
        ll lo = 0, hi = A[i];
        while (lo < hi) {
            ll mi = lo + (hi - lo + 1) / 2;
            if (valid(mi, A[i])) lo = mi;
            else hi = mi - 1;
        }
        if (lo != 0) ans = min(ans, A[i] - lo);
    }
    printf("%lld\n", ans);
    return 0;
}