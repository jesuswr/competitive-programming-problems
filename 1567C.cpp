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
int N;
vi DIG;

ll DP[20][2][2];
void solve() {
    ri(N);
    DIG.clear();
    while (N > 0) {
        DIG.pb(N % 10);
        N /= 10;
    }
    N = SZ(DIG);

    DP[N][0][0] = 1;
    DP[N][0][1] = DP[N][1][0] = DP[N][1][1] = 0;

    for (int i = N - 1; i >= 0; --i) {
        FOR(c1, 0, 2) FOR(c2, 0, 2) {
            DP[i][c1][c2] = 0;
            FOR(a, 0, 10) FOR(b, 0, 10) {
                int c = a + b + c1;
                if (c % 10 == DIG[i]) {
                    DP[i][c1][c2] += DP[i + 1][c2][c / 10];
                }
            }
        }
    }

    printf("%lld\n", DP[0][0][0] - 2);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}