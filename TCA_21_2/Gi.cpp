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
int A[4];

bool triangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

bool segment(int a, int b, int c) {
    int mx = max({a, b, c});
    return a + b + c == 2 * mx;
}

int main() {
    FOR(i, 0, 4) ri(A[i]);
    FOR(i, 0, 4) FOR(j, i + 1, 4) FOR(k, j + 1, 4) if (triangle(A[i], A[j], A[k])) {
        printf("TRIANGLE\n");
        return 0;
    }
    FOR(i, 0, 4) FOR(j, i + 1, 4) FOR(k, j + 1, 4) if (segment(A[i], A[j], A[k])) {
        printf("SEGMENT\n");
        return 0;
    }
    printf("IMPOSSIBLE\n");
    return 0;
}