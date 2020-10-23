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
int n, q;
int sqrtn;
int a[MAXN];

struct query {
    int l, r, i;
};

bool comp(query &a, query &b) {
    if (a.l / sqrtn != b.l / sqrtn)
        return a.l < b.l;
    return a.r < b.r;
}

query qs[MAXN];

int freq[MAXN], cnt[MAXN];
int ans;
int qans[MAXN];

void add(int x) {
    freq[cnt[x]]--;
    cnt[x]++;
    freq[cnt[x]]++;
    if (cnt[x] > ans)
        ans = cnt[x];
}

void rem(int x) {
    freq[cnt[x]]--;
    cnt[x]--;
    freq[cnt[x]]++;
    if (freq[ans] == 0)
        ans = ans - 1;
}

int main() {
    rii(n, q);
    sqrtn = sqrt(n);
    FOR(i, 0, n) {
        ri(a[i]);
        a[i] += 100000;
    }
    FOR(i, 0, q) {
        rii(qs[i].l, qs[i].r);
        qs[i].l--, qs[i].r--;
        qs[i].i = i;
    }
    sort(qs, qs + q, comp);

    int l = 0, r = 0;
    ans = 1;
    freq[1] = 1;
    cnt[a[0]] = 1;

    FOR(i, 0, q) {
        while (l > qs[i].l) { // move l left
            l--;
            add(a[l]);
        }
        while (r < qs[i].r) { // move r right
            r++;
            add(a[r]);
        }

        while (l < qs[i].l) { // move l right
            rem(a[l]);
            l++;
        }
        while (r > qs[i].r) { // move r left
            rem(a[r]);
            r--;
        }
        qans[qs[i].i] = ans;
    }

    FOR(i, 0, q) {
        printf("%d\n", qans[i]);
    }

    return 0;
}