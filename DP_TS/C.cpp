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
int hasA(string s) {
    for (auto c : s) if (c == 'A')
            return 1;
    return 0;
}
int hasB(string s) {
    for (auto c : s) if (c == 'B')
            return 2;
    return 0;
}
int hasC(string s) {
    for (auto c : s) if (c == 'C')
            return 4;
    return 0;
}

int main() {
    int n; ri(n);
    vi dp(8, INF);
    dp[0] = 0;
    FOR(i, 0, n) {
        int c; ri(c);
        string S; cin >> S;
        FOR(msk, 0, 8) {
            dp[msk | hasA(S) | hasB(S) | hasC(S)] = min(dp[msk] + c, dp[msk | hasA(S) | hasB(S) | hasC(S)]);
        }
    }
    if (dp[7] == INF)
        printf("-1\n");
    else
        printf("%d\n", dp[7]);
    return 0;
}