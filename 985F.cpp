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
#include <random>
#include <chrono>

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
const int MAXN = 2e5 + 69; // CAMBIAR ESTE
const int MOD = 1000000289;
const int p = 2;
const int ALPHA = 26;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, Q;
string A;
int PREF[MAXN][ALPHA];
int P[MAXN];
void pre() {
    P[0] = p;
    FOR(i, 1, MAXN) P[i] = (1ll * P[i - 1] * p) % MOD;
    for (int i = N - 1; i >= 0; --i) FOR(j, 0, ALPHA)
        PREF[i][j] = ((A[i] == ('a' + j)) + 1ll * PREF[i + 1][j] * p) % MOD;
}
vi qry(int l, int r) { // [l, r)
    int len = r - l;
    vi ret(ALPHA);
    FOR(i, 0, ALPHA)
        ret[i] = (PREF[l][i] - (1ll * P[len - 1] * PREF[r][i]) % MOD + MOD) % MOD;
    sort(ALL(ret));
    return ret;
}

int main() {
    rii(N, Q);
    cin >> A;
    pre();
    while (Q--) {
        int l1, l2, len; riii(l1, l2, len); --l1, --l2;
        if (qry(l1, l1+len) == qry(l2, l2+len))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}