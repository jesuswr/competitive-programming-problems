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
const int MAXN = 4e5; // CAMBIAR ESTE
const int MAXA = 1e6 + 10;

// GJNM
int N;
ll A[MAXN];
bool NOT_P[MAXA];
vector<ll> PRIMES;


void pre() {
    FOR(i, 2, MAXA) {
        if (NOT_P[i]) continue;
        PRIMES.pb(i);
        int j = i + i;
        while (j < MAXA) {
            NOT_P[j] = true;
            j += i;
        }
    }
}


void solve() {
    ri(N);
    FOR(i, 0, N) rl(A[i]);
    FOR(i, 0, N) {
        ll aux = 1;
        for (auto p : PRIMES) {
            if (p * p > A[i]) break;
            if (A[i] % p == 0) {
                int cnt = 0;
                while (A[i] % p == 0) {
                    cnt++;
                    A[i] = A[i] / p;
                }
                if (cnt & 1) aux *= p;
            }
        }
        aux *= A[i];
        A[i] = aux;
    }

    map<int, int> cnt;
    FOR(i, 0, N) cnt[A[i]]++;

    int w0 = 0;
    for (auto p : cnt) w0 = max(w0, p.S);

    FOR(i, 0, N) if (cnt[A[i]] % 2 == 0) A[i] = 1;
    cnt.clear();
    FOR(i, 0, N) cnt[A[i]]++;
    int w1 = 0;
    for (auto p : cnt) w1 = max(w1, p.S);

    int q; ri(q);
    while (q--) {
        ll w; rl(w);
        if (w == 0) printf("%d\n", w0);
        else printf("%d\n", w1);
    }
}


int main() {
    pre();
    int t; ri(t);
    while (t--) solve();
    return 0;
}