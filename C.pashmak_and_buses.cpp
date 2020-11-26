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
ll n, d, k;
int m[1010][1010];

int main() {
    rll(n, k), rl(d);
    ll aux = 1;
    FOR(i, 0, d) {
        aux = min(aux * k, (ll)1e5);
    }
    if (aux < n) {
        printf("-1\n");
        return 0;
    }
    FOR(i, 1, n) {
        FOR(j, 0, d) {
            m[i][j] = m[i - 1][j];
        }
        for (int j = d - 1; j >= 0; j--) {
            m[i][j] = (m[i][j] + 1) % k;
            if (m[i][j])
                break;
        }
    }
    FOR(i, 0, d) {
        FOR(j, 0, n) {
            printf("%d ", m[j][i] + 1);
        }
        printf("\n");
    }
    return 0;
}