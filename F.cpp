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
const int MAXN = 2100; // CAMBIAR ESTE

// GJNM
int R, N, MOD;

ll PICK[MAXN][MAXN];

ll DP[MAXN][MAXN][2];
ll f(int bigger, int smaller, int r) {

}


int main() {
    memset(DP, -1, sizeof(DP));
    riii(R, N, MOD);

    FOR(i, 0, MAXN) {
        PICK[i][0] = 1;
        PICK[i][i] = 1;
        FOR(k, 1, i) PICK[i][k] = (PICK[i - 1][k] + PICK[i - 1][k - 1]) % MOD;
    }
    printf("%lld\n", f(N - R, R - 1, true));
    return 0;
}