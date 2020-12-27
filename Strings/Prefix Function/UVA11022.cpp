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
string s;
int dp[100][100];

int pf(int l, int r) {
    int n = r - l;
    vi pi(n);
    FOR(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && s[i + l] != s[j + l]) j = pi[j - 1];
        if (s[i + l] == s[j + l]) pi[i] = j + 1;
    }

    int k = n - pi[n - 1];
    if (n % k == 0) return k;
    return n;
}

int f(int l, int r) {
    if (l == r - 1) return 1;
    if (dp[l][r] != -1) return dp[l][r];

    int aux = pf(l, r);
    int &ret = dp[l][r] = aux;
    FOR(m, 1, aux) ret = min(ret, f(l, m + l) + f(m + l, l + aux));
    for (int m = l + 1; m < r; m++) ret = min(ret, f(l, m) + f(m, r)); // no hace falta pero confio mas xD
    return ret;
}

int main() {
    while (cin >> s, s[0] != '*') {
        FOR(i, 0, 81) FOR(j, 0, 81) dp[i][j] = -1;
        printf("%d\n", f(0, SZ(s)));
    }

    return 0;
}