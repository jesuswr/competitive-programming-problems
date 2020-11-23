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
const int MAXN = 55; // CAMBIAR ESTE

// GJNM
int N, K;
ll A, B;
ll W[MAXN];
ll suf[MAXN];
map<tuple<int, int, ll>, ll> dp;
ll dp2[MAXN][MAXN];

ll pick(int n, int k) {
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    if (dp2[n][k] != 0)
        return dp2[n][k];

    return dp2[n][k] = pick(n - 1, k - 1) + pick(n - 1, k);
}

ll f(int p, int k, ll s) {
    if (k > K || s > B || s + suf[p] < A)
        return 0;
    if (s >= A && s + suf[p] <= B) {
        return pick(N - p, K - k);
    }
    if (p == N) {
        if (A <= s && s <= B && k == K)
            return 1;
        else
            return 0;
    }

    if (dp.find({p, k, s}) != dp.end())
        return dp[ {p, k, s}];
    return dp[ {p, k, s}] = f(p + 1, k + 1, s + W[p]) + f(p + 1, k, s);
}

int main() {
    rii(N, K);
    FOR(i, 0, N) {
        rl(W[i]);
    }
    sort(W, W + N); reverse(W, W + N);
    for (int i = N - 1; i >= 0; i--) {
        suf[i] = W[i] + suf[i + 1];
    }
    rll(A, B);
    printf("%lld\n", f(0, 0, 0));

    return 0;
}