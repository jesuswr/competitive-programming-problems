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
const int MAXN = 4e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
pii A[MAXN];
ll P[MAXN];

ll sum(int l, int r) {
    ll ret = P[r] - (l > 0 ? P[l - 1] : 0);
    return ret;
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i].F);
    FOR(i, 0, N) A[i].S = i + 1;
    sort(A, A + N);
    FOR(i, 0, N) P[i] = A[i].F + (i > 0 ? P[i - 1] : 0);
    ri(K);
    ll ans;
    ll bsti = 0;
    ll aux = 0;

    FOR(i, 1, K) aux += 1ll * i * A[i].F - sum(0, i - 1);
    ans = aux;
    FOR(l, 1, N - K + 1) {
        aux = aux + 1ll * (K - 1) * A[l + K - 1].F - sum(l, l + K - 2) + 1ll * (K - 1) * A[l - 1].F - sum(l, l + K - 2);
        if (aux < ans) {
            ans = aux;
            bsti = l;
        }
    }
    FOR(i, 0, K) printf("%d ", A[bsti + i].S);
    printf("\n");
    return 0;
}

// f(0,0) = 0
// f(0,i+1) = f(0,i) + sum(j<i)(xi - xj) = f(0,i) + i * xi - sum(j<i)(xj)

// f(j+1,i) = f(j,i) + (K-1) * x(j+K) - sum(j+1,j+K-1)(xi) + (K-1)*xj - sum(j+1,j+K-1)(xi)