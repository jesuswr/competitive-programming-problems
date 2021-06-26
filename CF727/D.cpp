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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int N;
pair<ll, ll> A[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) rll(A[i].S, A[i].F); // F = oferta, S = necesito
    sort(A, A + N);

    ll prc = 0, cnt = 0;

    int l = 0, r = N - 1;
    while (l <= r) {
        ll need = max(0ll, A[l].F - cnt);
        if (need > 0) {
            ll take = min(need, A[r].S);
            cnt += take;
            prc += 2 * take;
            A[r].S -= take;
        }
        else {
            cnt += A[l].S;
            prc += A[l].S;
            A[l].S = 0;
        }

        if (A[l].S == 0) ++l;
        if (A[r].S == 0) --r;
    }
    printf("%lld\n", prc);

    return 0;
}