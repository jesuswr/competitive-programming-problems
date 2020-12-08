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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
vector<ll> nums;

void precalc(int pos = 0, int cnt = 0, long long cur = 0){
    if (pos == 18){
        nums.pb(cur);
        return;
    }
    
    precalc(pos + 1, cnt, cur * 10);
    
    if (cnt < 3)
        for (int i = 1; i <= 9; ++i)
            precalc(pos + 1, cnt + 1, cur * 10 + i);
}



void solve() {
    ll l, r; rll(l, r);
    printf("%ld\n", ub(ALL(nums), r) - lb(ALL(nums), l));
}


int main() {
    precalc();
    nums.pb(1000000000000000000);
    sort(ALL(nums));
    int t; ri(t);
    while (t--)
        solve();

    return 0;
}