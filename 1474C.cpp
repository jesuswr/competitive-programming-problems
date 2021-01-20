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
const int MAXN = 2010; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];
stack<pii> ans;

void prnt() {
    while (!ans.empty()) printf("%d %d\n", ans.top().F, ans.top().S), ans.pop();
}

bool f(multiset<int> &ms, int x) {
    if (ms.size() == 0) return true;
    int a = *ms.rbegin();
    ms.erase(ms.find(a));

    int b = x - a;
    if (ms.find(b) == ms.end()) {
        ms.insert(a);
        return false;
    }
    ms.erase(ms.find(b));
    if (f(ms, a)) {
        ans.push({a, b});
        return true;
    }
    ms.insert(a);
    ms.insert(b);
    return false;
}


void solve() {
    ri(N);
    FOR(i, 0, 2 * N) ri(A[i]);
    sort(A, A + 2 * N);
    multiset<int> ms;
    FOR(i, 0, 2 * N) ms.insert(A[i]);
    FOR(i, 0, 2 * N - 1) {
        if (f(ms, A[i] + A[2 * N - 1])) {
            printf("YES\n");
            printf("%d\n", A[i] + A[2 * N - 1]);
            prnt();
            return;
        }
    }
    printf("NO\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}