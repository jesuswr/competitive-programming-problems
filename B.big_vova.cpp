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
const int MAXN = 1e3 + 10; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN], b[MAXN];
bool used[MAXN];

void solve() {
    ri(n);
    int gcd = 0;
    FOR(i, 0, n) {
        ri(a[i]);
        used[i] = false;
    }

    FOR(i, 0, n) {
        int new_gcd = -1;
        int ind;
        FOR(j, 0, n) {
            if (used[j])
                continue;
            if (__gcd(gcd, a[j]) > new_gcd) {
                new_gcd = __gcd(gcd, a[j]);
                ind = j;
            }
        }

        gcd = new_gcd;
        used[ind] = true;
        b[i] = a[ind];
    }

    FOR(i, 0, n) {
        printf("%d%c", b[i], " \n"[i == n - 1]);
    }
}

int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
    }

    return 0;
}