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
const int MAXN = 1e7 + 10; // CAMBIAR ESTE

// GJNM
int min_div[MAXN];

int main() {
    FOR(i, 0, MAXN) {
        min_div[i] = 1e8;
    }
    FOR(i, 2, MAXN) {
        if (min_div[i] < i)
            continue;
        min_div[i] = i;
        int j = i;
        while (j < MAXN) {
            min_div[j] = min(min_div[j], i);
            j += i;
        }
    }

    int n;
    ri(n);
    vi d1, d2;
    FOR(i, 0, n) {
        int a; ri(a);
        vi primes;
        while (a > 1) {
            primes.pb(min_div[a]);
            int b = min_div[a];
            while (min_div[a] == b)
                a /= b;
        }
        if (primes.size() == 1) {
            d1.pb(-1), d2.pb(-1);
        }
        else {
            d1.pb(primes[0]);
            int other = 1;
            FOR(i, 1, primes.size()) {
                other *= primes[i];
            }
            d2.pb(other);
        }
    }
    for (auto x : d1) {
        printf("%d ", x);
    } printf("\n");
    for (auto x : d2) {
        printf("%d ", x);
    } printf("\n");
    return 0;
}