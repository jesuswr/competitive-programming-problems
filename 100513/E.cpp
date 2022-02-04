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
const int MAXN = 3e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[MAXN], B[MAXN];
vii ans;

bool valid(int k) {
    ans.clear();
    int votes[2] = {0, 0};
    FOR(i, 0, N) {
        if (A[i] > B[i]) votes[0]++;
        if (A[i] < B[i]) votes[1]++;
    }

    int i = 0;
    int n = N;
    while (i + 1 < N) {
        if (k == 0)
            break;
        int won1 = (A[i] > B[i]) + (A[i + 1] > B[i + 1]);
        int won2 = (A[i] + A[i + 1] > B[i] + B[i + 1]);
        if (won2 >= won1) {
            --n;
            ans.pb({i + 1, i + 2});
            i += 2;
            --k;
        }
        else
            ++i;
    }
    return 2 * votes[0] > n;
}

int main() {
    ri(N);
    FOR(i, 0, N) rii(A[i], B[i]);
    int lo = 0, hi = N + 1;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (valid(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    if (hi == N + 1)
        printf("-1\n");
    else {
        printf("%d\n", hi);
        valid(hi);
        for (auto [l, r] : ans) printf("%d %d\n", l, r);
    }

    return 0;
}