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
const int MAXN = 1010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
bool M[MAXN][MAXN];

void solve() {
    int n; ri(n);
    FOR(i, 1, n + 1) FOR(j, 1, n + 1) M[i][j] = 0;
    vi l(n), r(n);
    FOR(i, 0, n) rii(l[i], r[i]);
    FOR(i, 0, n) M[l[i]][r[i]] = 1;

    FOR(i, 0, n) {
        if (l[i] == r[i]) {
            printf("%d %d %d\n", l[i], r[i], l[i]);
            continue;
        }
        FOR(j, 0, n) if (i != j) {
            if (l[i] == l[j] && r[i] == r[j] + 1) {
                printf("%d %d %d\n", l[i], r[i], r[i]);
                break;
            }
            if (l[i] + 1 == l[j] && r[i] == r[j]) {
                printf("%d %d %d\n", l[i], r[i], l[i]);
                break;
            }
            if (l[i] == l[j] && r[i] > r[j] && M[r[j] + 2][r[i]]) {
                printf("%d %d %d\n", l[i], r[i], r[j] + 1);
                break;
            }
            assert(j + 1 != n);
        }
    }
    // printf("\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}