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
int N, M;
ll A[MAXN], B[MAXN];

bool valid(ll k) {
    int j = 0;
    FOR(i, 0, N) {
        ll l = 0, r = 0;
        while (j < M) {
            if (B[j] <= A[i]) {
                l = max(l, A[i] - B[j]);
            }
            else {
                r = max(r, B[j] - A[i]);
            }

            if (2 * min(l, r) + max(l, r) <= k)
                j++;
            else
                break;
        }
    }
    return j == M;
}

int main() {
    rii(N, M);
    FOR(i, 0, N) rl(A[i]);
    FOR(i, 0, M) rl(B[i]);

    ll lo = 0, hi = 2e10;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        if (valid(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    printf("%lld\n", lo);
    return 0;
}