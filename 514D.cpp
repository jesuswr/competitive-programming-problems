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
// Todos los rangos son semi-abiertos [a,b)
int N, M, K;
vi A[MAXN];

int main() {
    riii(N, M, K);
    vi best(M);
    int mx = 0;
    FOR(i, 0, N) FOR(_, 0, M) {
        int tmp; ri(tmp);
        A[i].pb(tmp);
    }
    FOR(i, 0, M) A[N].pb((i == 0 ? 1e9 + 10 : 0));
    int l = 0, r = 0;
    multiset<int> sets[5];
    FOR(i, 0, M) sets[i].insert(0);
    while (r <= N) {
        int sm = 0;
        FOR(i, 0, M) sm += *sets[i].rbegin();
        if (sm <= K) {
            if (r - l > mx) {
                mx = r - l;
                FOR(i, 0, M) best[i] = *sets[i].rbegin();
            }
            FOR(i, 0, M) sets[i].insert( A[r][i] );
            r++;
        }
        else {
            FOR(i, 0, M) sets[i].erase( sets[i].find( A[l][i] ) );
            l++;
        }
    }
    for (auto x : best) printf("%d ", x);
    printf("\n");
    return 0;
}