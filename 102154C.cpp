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
int N;
int A[MAXN];

vii ops;

void op(int l, int r) {
    ops.pb({l + 1, r + 1});
    vi aux;
    for (int i = l + 1; i <= r; i += 2)
        aux.pb(A[i]);
    for (int i = l; i <= r; i += 2)
        aux.pb(A[i]);
    for (int i = l; i <= r; ++i)
        A[i] = aux[i - l];
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) --A[i];
    for (int i = 0; i < N; ++i) {
        while (A[i] != i) {
            FOR(j, i + 1, N) if (A[j] == i) {
                if ((j - i) & 1)
                    op(i, N - 1);
                else
                    op(i + 1, N - 1);
                break;
            }
        }
    }

    printf("%d\n", SZ(ops));
    for (auto [l, r] : ops) printf("%d %d\n", l, r);
    // FOR(i, 0, N) printf("%d\n", A[i] + 1);

    return 0;
}