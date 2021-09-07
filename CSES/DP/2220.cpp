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
vi N;

ll DP[20][10][3]; // pos, prev digits, (<, ==, >) N
ll f() {
    DP[SZ(N)][0][1] = 0;
    for (int p = SZ(N) - 1; p >= 0; --p) {
        for (int d = 0; d < 10; ++d) {
            for (int s = 0; s < 3; ++s) {
                DP[p][d][s] = 0;
                if (p == SZ(N) - 1) {
                    if (s == 0) {
                        DP[p][d][s] = 9;
                    }
                    else if (s == 1) {
                        FOR(nd, 0, 10) if (nd != d && nd <= N[p])
                            ++DP[p][d][s];
                    }
                }
                else {
                    if (s == 0) {
                        FOR(nd, 0, 10) if (nd != d)
                            DP[p][d][s] += 1 + DP[p + 1][nd][0];
                    }
                    else if (s == 1) {
                        FOR(nd, 0, 10) if (nd != d) {
                            ++DP[p][d][s];
                            if (nd < N[p])
                                DP[p][d][s] += DP[p + 1][nd][0];
                            else if (nd == N[p])
                                DP[p][d][s] += DP[p + 1][nd][1];
                            else
                                DP[p][d][s] += DP[p + 1][nd][2];
                        }
                    }
                    else {
                        FOR(nd, 0, 10) if (nd != d) {
                            ++DP[p][d][s];
                            DP[p][d][s] += DP[p + 1][nd][2];
                        }
                    }
                }
            }
        }
    }
    return DP[0][0][1] + 1;
}

int main() {
    ll a, b; rll(a, b);
    while (b > 0) {
        N.pb(b % 10);
        b /= 10;
    }
    reverse(ALL(N));

    ll ans = f();

    if (a - 1 >= 0) {
        N.clear();
        a--;
        while (a > 0) {
            N.pb(a % 10);
            a /= 10;
        }
        reverse(ALL(N));
        ans -= f();
    }

    printf("%lld\n", ans);
    return 0;
}