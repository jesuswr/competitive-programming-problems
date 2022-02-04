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
int N;
string S, T;

int go(vector<vi> cnt) {
    // FOR(i, 0, 2) FOR(j, 0, 2) printf("%d %d : %d\n", i, j, cnt[i][j]);
    if (cnt[0][1] == cnt[1][0]) {
        // printf("%d\n", 2 * cnt[0][1]);
        return 2 * cnt[0][1];
    }
    // printf("ALO %d\n", INF);
    return INF;
}

void solve() {
    ri(N);
    cin >> S >> T;
    vector<vi> CNT(2, vi(2, 0));
    FOR(i, 0, N) CNT[S[i] - '0'][T[i] - '0']++;
    int ans = go(CNT);
    if (CNT[1][1]) {
        vector<vi> cnt(2, vi(2, 0));
        --CNT[1][1];
        FOR(i, 0, 2) FOR(j, 0, 2) cnt[i][j] = CNT[1 ^ i][j];
        ++cnt[1][1];
        ++CNT[1][1];
        ans = min(ans, 1 + go(cnt));
    }
    if (CNT[1][0]) {
        vector<vi> cnt(2, vi(2, 0));
        --CNT[1][0];
        FOR(i, 0, 2) FOR(j, 0, 2) cnt[i][j] = CNT[1 ^ i][j];
        ++cnt[1][0];
        ++CNT[1][0];
        ans = min(ans, 1 + go(cnt));
    }
    if (ans >= INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}