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
int N;

struct box {
    ll a, b;
    int i;
    bool operator<(box other) {
        return a < other.a;
    }
};

box A[MAXN];
ll need_a, need_b;


bool go(vi inds) {
    ll a = 0, b = 0;
    for (auto i : inds) {
        a += A[i].a;
        b += A[i].b;
    }
    if (2 * a < need_a || 2 * b < need_b)
        return false;
    printf("YES\n");
    for (auto i : inds) printf("%d ", A[i].i);
    printf("\n");
    return true;
}


void solve() {
    ri(N);
    need_a = 0, need_b = 0;
    FOR(i, 0, 2 * N - 1) {
        A[i].i = i + 1;
        rll(A[i].a, A[i].b);
        need_a += A[i].a;
        need_b += A[i].b;
    }
    N = 2 * N - 1;
    sort(A, A + N);

    vi op1, op2;
    FOR(i, 0, N - 1) {
        if (i & 1) op1.pb(i);
        else op2.pb(i);
    }
    op1.pb(N - 1);
    op2.pb(N - 1);

    if (go(op1) || go(op2))
        return;
    printf("NO\n");
}



int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}