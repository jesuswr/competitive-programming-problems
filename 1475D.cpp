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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int N, M;
ll A[MAXN];

void solve() {
    rii(N, M);
    FOR(i, 0, N) rl(A[i]);
    vector<ll> pre1, pre2;
    ll tot = 0;
    FOR(i, 0, N) {
        int b; ri(b);
        if (b == 1) pre1.pb(A[i]);
        else pre2.pb(A[i]);
        tot += A[i];
    }
    pre1.pb(0);
    pre1.pb(0);
    pre1.pb(0);
    sort(ALL(pre1)); reverse(ALL(pre1));
    ll mn = LLINF;
    {
        priority_queue<ll> pq;
        ll need = M - pre1[0];
        for (int i = 2; i < SZ(pre1); i += 2) pq.push(pre1[i] + pre1[i - 1]);
        for (int i = 0; i < SZ(pre2); i += 1) pq.push(pre2[i]);
        int take = 0;
        while (need > 0 && !pq.empty()) {
            ++take;
            need -= pq.top();
            pq.pop();
        }
        if (need <= 0) mn = 2 * take + 1;
    }
    {
        priority_queue<ll> pq;
        ll need = M;
        for (int i = 1; i < SZ(pre1); i += 2) pq.push(pre1[i] + pre1[i - 1]);
        for (int i = 0; i < SZ(pre2); i += 1) pq.push(pre2[i]);
        int take = 0;
        while (need > 0 && !pq.empty()) {
            ++take;
            need -= pq.top();
            pq.pop();
        }
        if (need <= 0 && mn > 2 * take) mn = 2 * take;
    }
    if (mn == LLINF) printf("-1\n");
    else printf("%lld\n", mn);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}