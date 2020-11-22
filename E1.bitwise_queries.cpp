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
int query_and(int i, int j) {
    printf("AND %d %d\n", i, j); fflush(stdout);
    int aux; ri(aux);
    return aux;
}
int query_or(int i, int j) {
    printf("OR %d %d\n", i, j); fflush(stdout);
    int aux; ri(aux);
    return aux;
}
int query_xor(int i, int j) {
    printf("XOR %d %d\n", i, j); fflush(stdout);
    int aux; ri(aux);
    return aux;
}

int main() {
    int n;
    ri(n);
    int x12 = query_xor(1, 2);
    int a12 = query_and(1, 2);
    int x23 = query_xor(2, 3);
    int a23 = query_and(2, 3);
    int x13 = x12 ^ x23;
    int a13 = query_and(1, 3);
    int x = x12 + 2 * a12;
    int y = x23 + 2 * a23;
    int z = x13 + 2 * a13;

    vi ans(n);
    ans[0] = (x - y + z) / 2;
    ans[2] = z - ans[0];
    ans[1] = y - ans[2];
    FOR(i, 3, n) {
        int tmp = query_xor(1, i + 1);
        ans[i] = tmp ^ ans[0];
    }

    printf("! ");
    FOR(i, 0, n) {
        printf("%d ", ans[i]);
    } printf("\n");

    return 0;
}