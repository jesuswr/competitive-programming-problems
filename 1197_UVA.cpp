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
const int MAXN = 769; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int K;
ll M[MAXN][MAXN];


void solve() {
    vector<ll> bst(K);
    FOR(i, 0, K) rl(bst[i]);
    sort(ALL(bst));
    FOR(_, 1, K) {
        vi curr(K);
        FOR(i, 0, K) ri(curr[i]);
        curr.pb(1e9);
        sort(ALL(curr));
        priority_queue< pair< ll, int > > pq;
        FOR(i, 0, K) pq.push({ -(bst[i] + curr[0]) , 0});
        FOR(i, 0, K) {
            auto [sm, ind] = pq.top();
            pq.pop();
            sm = -sm;
            bst[i] = sm;
            pq.push({ -(sm - curr[ind] + curr[ind + 1]), ind + 1});
        }
    }
    FOR(i, 0, K) printf("%lld%c", bst[i], (i + 1 == K ? '\n' : ' '));
}



int main() {
    while (scanf("%d", &K) != EOF) {
        solve();
    }
    return 0;
}