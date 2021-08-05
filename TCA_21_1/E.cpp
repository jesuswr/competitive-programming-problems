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
int n;
int a[MAXN];

int query(int a, int b) {
    printf("? %d %d\n", a + 1, b + 1);
    fflush(stdout);
    int ret; ri(ret);
    return ret;
}

int main() {
    ri(n);
    int x = query(0, 1), y = query(1, 2), z = query(0, 2);

    a[0] = (x - y + z) / 2;
    a[1] = x - a[0];
    a[2] = z - a[0];

    FOR(i, 3, n) {
        int sm = query(0, i);
        a[i] = sm - a[0];
    }
    printf("!");
    FOR(i, 0, n) printf(" %d", a[i]);
    printf("\n");
    fflush(stdout);

    return 0;
}