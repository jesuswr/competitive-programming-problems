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
struct Hash {
    int P = 1777771, MOD[2], PI[2];
    vector<int> h[2], pi[2];
    Hash(string& s) {
        MOD[0] = 999727999; 
        PI[0] = 325255434; // inversa de P en MOD0 y MOD1
        FOR(k, 0, 1)h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
        FOR(k, 0, 1) {
            h[k][0] = 0; pi[k][0] = 1;
            ll p = 1;
            FOR(i, 1, SZ(s) + 1) {
                h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
                pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
                p = (p * P) % MOD[k];
            }
        }
    }
    int get(int s, int e) { // [s,e)
        int h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
        h0 = (1LL * h0 * pi[0][s]) % MOD[0];
        return h0;
    }
};


int main() {
    string txt;
    cin >> txt;
    int n = SZ(txt);
    Hash h(txt);
    for (int len = 1; len <= n; ++len) {
        bool good = true;
        for (int l = 0; l < n; l += len) {
            int r = min(l + len, n);
            if (h.get(l, r) != h.get(0, r - l)) {
                good = false;
                break;
            }
        }
        if (good)
            printf("%d ", len);
    }
    return 0;
}