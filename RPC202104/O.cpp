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
const ll MOD = 998244353;

// GJNM
int N;
char S[MAXN];
ll DP[MAXN][10][3];

ll f(int p, int x, int l) {
    if (p == N) return 0;
    if (DP[p][x][l] != -1) return DP[p][x][l];
    ll ans = 0;
    if (l == 0) {
        ans = 1;
        FOR(i, 0, 10) if (x != i) ans += f(p + 1, i, 0);
    }
    else if (l == 1) {
        ans = 1;
        FOR(i, 0, 10) if (i != x) {
            int nxt = S[p + 1] - '0';
            if (i < nxt) ans += f(p + 1, i, 0);
            if (i == nxt) ans += f(p + 1, i, 1);
            if (i > nxt) ans += f(p + 1, i, 2);
        }
    }
    else {
        if (p == N - 1) ans = 0;
        else {
            ans = 1;
            FOR(i, 0, 10) if (i != x) ans += f(p + 1, i, 2);
        }
    }
    return DP[p][x][l] = ans % MOD;
}

bool good() {
    FOR(i, 1, N) if (S[i] == S[i - 1]) return false;
    return true;
}

int main() {
    dadsadasda = scanf("%s", S);
    N = strlen(S);
    memset(DP, -1, sizeof(DP));
    ll down = 0;
    FOR(i, 1, 10) {
        int nxt = S[0] - '0';
        if (i < nxt) down += f(0, i, 0);
        if (i == nxt) down += f(0, i, 1);
        if (i > nxt) down += f(0, i, 2);
    }
    down = down - good();
    down %= MOD;

    dadsadasda = scanf("%s", S);
    N = strlen(S);
    memset(DP, -1, sizeof(DP));
    ll top = 0;
    FOR(i, 1, 10) {
        int nxt = S[0] - '0';
        if (i < nxt) top += f(0, i, 0);
        if (i == nxt) top += f(0, i, 1);
        if (i > nxt) top += f(0, i, 2);
    }
    top %= MOD;
    printf("%lld\n", (top - down + MOD) % MOD);
    return 0;
}