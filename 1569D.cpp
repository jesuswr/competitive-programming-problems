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
const int MAXN = 3e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M, K;
int H[MAXN], V[MAXN];
int X[MAXN], Y[MAXN];

void solve() {
    riii(N, M, K);
    FOR(i, 0, N) ri(V[i + 1]);
    FOR(i, 0, M) ri(H[i + 1]);
    V[0] = H[0] = -1;
    ++N, ++M;
    FOR(i, 0, K) rii(X[i], Y[i]);

    vector<map<int, int>> cntv(N), cnth(M);
    FOR(i, 0, K) {
        int Vi = lb(V, V + N, X[i]) - V;
        if (Vi < N && V[Vi] != X[i])
            Vi = N;
        int Hi = lb(H, H + M, Y[i]) - H;
        if (Hi < M && H[Hi] != Y[i])
            Hi = M;

        if (Vi < N && Hi < M)
            continue;
        if (Vi < N) {
            Hi = lb(H, H + M, Y[i]) - H - 1;
            cnth[Hi][X[i]]++;
        }
        else {
            Vi = lb(V, V + N, X[i]) - V - 1;
            cntv[Vi][Y[i]]++;
        }
    }
    ll ans = 0;
    for (auto m : cntv) {
        ll cnt = 0;
        for (auto x : m) {
            cnt += x.S;
            ans -= ((x.S - 1) * x.S) / 2;
        }
        ans += (cnt * (cnt - 1)) / 2;
    }
    for (auto m : cnth) {
        ll cnt = 0;
        for (auto x : m) {
            cnt += x.S;
            ans -= ((x.S - 1) * x.S) / 2;
        }
        ans += (cnt * (cnt - 1)) / 2;
    }
    printf("%lld\n", ans);
}

int main() {
    int t; ri(t);
    while (t--)solve();
    return 0;
}