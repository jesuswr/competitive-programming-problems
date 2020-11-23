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
const int MAXN = 4e6; // CAMBIAR ESTE

// GJNM
ll N, A, B, L, OFFSET;
long double En[MAXN];
long double En_pre[MAXN];
long double query(int a, int b) {
    return En_pre[b] - En_pre[a - 1];
}

int main() {
    rl(N), rll(A, B);
    L = B - A + 1;
    OFFSET = 2 * B;

    FOR(i, 1, N + 1) {
        if (A == 0) {
            En[OFFSET + i] = (1.0 / (long double)L) * query(OFFSET + i - B, OFFSET + i - A - 1);
            En[OFFSET + i] += 1;
            En[OFFSET + i] *= ((long double)B + 1) / B;
        }
        else {
            En[OFFSET + i] = (1.0 / (long double)L) * query(OFFSET + i - B, OFFSET + i - A);
            En[OFFSET + i] += 1;
        }
        En_pre[OFFSET + i] = En_pre[OFFSET + i - 1] + En[OFFSET + i];
    }
    printf("%Lf\n", En[OFFSET + N]);
    return 0;
}