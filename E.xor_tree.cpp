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
#define ROF(i,n,m) for(int i=n; i>=m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n;

int f(vi S, int bit = 30) {
    if (S.size() == 0)
        return 0;
    if (bit == 0)
        return S.size();

    vi S0, S1;
    for (auto x : S) {
        if (x & (1 << bit))
            S1.pb(x);
        else
            S0.pb(x);
    }
    int n0 = S0.size(), n1 = S1.size();
    if (n0 == 0)
        return f(S1, bit - 1);
    if (n1 == 0)
        return f(S0, bit - 1);
    return 1 + max(f(S0, bit - 1), f(S1, bit - 1));
}

int main() {
    ri(n);
    vi a(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    printf("%d\n", n - f(a, 30));

    return 0;
}