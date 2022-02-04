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
const int MAXN = 3e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll N; ll K;
ll A[MAXN];
ll B[MAXN];

void solve() {
    rl(N); rl(K);
    FOR(i, 0, N) rl(A[i]);
    sort(A, A + N);
    ll tot = 0;
    FOR(i, 0, N) tot += A[i];
    if (tot <= K) {
        printf("0\n");
        return;
    }
    ll curr = 0;
    ll ans = LLINF;
    for (ll keep = 0; keep <= N - 1; ++keep) {
        ll others = (K - curr) / (N - keep);
        if (K - curr < 0) {
            others = (curr - K + (N - keep) - 1) / (N - keep);
            others = -others;
        }
        ll _ans = max(A[0] - others, 0ll) + N - keep - 1;
        // printf("%d:\n", keep);
        // printf("Bajo el mas pequeno a %lld, me cuesta %lld\n", others, max(A[0] - others, 0ll));
        // printf("%lld / %lld\n", curr, tot - curr);
        // printf("%lld %lld\n", K, curr);
        // printf("%lld\n", _ans);
        ans = min(ans, _ans);
        curr += A[keep + 1];
    }
    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}