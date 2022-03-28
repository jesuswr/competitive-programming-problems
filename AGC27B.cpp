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
const ll LLINF = 9e18;
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, X;
ll A[MAXN];

int main() {
    rii(N, X);
    FOR(i, 0, N) rl(A[i + 1]);
    FOR(i, 1, N + 1) A[i] += A[i - 1];
    ll mn = LLINF;
    FOR(x, 1, N + 1) {
        ll ans = 1ll * N * X + 1ll * x * X;
        ll coef = 3;
        for (int i = N; i > 0; i -= x) {
            ans += (A[i] - A[max(0, i - x)]) * max(5ll, coef);
            coef += 2;
            if (ans >= mn) break;
        }
        mn = min(mn, ans);
    }
    printf("%lld\n", mn);
    return 0;
}