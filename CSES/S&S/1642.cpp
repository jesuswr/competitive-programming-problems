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
const int MAXN = 1e5; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, X;
pii A[1000];

map<int, pii> get_sms(int l, int r) {
    map<int, pii> ret;
    FOR(i, l, r) FOR(j, i + 1, r) {
        ret[A[i].F + A[j].F] = {A[i].S, A[j].S};
    }
    return ret;
}

int main() {
    rii(N, X);
    FOR(i, 0, N) ri(A[i].F), A[i].S = i + 1;
    FOR(_, 0, 10) {
        FOR(i, 0, N) swap(A[i], A[rng() % N]);
        map<int, pii> lft = get_sms(0, N / 2), rgt = get_sms(N / 2, N);
        for (auto [sml, il] : lft) {
            if (rgt.find(X - sml) != rgt.end()) {
                printf("%d %d %d %d\n", il.F, il.S, rgt[X - sml].F, rgt[X - sml].S);
                return 0;
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}