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


void solve() {
    int n; ri(n);
    vi a(n), b(n);
    FOR(i, 0, n) ri(a[i]);
    FOR(i, 0, n) ri(b[i]);
    multiset<pii> A, B;

    if ((n & 1) && a[n >> 1] != b[n >> 1]) {
        printf("no\n");
        return;
    }

    int l = 0, r = n - 1;
    while (l < r) {
        pii x = {min(a[l], a[r]), max(a[l], a[r])};
        pii y = {min(b[l], b[r]), max(b[l], b[r])};
        A.insert(x);
        B.insert(y);
        l++, r--;
    }
    if (A == B)
        printf("yEs\n");
    else
        printf("nO\n");
}



int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}