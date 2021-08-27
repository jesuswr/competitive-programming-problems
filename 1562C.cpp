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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
string A;

void solve() {
    ri(N);
    cin >> A;
    int cnt[2] = {0, 0};
    int lst_zero = -1;
    FOR(i, 0, N) {
        if (A[i] == '0')
            lst_zero = i + 1;
        cnt[A[i] - '0']++;
    }

    if (cnt[0] == N) {
        printf("%d %d %d %d\n", 1, N, 1, N - 1);
    }
    else if (cnt[1] == N) {
        printf("%d %d %d %d\n", 1, (N / 2) * 2, 1, N / 2);
    }
    else if (lst_zero - 1 < abs(N - lst_zero)) {
        printf("%d %d %d %d\n", lst_zero, N, lst_zero + 1, N);
    }
    else {
        printf("%d %d %d %d\n", 1, lst_zero, 1, lst_zero - 1);
    }
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}