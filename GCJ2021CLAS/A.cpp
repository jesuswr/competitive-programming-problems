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
const int MAXN = 110; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];
void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    int cst = 0;
    FOR(i, 0, N - 1) {
        int mn_j = i;
        FOR(j, i, N) if (A[j] < A[mn_j]) mn_j = j;
        cst += mn_j - i + 1;
        int aux_i = i;
        while (aux_i < mn_j) {
            swap(A[aux_i], A[mn_j]);
            mn_j--, aux_i++;
        }
    }
    printf("%d\n", cst);
}


int main() {
    int t; ri(t);
    FOR(i, 0, t) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}