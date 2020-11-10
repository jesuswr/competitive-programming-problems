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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int n, m;
ll a[MAXN], b[MAXN];
ll d[MAXN];

int main() {
    ri(n);
    FOR(i, 0, n) {
        rl(a[i]);
    }
    FOR(i, 0, n) {
        rl(b[i]);
    }

    FOR(i, 0, n) {
        d[i + 1] = (a[i] - b[i]) * (a[i] - b[i]);
        d[i + 1] += d[i];
    }

    ri(m);
    FOR(_, 0, m) {
        int l, r; rii(l, r);
        long double tmp = d[r] - d[l - 1];
        tmp = sqrt(tmp);
        printf("%Lf\n", tmp);
    }

    return 0;
}