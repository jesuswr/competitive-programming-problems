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
const int MAXN = 3e5 + 1; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N; ll A[MAXN];

int main() {
    int k;
    rii(N, k);
    FOR(i, 0, N) rl(A[i]);
    ROF(i, N - 1, -1) A[i] += A[i + 1];
    priority_queue<ll> pq;
    if (k == 1) {
        printf("%lld\n", A[0]);
        return 0;
    }

    ll ans = A[0];
    FOR(i, 1, N) {
        if (SZ(pq) < k - 1) {
            pq.push(-A[i]);
            ans += A[i];
        }
        else {
            if (A[i] > -pq.top()) {
                ans += pq.top();
                pq.pop();
                pq.push(-A[i]);
                ans += A[i];
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}