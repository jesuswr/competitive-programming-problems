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
#include <array>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int N;
ll V;
ll A[MAXN], B[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) rl(A[i]);
    FOR(i, 0, N) V += A[i];
    V /= N;

    ll ans1 = 0, ans2 = 0;
    {
        FOR(i, 0, N) B[i] = A[i];
        ll carry = 0;
        for (int i = 0; i < 2 * N; ++i) {
            int p = (i >= N ? i - N : i);
            ans1 += carry;
            if (B[p] > V) {
                carry += B[p] - V;
                B[p] = V;
            }
            else if (B[p] < V) {
                ll take = min(carry, V - B[p]);
                B[p] += take;
                carry -= take;
            }
        }
    }
    {
        FOR(i, 0, N) B[i] = A[i];
        ll carry = 0;
        for (int i = 2 * N - 1; i >= 0; --i) {
            int p = (i >= N ? i - N : i);
            ans2 += carry;
            if (B[p] > V) {
                carry += B[p] - V;
                B[p] = V;
            }
            else if (B[p] < V) {
                ll take = min(carry, V - B[p]);
                B[p] += take;
                carry -= take;
            }
        }
    }
    printf("%lld\n", min(ans1, ans2));
    return 0;
}