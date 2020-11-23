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
int n, m;
int a[MAXN], b[MAXN];
int need[MAXN];

void compress() {
    sort(b, b + n);
    map<int, int> new_a;
    FOR(i, 0, n) {
        new_a[b[i]] = i;
    }
    FOR(i, 0, n) {
        need[new_a[a[i]]] = a[i];
        a[i] = new_a[a[i]];
    }
}

int sqrtn = 316;
struct QUERIES {
    int l, r, i;
};
bool comp(const QUERIES &aa, const QUERIES &bb) {
    if (aa.l / sqrtn != bb.l / sqrtn)
        return aa.l < bb.l;
    return aa.r < bb.r;
}

QUERIES qs[MAXN];

int l, r;
int ans;
int freq[MAXN];
int ANS[MAXN];

void add(int p) {
    if (freq[a[p]] == need[a[p]])
        ans--;
    freq[a[p]]++;
    if (freq[a[p]] == need[a[p]])
        ans++;
}
void rem(int p) {
    if (freq[a[p]] == need[a[p]])
        ans--;
    freq[a[p]]--;
    if (freq[a[p]] == need[a[p]])
        ans++;
}

int main() {
    rii(n, m);
    FOR(i, 0, n) {
        ri(a[i]);
        b[i] = a[i];
    }
    compress();
    FOR(i, 0, m) {
        rii(qs[i].l, qs[i].r);
        qs[i].l--, qs[i].r--;
        qs[i].i = i;
    }
    sort(qs, qs + m, comp);
    add(0);
    FOR(i, 0, m) {
        while (l < qs[i].l) {
            rem(l);
            l++;
        }
        while (l > qs[i].l) {
            l--;
            add(l);
        }
        while (r < qs[i].r) {
            r++;
            add(r);
        }
        while (r > qs[i].r) {
            rem(r);
            r--;
        }
        ANS[qs[i].i] = ans;
    }
    FOR(i, 0, m) {
        printf("%d\n", ANS[i]);
    }
    return 0;
}