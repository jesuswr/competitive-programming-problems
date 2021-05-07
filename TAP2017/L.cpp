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
ll N[4];
vector< vector<ll> > A = {
    {1, 0, 1, 2},
    {4, 0, 0, 0},
    {2, 2, 0, 0},
    {0, 4, 0, 0},
    {0, 0, 0, 4},
    {2, 0, 2, 0}
};

ll go() {
    ll aux_n[4] = {N[0], N[1], N[2], N[3]};
    ll ret = 0;
    for (auto v : A) {
        ll mn = LLINF;
        FOR (i, 0, 4) {
            if (v[i] == 0) continue;
            ll can_take = aux_n[i] / v[i];
            mn = min(mn, can_take);
        }
        ret += mn;
        FOR(i, 0, 4) {
            aux_n[i] -= v[i] * mn;
        }
    }
    return ret;
}

int main() {
    rll(N[0], N[1]), rll(N[2], N[3]);
    sort(ALL(A));
    ll ans = 0;
    while (true) {
        ans = max(ans, go());
        if (!next_permutation(ALL(A))) break;
    }
    printf("%lld\n", ans);

    return 0;
}