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
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM

int main() {
    int n;
    ri(n);
    vi a(n);
    vi neg_a_pre(n), neg_a_suf(n);
    FOR(i, 0, n) {
        ri(a[i]);
        neg_a_suf[i] = neg_a_pre[i] = ~a[i];
    }
    FOR(i, 1, n) {
        neg_a_pre[i] &= neg_a_pre[i - 1];
    }
    ROF(i, n - 2, -1) {
        neg_a_suf[i] &= neg_a_suf[i + 1];
    }
    int mx = -1;
    int mx_i;

    FOR(i, 0, n) {
        int curr = a[i];
        if (i > 0)
            curr = curr & neg_a_pre[i - 1];
        if (i < n - 1)
            curr = curr & neg_a_suf[i + 1];
        if (curr > mx) {
            mx = curr;
            mx_i = i;
        }
    }

    printf("%d ", a[mx_i]);
    FOR(i, 0, n) {
        if (i == mx_i)
            continue;
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}