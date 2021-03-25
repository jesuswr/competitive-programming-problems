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
const int MAXN = 4e5 + 10; // CAMBIAR ESTE

// GJNM
ll N;
ll A[MAXN];

int main() {
    rl(N);
    FOR(i, 0, N) rl(A[i]);
    ll ans = 0;
    FOR(b, 0, 30) {
        vector<ll> B;
        FOR(i, 0, N) B.pb(A[i] & ((1ll << (b + 1ll)) - 1ll));
        sort(ALL(B));
        ll cnt = 0;
        FOR(i, 0, N) {
            ll lo = (1ll << b) - B[i], hi = (1ll << (b + 1ll)) - 1ll - B[i];
            auto itl = lb(ALL(B), lo), ith = ub(ALL(B), hi);
            cnt += (ith - itl) - (lo <= B[i] && B[i] <= hi);

            lo = (1ll << b) + (1ll << (b + 1ll)) - B[i], hi = (1ll << (b + 2ll)) - 2ll - B[i];
            itl = lb(ALL(B), lo), ith = ub(ALL(B), hi);
            cnt += (ith - itl) - (lo <= B[i] && B[i] <= hi);
        }
        cnt >>= 1ll;
        if (cnt & 1ll) ans |= 1ll << b;
    }
    printf("%lld\n", ans);

    return 0;
}