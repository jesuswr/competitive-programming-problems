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
const int MAXN = 1e6 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
char A[MAXN];
char S[MAXN];
vi INDS;


bool valid(int K) {
    FOR(i, 0, N) A[i] = S[i];
    for (int i : INDS) {
        int k_l = K;
        for (int l = i - 1; l >= 0 && A[l] == '0' && k_l > 0; --l) {
            A[l] = '1';
            k_l--;
        }
        int k_r = (k_l == 0 ? K - 1 : K);
        for (int r = i + 1; r < N && A[r] == '0' && k_r > 0; ++r) {
            A[r] = '1';
            k_r--;
        }
    }
    FOR(i, 0, N) if (A[i] == '0') return false;
    return true;
}

void solve() {
    ri(N);
    dadsadasda = scanf("%s", S);
    INDS.clear();
    FOR(i, 0, N) if (S[i] == '1') INDS.pb(i);
    int lo = 0, hi = N;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (valid(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    printf("%d\n", hi);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}