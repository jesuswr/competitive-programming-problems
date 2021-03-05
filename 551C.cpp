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
#include <deque>

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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int N, M;
ll A[MAXN], B[MAXN];

bool valid(ll t) {
    FOR(i, 1, N + 1) B[i] = A[i];
    int j = N;
    FOR(i, 0, M) {
        ll curr_t = t;
        while (j >= 1 && B[j] == 0) j--;
        curr_t -= j;
        while (curr_t > 0 && j >= 1) {
            while (j >= 1 && B[j] == 0) j--;
            ll can_take = max(0ll, min(curr_t, B[j]));
            curr_t -= can_take;
            B[j] -= can_take;
        }
    }
    FOR(i, 1, N + 1) if (B[i] != 0) return false;
    return true;
}

int main() {
    rii(N, M);
    FOR(i, 0, N) rl(A[i + 1]);
    ll lo = 0, hi = 2e14;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        if (valid(mi)) hi = mi;
        else lo = mi + 1;
    }
    printf("%lld\n", lo);
    return 0;
}