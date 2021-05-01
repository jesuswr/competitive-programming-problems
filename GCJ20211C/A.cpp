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
const int MAXN = 40; // CAMBIAR ESTE

// GJNM
int N, K;
void solve() {
    rii(N, K);
    vi P(N);
    FOR(i, 0, N) ri(P[i]);
    sort(ALL(P));
    P.resize(distance(P.begin(), unique(ALL(P))));
    N = SZ(P);
    vi one;
    FOR(j, 0, N - 1) {
        vi opts;
        opts.pb(P[j] + 1);
        opts.pb(P[j + 1] - 1);
        opts.pb(P[j] + (P[j + 1] - P[j]) / 2);
        opts.pb(P[j] + (P[j + 1] - P[j] + 1) / 2);

        int best = 0;
        FOR(i, 0, SZ(opts)) {
            int cnt = 0;
            auto it = lb(ALL(P), opts[i]);
            if (it != P.end()) {
                int mid = opts[i] + (*it - opts[i] + 1) / 2;
                cnt += mid - opts[i] + 1;
                if (abs(*it - mid) <= abs(mid - opts[i])) cnt--;
            }
            else continue;
            if (it != P.begin()) {
                --it;
                int mid = *it + (opts[i] - *it) / 2;
                cnt += opts[i] - mid;
                if (abs(*it - mid) <= abs(mid - opts[i])) cnt--;
            }
            else continue;
            best = max(best, cnt);
        }
        one.pb(best);
    }
    one.pb(0);
    one.pb(0);
    if (P[0] > 1) one.pb(P[0] - 1);
    if (P[N - 1] < K) one.pb(K - P[N - 1]);
    sort(ALL(one)); reverse(ALL(one));
    int ans = one[0] + one[1];

    FOR(i, 0, N - 1)
        ans = max(ans, P[i + 1] - P[i] - 1);
    printf("%Lf\n", (long double)ans / K);
}

int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}