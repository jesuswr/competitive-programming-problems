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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K, MN;
int A[MAXN];
ll B[MAXN];


bool valid(ll p) {
    FOR(i, 0, N) B[i] = A[i];
    deque<int> q;
    ll sm = 0;
    FOR(i, 0, K) {
        q.push_back(i);
        sm += B[i];
    }
    ll cnt = 0;
    FOR(i, K - 1, N) {
        while (sm >= 0) {
            if (q.empty())
                return false;
            int r = q.back();
            ll mv = min(abs(B[r] - MN), sm + 1);
            if (mv == 0)
                q.pop_back();
            else {
                sm -= mv;
                B[r] -= mv;
                cnt += mv;
            }
        }

        if (i == N - 1)
            break;
        if (!q.empty()) {
            q.pop_front();
            sm -= B[i - (K - 1)];
        }
        q.push_back(i + 1);
        sm += B[i + 1];
    }

    return cnt <= p;
}



int main() {
    rii(N, K);
    FOR(i, 0, N) ri(A[i]);
    MN = A[0];
    FOR(i, 1, N) MN = min(MN, A[i]);


    ll lo = 0, hi = 1e12;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        if (valid(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    valid(hi);
    printf("%lld\n", hi);
    FOR(i, 0, N) printf("%lld ", B[i]);
    printf("\n");
    return 0;
}