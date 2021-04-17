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
int DP[1 << 11][11];
char S[MAXN];
int CNT[11][11];

int f(int msk, int ind) {
    if (DP[msk][ind] != -1) return DP[msk][ind];
    if (msk == (1 << 10) - 1) return 0;
    int aux = 0;
    FOR(on, 0, 10) if (msk & (1 << on)) {
        FOR(off, 1, 10) if (( msk & (1 << off)) == 0 ) {
            aux += CNT[on][off] + CNT[off][on];
        }
    }
    int ans = 1e9;
    FOR(off, 1, 10) if ((msk & (1 << off)) == 0) {
        ans = min(ans, aux + f(msk | (1 << off), off));
    }
    return DP[msk][ind] = ans;
}

int main() {
    memset(DP, -1, sizeof(DP));
    dadsadasda = scanf("%s", S);
    CNT[0][S[0] - '0']++;
    int n = strlen(S);
    FOR(i, 0, n - 1) ++CNT[S[i] - '0'][S[i + 1] - '0'];
    printf("%d\n", f(1, 0) - 1 + n);
    return 0;
}