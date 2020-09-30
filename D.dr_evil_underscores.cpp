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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int solve(vi &all, int bit) {
    if (bit < 0)
        return 0;
    vi on, off;
    for (auto a : all) {
        if (a & (1 << bit))
            on.pb(a);
        else
            off.pb(a);
    }

    if (on.empty())
        return solve(off, bit - 1);
    else if (off.empty())
        return solve(on, bit - 1);
    else
        return ((1 << bit) + min(solve(on, bit - 1), solve(off, bit - 1)));
}



int main() {
    int n; ri(n);
    vi a;
    FOR(i, 0, n) {
        int aux; ri(aux);
        a.pb(aux);
    }

    printf("%d\n", solve(a, 30));

    return 0;
}