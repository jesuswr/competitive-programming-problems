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
const int MAXN = 4e6; // CAMBIAR ESTE

// GJNM
ll N, X;
pair<ll, ll> A[MAXN];

void solve() {
    rll(N, X);
    FOR(i, 0, N) {
        rl(A[i].F);
        A[i].S = 1;
    }
    ll sum = 0;
    int i = 0;
    while (i < N) {
        if (A[i].F % X == 0) {
            A[N].F = A[i].F / X;
            A[N].S = X * A[i].S;
            N++;
        }
        else break;
        i++;
    }
    FOR(j, 0, N) sum += A[j].F * A[j].S;
    printf("%lld\n", sum);
}

int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}