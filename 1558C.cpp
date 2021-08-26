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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int n;
int A[6969];

void rev(int l) {
    reverse(A + 1, A + l + 1);
}

int fnd(int x) {
    for (int i = 1; i <= n; ++ i) if (x == A[i])
            return i;
}

void solve() {
    ri(n);
    bool good = true;
    for (int i = 1; i <= n; ++i) {
        ri(A[i]);
        good &= (A[i] & 1) == (i & 1);
    }

    if (!good) {
        printf("-1\n");
        return;
    }

    vi moves;
    for (int x = n; x > 1; x -= 2) {
        int xi = fnd(x);
        moves.pb(xi);
        rev(xi);

        int yi = fnd(x - 1);
        moves.pb(yi - 1);
        rev(yi - 1);

        moves.pb(yi + 1);
        rev(yi + 1);

        moves.pb(3);
        rev(3);

        moves.pb(x);
        rev(x);
    }

    printf("%d\n", SZ(moves));
    for (auto m : moves) printf("%d ", m);
    if (SZ(moves) > 0) printf("\n");
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}