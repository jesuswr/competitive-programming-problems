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
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
string S;

void solve() {
    ri(N);
    cin >> S;

    int sm = 0;
    int lst = N, lst_sm = 0;

    for (int i = N - 1; i >= 0; --i) {
        if (S[i] == 'F')
            sm = (sm + lst_sm) % MOD;
        else if (lst == N)
            lst = i;
        else if (S[i] != S[lst]) {
            lst_sm = (lst_sm + (N - lst)) % MOD;
            sm = (sm + lst_sm) % MOD;
            lst = i;
        }
        else {
            sm = (sm + lst_sm) % MOD;
            lst = i;
        }
    }
    printf("%d\n", sm);
}

int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}