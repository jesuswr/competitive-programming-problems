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

ll qor(int i, int j) {
    printf("or %d %d\n", i + 1, j + 1);
    fflush(stdout);
    int ret; ri(ret);
    return ret;
}
ll qand(int i, int j) {
    printf("and %d %d\n", i + 1, j + 1);
    fflush(stdout);
    int ret; ri(ret);
    return ret;
}

int A[MAXN];

int main() {
    int n, k; rii(n, k);

    ll or01 = qor(0, 1), and01 = qand(0, 1);
    ll or12 = qor(1, 2), and12 = qand(1, 2);
    ll or02 = qor(0, 2), and02 = qand(0, 2);

    ll x = (or01 - and01) + 2 * (and01);
    ll y = (or12 - and12) + 2 * (and12);
    ll z = (or02 - and02) + 2 * (and02);

    ll a = (x - y + z) / 2; A[0] = a;
    ll c = z - a; A[2] = c;
    ll b = y - c; A[1] = b;

    FOR(i, 3, n) {
        ll or0i = qor(0, i), and0i = qand(0, i);
        A[i] = (or0i - and0i) + 2 * (and0i) - A[0];
    }
    sort(A, A + n);
    printf("finish %d\n", A[k - 1]);

    return 0;
}