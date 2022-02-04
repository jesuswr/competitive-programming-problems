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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll N, M;
vector<ll> A;
vector<pair<ll, int>> H, L;

int main() {
    rll(N, M);
    FOR(i, 0, N) {
        ll a, b; rll(a, b);
        if (b == 1)
            L.pb({a, i + 1});
        else
            H.pb({a, i + 1});
        A.pb(a);
    }
    sort(ALL(A)); A.pb(0);
    sort(ALL(L)); L.pb({0, 0});
    sort(ALL(H)); H.pb({0, 0});

    reverse(ALL(A));
    reverse(ALL(L));
    reverse(ALL(H));

    for (int i = 1; i < SZ(A); ++i)
        A[i] += A[i - 1];
    for (int i = 1; i < SZ(L); ++i)
        L[i].F += L[i - 1].F;
    for (int i = 1; i < SZ(H); ++i)
        H[i].F += H[i - 1].F;

    int mn = 0;
    for (;; ++mn) {
        if (A[mn] >= M)
            break;
    }

    int mx = 0;
    for (int l = 1; l <= mn; ++l) {
        if (mn - l < SZ(H) && l < SZ(L)) {
            if (L[l].F + H[mn - l].F >= M)
                mx = l;
        }
    }
    printf("%d %d\n", mn, mx);
    for (int i = 1; i <= mx; ++i) printf("%d ", L[i].S);
    for (int i = 1; i <= mn - mx; ++i) printf("%d ", H[i].S);
    printf("\n");
    return 0;
}