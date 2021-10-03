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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll N;

ll DP[69][69][2];
ll f(int b, int cnt_on, int eq) {
    if (b == -1)
        return (1ll << cnt_on);
    ll &ret = DP[b][cnt_on][eq];
    if (ret != -1)
        return ret;

    ret = 0;
    bool is_b_on = (N >> b) & 1;
    if (eq) {
        if (is_b_on) {
            ret += f(b - 1, cnt_on + 1, eq);
            ret += f(b - 1, cnt_on, 0);
        }
        else {
            ret += f(b - 1, cnt_on, 1);
        }
    }
    else {
        ret += f(b - 1, cnt_on + 1, 0);
        ret += f(b - 1, cnt_on, 0);
    }
    return ret;
}

int main() {
    memset(DP, -1, sizeof(DP));
    rl(N); --N;
    printf("%lld\n", f(40, 0, 1));
    return 0;
}