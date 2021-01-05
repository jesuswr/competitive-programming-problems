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
const int MAXN = 5e5 + 1; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;
const int BITS = 60;

// GJNM
int N;
ll X[MAXN];
int AND[MAXN][BITS];
int OR[MAXN][BITS];
int ON[BITS];
ll PRE[BITS];

void solve() {
    ri(N);
    FOR(i, 0, N) rl(X[i]);
    FOR(i, 0, BITS) ON[i] = 0;
    FOR(i, 0, N) FOR(j, 0, BITS) if (X[i] & (1ll << j)) ON[j]++;
    ll ANS = 0;
    FOR(i, 0, N) {
        FOR(j, 0, BITS) {
            if (X[i] & (1ll << j)) {
                OR[i][j] = N;
                AND[i][j] = ON[j];
            }
            else {
                OR[i][j] = ON[j];
                AND[i][j] = 0;
            }
        }
        ll aux = 0;
        FOR(k, 0, BITS) {
            if (OR[i][k] == 0) continue;
            ll aux2 = PRE[k];
            aux2 = (aux2 * OR[i][k]) % MOD;
            aux += aux2;
            if (aux >= MOD) aux -= MOD;
        }
        FOR(j, 0, BITS) {
            if (AND[i][j] == 0) continue;
            ll aux1 = PRE[j];
            aux1 = (aux1 * AND[i][j]) % MOD;
            ll tmp = aux * aux1;
            tmp %= MOD;
            ANS += tmp;
            if (ANS >= MOD) ANS -= MOD;
        }
    }
    printf("%lld\n", ANS);
}



int main() {
    FOR(i, 0, BITS) PRE[i] = (1ll << i) % MOD;
    int t; ri(t);
    while (t--) solve();

    return 0;
}