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
const int MAXN = 1e3 + 19; // CAMBIAR ESTE
const int MAXK = 1e6 + 10;

// GJNM
int N, M, K; ll P;
int MAT[MAXN][MAXN];
ll SR[MAXN], SC[MAXN];
priority_queue<ll> PQR, PQC;
ll TR, TC;
ll A[MAXK], B[MAXK];

int main() {
    riii(N, M, K); rl(P);
    FOR(i, 0, N) FOR(j, 0, M) ri(MAT[i][j]);
    FOR(i, 0, N) FOR(j, 0, M) {
        SR[i] += MAT[i][j];
        SC[j] += MAT[i][j];
    }
    FOR(i, 0, N) PQR.push(SR[i]);
    FOR(j, 0, M) PQC.push(SC[j]);

    FOR(i, 1, K + 1) {
        A[i] += A[i - 1];
        B[i] += B[i - 1];

        ll aux = PQR.top(); PQR.pop();
        A[i] += aux;
        PQR.push(aux - M * P);

        aux = PQC.top(); PQC.pop();
        B[i] += aux;
        PQC.push(aux - N * P);
    }
    ll ans = -LLINF;
    FOR(i, 0, K + 1) ans = max(ans, A[i] + B[K - i] - P * i * (K - i));
    printf("%lld\n", ans);
    return 0;
}