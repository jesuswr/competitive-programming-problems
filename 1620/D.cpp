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
const int MAXN = 160; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[MAXN];


void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    int mx = -69;
    FOR(i, 0, N) mx = max(mx, A[i]);
    mx = mx / 3;

    int ans = 1e9;
    for (int c3 = max(0, mx - 2); c3 <= mx; ++c3) {
        for (int c2 = 0; c2 <= 2; ++c2) {
            int c1 = 0;
            FOR(i, 0, N) {
                int mx_c3 = min(A[i] / 3, c3);
                int mn_c1 = 1e9;
                for (int use_c3 = max(0, mx_c3 - 2); use_c3 <= mx_c3; ++use_c3) {
                    int ai = A[i] - 3 * use_c3;
                    ai -= 2 * min(ai / 2, c2);
                    mn_c1 = min(mn_c1, ai);
                }
                c1 = max(c1, mn_c1);
            }
            ans = min(ans, c1 + c2 + c3);
        }
    }
    printf("%d\n", ans);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}