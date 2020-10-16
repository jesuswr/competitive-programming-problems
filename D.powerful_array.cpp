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
const ll LLINF = 1e18;
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
const int sqrtn = 450;
struct query {
    int l, r, i;
};
bool comp(const query &a, const query &b) {
    if (a.l / sqrtn != b.l / sqrtn)
        return a.l < b.l;
    return a.r < b.r;
}


int n, q;
ll a[MAXN];

ll ans;
ll cnt[(int)1e6 + 10];
query qs[MAXN];
ll q_ans[MAXN];

void rm(int p) {
    ans -= cnt[p] * cnt[p] * p;
    cnt[p]--;
    ans += cnt[p] * cnt[p] * p;
}
void add(int p) {
    ans -= cnt[p] * cnt[p] * p;
    cnt[p]++;
    ans += cnt[p] * cnt[p] * p;
}

int main() {
    rii(n, q);
    FOR(i, 0, n) {
        rl(a[i + 1]);
    }
    FOR(i, 0, q) {
        rii(qs[i].l, qs[i].r);
        qs[i].i = i;
    }
    sort(qs, qs + q, comp);

    int left = 0, right = 0;
    FOR(i, 0, q) {
        while (left < qs[i].l) {
            rm(a[left]);
            left++;
        }
        while (left > qs[i].l) {
            left--;
            add(a[left]);
        }

        while (right < qs[i].r) {
            right++;
            add(a[right]);
        }
        while (right > qs[i].r) {
            rm(a[right]);
            right--;
        }
        q_ans[qs[i].i] = ans;
    }
    FOR(i, 0, q) {
        printf("%lld\n", q_ans[i]);
    }
    return 0;
}