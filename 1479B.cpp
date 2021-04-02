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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];
int LST[MAXN], NXT[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i + 1]);
    FOR(i, 0, N + 5) LST[i] = INF;
    NXT[0] = INF + 1;
    for (int i = N; i >= 1; --i) {
        NXT[i] = LST[A[i]];
        LST[A[i]] = i;
    }
    int x = 0, y = 0;
    int cnt = 0;
    FOR(z, 1, N + 1) {
        if (A[x] == A[z]) x = z;
        else if (A[y] == A[z]) y = z;
        else if (NXT[x] < NXT[y]) {
            y = z;
            ++cnt;
        }
        else {
            x = z;
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}