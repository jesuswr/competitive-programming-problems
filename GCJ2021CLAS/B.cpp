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

using namespace std;

typedef long long ll;
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

// GJNM
int N, X, Y;
string S;
// CJ -> X
// JC -> Y

void solve() {
    rii(X, Y); cin >> S; N = SZ(S);
    ll dp[2] = {0, 0};
    if (S[0] == 'C') dp[1] = LLINF;
    if (S[0] == 'J') dp[0] = LLINF;
    FOR(i, 1, N) {
        ll new_dp[2];
        if (S[i] == 'C') {
            new_dp[0] = min(dp[0], dp[1] + Y);
            new_dp[1] = LLINF;
        }
        else if (S[i] == 'J') {
            new_dp[0] = LLINF;
            new_dp[1] = min(dp[1], dp[0] + X);
        }
        else {
            new_dp[0] = min(dp[0], dp[1] + Y);
            new_dp[1] = min(dp[1], dp[0] + X);
        }
        swap(dp[0], new_dp[0]);
        swap(dp[1], new_dp[1]);
    }
    printf("%lld\n", min(dp[0], dp[1]));
}


int main() {
    int t; ri(t);
    FOR(i, 0, t) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}