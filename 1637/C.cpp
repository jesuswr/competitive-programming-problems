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
#include <random>
#include <chrono>

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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[MAXN];


void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    int odd = 0, even = 0, greater_than_2 = 0;
    ll tot_sum = 0;
    FOR(i, 1, N - 1) {
        if (A[i] & 1) odd++;
        else even++;
        if (A[i] > 2) greater_than_2++;
        tot_sum += A[i];
    }

    if (even > 0) 
        printf("%lld\n", odd + (tot_sum - odd) / 2);
    else if (odd > 1 && greater_than_2 > 0) 
        printf("%lld\n", odd + (tot_sum - (odd - 1)) / 2);
    else
        printf("-1\n");
}


int main() {
    int t = 1;
    ri(t);
    while (t--) solve();
    return 0;
}