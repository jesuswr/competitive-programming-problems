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
#include <chrono>

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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<int, int, custom_hash> index_of;
unordered_map<int, int, custom_hash> mx;
int n;
int a[MAXN];
int dp[MAXN];
int nxt[MAXN];

int main() {
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    a[n] = 1e9 + 10;
    mx.reserve(5*n); index_of.reserve(5*n);

    int ans = 0;
    int start;
    ROF(i, n - 1, -1) {
        if (a[i] == a[i + 1] - 1)
            dp[i] = 1 + dp[i + 1];
        else {
            dp[i] = 1 + mx[a[i] + 1];
            nxt[i] = index_of[a[i] + 1];
        }
        ans = max(ans, dp[i]);
        if (ans == dp[i])
            start = i;

        mx[a[i]] = max(mx[a[i]], dp[i]);
        if (mx[a[i]] == dp[i])
            index_of[a[i]] = i;
    }
    printf("%d\n", ans);
    FOR(i, 0, ans) {
        printf("%d ", start + 1);
        if (nxt[start] != 0)
            start = nxt[start];
        else
            start++;
    }
    printf("\n");




    return 0;
}