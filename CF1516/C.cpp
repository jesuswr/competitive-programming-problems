#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>
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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int N;
pii A[110];

int DP[110][2 * MAXN];
int f(int p, int sm) {
    if (p == N) return sm == 0;
    if (DP[p][sm + MAXN] != -1) return DP[p][sm + MAXN];
    int ret = 0;
    if (f(p + 1, sm + A[p].F) == 1)
        ret = 1;
    else if (f(p + 1, sm - A[p].F) == 1)
        ret = 1;
    return DP[p][sm + MAXN] = ret;
}

int main() {
    std::srand ( unsigned ( std::time(0) ) );
    memset(DP, -1, sizeof(DP));
    ri(N);
    FOR(i, 0, N) ri(A[i].F), A[i].S = i;

    if (f(0, 0) == 0) {
        printf("0\n");
    }
    else {
        random_shuffle(A, A + N);
        FOR(i, 0, N) {
            int tmp = A[i].F;
            A[i].F = 0;
            memset(DP, -1, sizeof(DP));
            if (f(0, 0) == 0) {
                printf("%d\n%d\n", 1, A[i].S + 1);
                exit(0);
            }
            A[i].F = tmp;
        }
    }

    return 0;
}