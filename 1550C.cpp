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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];

int DP[MAXN][2];
int check(int l) {
    int cnt = 0;
    for (int r = l; r < N; ++r) {
        DP[r][0] = DP[r][1] = 1;

        for (int i = l; i < r; ++i) {
            if (A[r] <= A[i])
                DP[r][1] = max(DP[r][1], DP[i][1] + 1);
            if (A[r] >= A[i])
                DP[r][0] = max(DP[r][0], DP[i][0] + 1);
        }

        if (max(DP[r][0], DP[r][1]) >= 3)
            return cnt;
        cnt++;
    }
    return cnt;
}

void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);

    int ans = 0;
    FOR(i, 0, N)
        ans += check(i);
    printf("%d\n", ans);
}

int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}