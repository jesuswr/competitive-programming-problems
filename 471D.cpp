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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int N, W;
int A[MAXN], B[MAXN];

vi pf(const vi &s) {
    int n = SZ(s);
    vi pi(n);
    FOR(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j + 1;
    }
    return pi;
}

int kmp(const vi &s) {
    vi pi = pf(s);
    int cnt = 0;
    FOR(i, W + 1, SZ(pi)) cnt += (pi[i] == W);
    return cnt;
}

int main() {
    rii(N, W);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, W) ri(B[i]);
    if (W == 1) {
        printf("%d\n", N);
        return 0;
    }
    vi t;
    FOR(i, 0, W - 1) t.pb(B[i + 1] - B[i]);
    t.pb(1e9 + 10);
    FOR(i, 0, N - 1) t.pb(A[i + 1] - A[i]);
    W--; N--;
    printf("%d\n", kmp(t));
    return 0;
}