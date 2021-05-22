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
const int MAXN = 1e3 + 10; // CAMBIAR ESTE

// GJNM
int N;
int DP[MAXN][MAXN][2][2][2];
bool VIS[MAXN][MAXN][2][2][2];
int f(int eq, int dst, int mid, int rev, int turn) {
    int &ret = DP[eq][dst][mid][rev][turn];
    if (VIS[eq][dst][mid][rev][turn]) return ret;
    VIS[eq][dst][mid][rev][turn] = true;
    if (eq == 0 && dst == 0 && mid == 0) return ret = 0;

    if (turn == 0) { // maximize
        ret = -INF;
        if (eq > 0) ret = max(ret, -1 + f(eq - 1, dst + 1, mid, 0, 1));
        if (dst > 0) ret = max(ret, -1 + f(eq, dst - 1, mid, 0, 1));
        if (rev == 0 && dst > 0) ret = max(ret, f(eq, dst, mid, 1, 1));
        if (mid > 0) ret = max(ret, -1 + f(eq, dst, 0, 0, 1));
    }
    else { // minimize
        ret = INF;
        if (eq > 0) ret = min(ret, 1 + f(eq - 1, dst + 1, mid, 0, 0));
        if (dst > 0) ret = min(ret, 1 + f(eq, dst - 1, mid, 0, 0));
        if (rev == 0 && dst > 0) ret = min(ret, f(eq, dst, mid, 1, 0));
        if (mid > 0) ret = min(ret, 1 + f(eq, dst, 0, 0, 0));
    }
    //printf("%d %d %d %d %d : %d\n", eq, dst, mid, rev, turn, ret);
    return ret;
}

void solve() {
    ri(N);
    string s; cin >> s;
    int l = 0, r = N - 1;
    int cnt = 0, cnt2 = 0;
    while (l < r) {
        if (s[l] == s[r] && s[l] == '0') cnt++;
        else if (s[l] == '0' || s[r] == '0') cnt2++;
        ++l, --r;
    }
    int md = (N & 1) && (s[N / 2] == '0');
    int ans = f(cnt, cnt2, md, 0, 0);
    if (ans > 0) printf("ALICE\n");
    else if (ans == 0) printf("DRAW\n");
    else printf("BOB\n");
}

int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}