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
#include <time.h>

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
ll N, K;
ll X[MAXN];

void solve() {
    rll(N, K);
    FOR(i, 0, N) rl(X[i]);
    bool has_zero = false;
    FOR(i, 0, N) has_zero |= X[i] == 0;
    if (has_zero) {
        ll g = 0;
        FOR(i, 0, N) g = __gcd(g, X[i]);
        if (K % g == 0) printf("YES\n");
        else printf("NO\n");
    }
    else {
        FOR(_, 0, min(N, 100ll)) { 
            int j = rand() % N; // maybe?
            ll g = 0;
            FOR(i, 0, N) if (j != i) g = __gcd(g, X[i] - X[j]);
            if ((K - X[j]) % g == 0) {
                printf("YES\n");
                return;
            }
        }
        printf("NO\n");
    }

}

int main() {
    srand(time(0));
    int t; ri(t);
    while (t--) solve();
    return 0;
}