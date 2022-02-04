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
int N;
int A[110];

int go(int l, int r) {
    int cnt = N;
    int gcd = __gcd(r - l, abs(A[r] - A[l]));
    int diff = (r - l) / gcd;
    int jump = (A[r] - A[l]) / gcd;
    // printf("%d %d\n", l, r);
    // printf("\t%d %d\n", diff, jump);
    for (int i = l; i < N; i += diff) {
        if (A[i] == A[l] + ((i - l) * jump) / diff) {
            cnt--;
        }
    }
    for (int i = l - diff; i >= 0; i -= diff) {
        if (A[i] == A[l] + ((i - l) * jump) / diff) {
            cnt--;
        }
    }
    return cnt;
}

void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    int ans = N - 1;
    FOR(i, 0, N) FOR(j, i + 1, N) {
        ans = min(ans, go(i, j));
    }
    printf("%d\n", ans);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}