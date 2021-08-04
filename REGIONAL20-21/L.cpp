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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM

int main() {
    int n, x;
    rii(n, x);
    vii ts;
    FOR(_, 0, n) {
        int a, b; rii(a, b);
        ts.pb({a, a + b});
    }

    int mn = INF, mni;
    FOR(i, 0, 8 * 60 + 1) {
        int curr = 0;
        for (auto [a, b] : ts) {
            curr += i >= a && i <= b;
            a = max(a - i, 0);
            b = max(b - i, 0);
            curr += b / x - (max(a - 1, 0)) / x;
        }
        if (curr < mn) {
            mn = curr;
            mni = i;
        }
    }
    printf("%d %d\n", mni, mn);
    return 0;
}