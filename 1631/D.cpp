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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
int A[MAXN];
int B[MAXN];

void solve() {
    rii(N, K);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) B[i] = A[i];
    int G = (N + K + 1) / 2;
    sort(B, B + N);
    int l = 0, r = INF;
    for (int i = 0; i <= N - G; ++i) {
        if (r - l > B[i + G - 1] - B[i]) {
            l = B[i];
            r = B[i + G - 1];
        }
    }
    printf("%d %d\n", l, r);
    int prv = 0;
    int i = 0;
    int cnt = 0;
    for (; i < N && K > 1; ++i) {
        cnt += ((A[i] <= r && A[i] >= l) ? 1 : -1);
        if (cnt > 0) {
            --K;
            printf("%d %d\n", prv + 1, i + 1);
            prv = i + 1;
            cnt = 0;
        }
    }
    printf("%d %d\n", prv + 1, N);
    // printf("\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}