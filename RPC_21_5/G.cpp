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
const int MAXN = 1e6 + 10; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
int N;
int A[MAXN];
ll DP[MAXN];
ll CNT[4];

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    ll aux = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (A[i] == 1) {
            continue;
        }
        else if (A[i] == 2) {
            DP[i] = CNT[3];
            DP[i] += aux;
            if (DP[i] >= MOD) DP[i] -= MOD;
            aux += DP[i];
            if (aux >= MOD) aux -= MOD;
        }
        else {
            CNT[3]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) CNT[1]++;
        else if (A[i] == 2) {
            ans += (CNT[1] * DP[i]);
            ans %= MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}