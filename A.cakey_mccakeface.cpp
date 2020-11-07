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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 2100; // CAMBIAR ESTE

// GJNM
int n, m;
ll in[MAXN], out[MAXN];
unordered_map<ll, int> cnt;

int main() {
    ri(n); ri(m);
    FOR(i, 0, n) {
        rl(in[i]);
    }
    FOR(i, 0, m) {
        rl(out[i]);
    }

    cnt.reserve(n * m);

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (out[j] >= in[i])
                cnt[out[j] - in[i]]++;
        }
    }

    ll ans = 0;
    int cnt_max = 0;
    for (auto p : cnt) {
        if (p.S == cnt_max) {
            ans = min(ans, p.F);
        }
        if (p.S > cnt_max) {
            ans = p.F;
            cnt_max = p.S;
        }
    }

    printf("%lld\n", ans);

    return 0;
}