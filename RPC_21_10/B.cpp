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
const int MAXN = 2e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int D, K;

struct super_queue {
    queue<int> q;
    ll sm;
    super_queue() {
        sm = 0;
    }
    void add(int x) {
        q.push(x);
        sm += x;
    }
    void pop() {
        sm -= q.front();
        q.pop();
    }
    int size() {
        return SZ(q);
    }
};

void solve() {
    int carry = 0;
    vi a;
    FOR(i, 0, K) {
        int act = D * D + carry;
        a.pb(act % 10);
        carry = act / 10;
    }
    while (carry > 0) {
        a.pb(carry %= 10);
        carry /= 10;
    }
    FOR(i, 0, 3 * K) a.pb(0);

    ll ans = 0;
    ll carry2 = 0;
    super_queue q;
    for (auto d : a) {
        if (q.size() >= K)
            q.pop();
        q.add(d);
        ll aux = q.sm + carry2;
        ans += aux % 10;
        carry2 = aux / 10;
    }
    printf("%lld\n", ans);
}


int main() {
    while (rii(D, K), D != 0 || K != 0) {
        solve();
    }
    return 0;
}