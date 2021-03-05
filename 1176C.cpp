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
const int MAXN = 5e5; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];
int CNT[6];

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) {
        if (A[i] == 4)
            ++CNT[0];
        else if (A[i] == 8) {
            if (CNT[0] > CNT[1]) ++CNT[1];
        }
        else if (A[i] == 15) {
            if (CNT[1] > CNT[2]) ++CNT[2];
        }
        else if (A[i] == 16) {
            if (CNT[2] > CNT[3]) ++CNT[3];
        }
        else if (A[i] == 23) {
            if (CNT[3] > CNT[4]) ++CNT[4];
        }
        else if (A[i] == 42) {
            if (CNT[4] > CNT[5]) ++CNT[5];
        }
    }
    printf("%d\n", N - 6 * CNT[5]);
    return 0;
}