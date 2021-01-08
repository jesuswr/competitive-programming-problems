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
const int MAX_B = 22;
const int MAXN = 1 << MAX_B; // CAMBIAR ESTE
const int MASK = MAXN - 1;

// GJNM
int N;
int HAVE[MAXN];
int A[MAXN];

void to_b(int a) {
    vi b;
    FOR(i, 0, MAX_B) {
        b.pb(a & 1);
        a >>= 1;
    }
    reverse(ALL(b));
    for (auto x : b) printf("%d", x);
    printf("\n");
}

int main() {
    ri(N);
    FOR(i, 0, N) {
        ri(A[i]);
        HAVE[A[i]] = i + 1;
    }
    FOR(i, 0, MAXN) FOR(j, 0, MAX_B) if ( (i | (1 << j)) < MAXN) {
        HAVE[i | (1 << j)] = max(HAVE[i | (1 << j)], HAVE[i]);
    }
    FOR(i, 0, N) {
        int aux = ~A[i] & MASK;
        if (HAVE[aux] == 0) printf("-1 ");
        else printf("%d ", A[HAVE[aux] - 1]);
    }
    printf("\n");
    return 0;
}