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
ll N, K, X;
ll A[MAXN];

int main() {
    rll(N, K), rl(X);
    FOR(i, 0, N) rl(A[i]);
    sort(A, A + N);
    priority_queue<ll> pq;

    FOR(i, 1, N) {
        if (A[i] - A[i - 1] > X)
            pq.push(-(A[i] - A[i - 1]));
    }

    int ans = pq.size() + 1;

    while (K > 0 && !pq.empty()) {
        ll d = -pq.top(); pq.pop();
        ll a = (d - 1) / X;
        if (K >= a) {
            K -= a;
            --ans;
        }
    }
    printf("%d\n", ans);

    return 0;
}