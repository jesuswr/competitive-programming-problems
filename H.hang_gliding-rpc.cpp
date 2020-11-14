#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <iomanip>
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
const int MAXN = 1e4 + 10; // CAMBIAR ESTE

// GJNM
int t, p;
vector<tuple<int, int, int, int>> times;
int points[MAXN];
int nxt[MAXN];

long double dp[MAXN];
long double probs[MAXN];

long double f(int pos) {
    if (pos == t)
        return 0;
    if (dp[pos] >= -0.5)
        return dp[pos];
    int a, b, c, d;
    tie(a, b, c, d) = times[pos];
    dp[pos] = max(f(pos + 1), probs[d] * (long double) c + f(nxt[pos]));
    return dp[pos];
}


int main() {
    rii(t, p);
    FOR(i, 0, t) {
        int a, b, c; riii(a, b, c);
        times.pb({a, b, c, i});
    }
    sort(all(times));
    FOR(i, 0, t) {
        int a, b, c, d;
        tie(a, b, c, d) = times[i];
        tuple<int, int, int, int> aux = {b, -1, -1, -1};
        auto it = lower_bound(times.begin(), times.end(), aux);
        nxt[i] = it - times.begin();
    }
    FOR(i, 0, t) {
        int a, b, c, d;
        tie(a, b, c, d) = times[i];
    }

    priority_queue<pair<long double, int>> pq;
    FOR(_, 0, p) {
        FOR(i, 0, t) {
            scanf("%Lf", &probs[i]);
            dp[i] = -1;
        }
        long double val = f(0);
        pq.push({val, _ + 1});
    }
    FOR(i, 0, 3) {
        auto aux = pq.top();
        printf("%d %.2Lf\n", aux.S, aux.F + 0.001);
        pq.pop();
    }
    return 0;
}