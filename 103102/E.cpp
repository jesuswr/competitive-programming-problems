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
const int MAXN = 5e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

ll COUNT[MAXN][3][3];
int main() {
    int n; ri(n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int a; ri(a);
        a %= 3;
        COUNT[i][a][(a * a) % 3] = 1;
        FOR(sm, 0, 3) FOR(smsq, 0, 3) {
            COUNT[i][(sm + a) % 3][(smsq + a * a) % 3] += COUNT[i - 1][sm][smsq];
        }
        FOR(sm, 0, 3) FOR(smsq, 0, 3) if ((sm * sm) % 3 == smsq) {
            ans += COUNT[i][sm][smsq];
        }
    }
    printf("%lld\n", ans);
    return 0;
}