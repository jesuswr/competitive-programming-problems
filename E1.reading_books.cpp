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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e12;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n, k;
priority_queue<ll> good_a, good_b, good_a_b; // 1 le gusta a A, 2 le gusta a B, 3 le gusta a A y B

bool sz() {
    return good_a_b.size() && good_a.size() && good_b.size();
}


void pop() {
    if (good_a.size())
        good_a.pop();
    if (good_b.size())
        good_b.pop();
    if (good_a_b.size())
        good_a_b.pop();
}

int main() {
    rii(n, k);
    FOR(i, 0, n) {
        int t, a, b;
        riii(t, a, b);
        if (a & b)
            good_a_b.push(t);
        else if (a)
            good_a.push(-t);
        else if (b)
            good_b.push(-t);
    }

    if (good_a_b.size() + min(good_b.size(), good_a.size()) < k) {
        printf("-1\n");
        return 0;
    }

    while (good_a_b.size() > k)
        good_a_b.pop();
    while (good_a_b.size() < k)
        good_a_b.push(LLINF);

    ll ans = 0;
    while (sz() && (-(good_a.top() + good_b.top()) < good_a_b.top())) {
        ans += -(good_a.top() + good_b.top());
        pop();
    }

    while (good_a_b.size()) {
        ans += good_a_b.top();
        pop();
    }
    printf("%lld\n", ans);

    return 0;
}