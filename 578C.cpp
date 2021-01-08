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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int N;
double A[MAXN];
double B[MAXN];

double f(double x) {
    FOR(i, 0, N) B[i] = A[i] - x;
    double ans = 0;
    double sm = 0;
    FOR(i, 0, N) {
        sm += B[i];
        ans = max(ans, sm);
        sm = max(sm, (double)0.0);
    }
    FOR(i, 0, N) B[i] = -B[i];
    sm = 0;
    FOR(i, 0, N) {
        sm += B[i];
        ans = max(ans, sm);
        sm = max(sm, (double)0.0);
    }
    return ans;
}


int main() {
    ri(N);
    FOR(i, 0, N) dadsadasda = scanf("%lF", A + i);
    double lo = -2e4, hi = 2e4, a , b;
    FOR(_, 0, 100) {
        a = lo + (hi - lo) / 3;
        b = lo + 2 * (hi - lo) / 3;
        if (f(a) < f(b)) hi = b;
        else lo = a;
    }
    printf("%lF\n", f(lo));
    return 0;
}