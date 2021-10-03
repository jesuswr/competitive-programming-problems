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
const int MAXN = 3e3 + 69; // CAMBIAR ESTE
const int MOD = 998244353;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
string S, T;

ll DP[MAXN][MAXN];
ll f(int l, int i) {
    if (DP[l][i] != -1)
        return DP[l][i];
    DP[l][i] = (l >= M && i == 0);
    if (i > 0 && (S[l] == T[i - 1] || T[i - 1] == '?'))
        DP[l][i] += f(l + 1, i - 1);
    if (i + l < N && (S[l] == T[i + l] || T[i + l] == '?'))
        DP[l][i] += f(l + 1, i);
    return DP[l][i] % MOD;
}

int main() {
    memset(DP, -1, sizeof(DP));
    cin >> S; N = SZ(S);
    cin >> T; M = SZ(T);
    while (SZ(T) < N)
        T.pb('?');
    ll ans = 0;
    for (int i = 0; i < N; ++i) if (S[0] == T[i] || T[i] == '?')
            ans = (ans + 2 * f(1, i)) % MOD;
    printf("%lld\n", ans);
    return 0;
}