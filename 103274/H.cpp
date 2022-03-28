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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int B, N;
string S;

struct Hash {
    int P = 1777771, MOD[2], PI[2];
    vector<int> h[2], pi[2];
    Hash(string& s) {
        MOD[0] = 1000003601; MOD[1] = 1000004249;
        PI[0] = 737238778; PI[1] = 388825072; // inversa de P en MOD0 y MOD1
        FOR(k, 0, 2)h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
        FOR(k, 0, 2) {
            h[k][0] = 0; pi[k][0] = 1;
            ll p = 1;
            FOR(i, 1, s.size() + 1) {
                h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
                pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
                p = (p * P) % MOD[k];
            }
        }
    }
    ll get(int s, int e) { // [s,e)
        ll h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
        h0 = (1LL * h0 * pi[0][s]) % MOD[0];
        ll h1 = (h[1][e] - h[1][s] + MOD[1]) % MOD[1];
        h1 = (1LL * h1 * pi[1][s]) % MOD[1];
        return (h0 << 32) | h1;
    }
};


int main() {
    ri(B);
    cin >> S;
    N = SZ(S);
    Hash h(S);
    int ans = N;
    for (int b = 2; b <= min(B, N); ++b) {
        unordered_map<ll, int> lst;
        unordered_map<ll, int> cnt;
        lst.reserve(N - b + 1);
        cnt.reserve(N - b + 1);
        for (int l = 0; l <= N - b; ++l) {
            ll hsh = h.get(l, l + b);
            if (lst.find(hsh) == lst.end() || lst[hsh] <= l - b) {
                cnt[hsh]++;
                ans = min(ans, N - cnt[hsh] * (b - 1));
                lst[hsh] = l;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}