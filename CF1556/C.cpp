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

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

void solve() {
    int n; ri(n);
    string s[2];
    cin >> s[0] >> s[1];
    int dp[2][2] = {{0, 0}, { 0, 0}};
    for (int i = n - 1; i >= 0; --i) {
        int new_dp[2][2] = {{ -INF, -INF}, { -INF, -INF}};
        FOR(z, 0, 2) FOR(o, 0, 2) {
            int new_z = z | (s[0][i] == '0') | (s[1][i] == '0');
            int new_o = o | (s[0][i] == '1') | (s[1][i] == '1');
            new_dp[z][o] = dp[new_z][new_o];
            if (new_z && new_o)
                new_dp[z][o] = max(new_dp[z][o], 2 + dp[0][0]);
            if (new_z)
                new_dp[z][o] = max(new_dp[z][o], 1 + dp[0][0]);
            new_dp[z][o] = max(new_dp[z][o], dp[0][0]);
        }
        FOR(z, 0, 2) FOR(o, 0, 2) dp[z][o] = new_dp[z][o];
    }
    printf("%d\n", dp[0][0]);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}