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

int adasda;

#define  ri(a) adasda = scanf("%d", &a)
#define  rii(a,b) adasda = scanf("%d %d", &a, &b)
#define  riii(a,b,c) adasda = scanf("%d %d %d", &a, &b, &c)
#define  rl(a) adasda = scanf("%lld", &a)
#define  rll(a,b) adasda = scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 4e5 + 10; // CAMBIAR ESTE

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


bool valid(int mx, int rest, int segments) {
    int x = mx / segments;
    int a = mx % segments;
    int b = segments - a;

    return rest >= a * x + b * max(0, x - 1);
}
int ANS[MAXN];
void solve(int i) {
    int mx_oc = qans[qs[i].i];
    int rest = qs[i].r - qs[i].l + 1 - mx_oc;

    int lo = 1, hi = MAXN;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;

        if (valid(mx_oc, rest, mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    ANS[qs[i].i] = lo;
}


int main() {
    rii(n, q);
    sqrtn = sqrt(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    FOR(i, 0, q) {
        rii(qs[i].l, qs[i].r);
        --qs[i].l;
        --qs[i].r;
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

    FOR(i, 0, q) solve(i);
    FOR(i, 0, q) cout << ANS[i] << endl;
    return 0;
}