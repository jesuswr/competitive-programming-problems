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
#define FOR(i,n,m) for(ll i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM

int main() {
    int n;
    ri(n);

    ll mx = 0;
    FOR(i, max(1, n - 50), n + 1) {
        FOR(j, max(1, n - 50), n + 1) {
            FOR(k, max(1, n - 50), n + 1) {
                ll new_lcm = i * j / __gcd(i, j);
                new_lcm = new_lcm * k / __gcd(new_lcm, k);
                mx = max(mx, new_lcm);
            }
        }
    }
    printf("%lld\n", mx);

    return 0;
}