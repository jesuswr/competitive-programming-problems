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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE
const ll MOD = 4294967296ll;

// GJNM
ll all[8][8];
ll dp[8][8];
ll new_dp[8][8];
pii moves[8] = {{2, 1}, {2, -1}, { -2, 1}, { -2, -1}, {1, 2}, {1, -2}, { -1, 2}, { -1, -2}};

int main() {
    int n; ri(n);
    dp[0][0] = 1;
    all[0][0] = 1;

    FOR(i, 0, n) {
        FOR(r, 0, 8) {
            FOR(c, 0, 8) {
                new_dp[r][c] = 0;
            }
        }

        FOR(r, 0, 8) {
            FOR(c, 0, 8) {
                FOR(m, 0, 8) {
                    if (r + moves[m].F >= 0 && r + moves[m].F < 8 && c + moves[m].S >= 0 && c + moves[m].S < 8) {
                        new_dp[r + moves[m].F][c + moves[m].S] += dp[r][c];
                    }
                }
            }
        }

        FOR(r, 0, 8) {
            FOR(c, 0, 8) {
                dp[r][c] = new_dp[r][c];
                all[r][c] += new_dp[r][c];
            }
        }
    }
    ll sm = 0;
    FOR(r, 0, 8) FOR(c, 0, 8) {
        sm += all[r][c];
    }
    printf("%lld\n", sm);

    return 0;
}