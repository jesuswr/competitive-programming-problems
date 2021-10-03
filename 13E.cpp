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
const int MAXN = 2e5; // CAMBIAR ESTE
const int SQRT = 250;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
int A[MAXN];
int LST[MAXN], CNT[MAXN];

void upd(int j, int aj) {
    A[j] = aj;
    int blck = j / SQRT;
    int l = blck * SQRT, r = min((blck + 1) * SQRT, N);
    for (int i = r - 1; i >= l; --i) {
        int nxt = i + A[i];
        if (nxt < r) {
            LST[i] = LST[nxt];
            CNT[i] = CNT[nxt] + 1;
        }
        else {
            LST[i] = i;
            CNT[i] = 1;
        }
    }
}

void ans(int i) {
    int cnt = 0;
    while (69) {
        cnt += CNT[i];
        i = LST[i];
        if (i + A[i] >= N)
            break;
        i = i + A[i];
    }
    printf("%d %d\n", i + 1, cnt);
}

int main() {
    rii(N, M);
    FOR(i, 0, N) ri(A[i]);
    for (int i = N - 1; i >= 0; --i) {
        int blck = i / SQRT;
        int r = min((blck + 1) * SQRT, N);
        int nxt = i + A[i];
        if (nxt < r) {
            LST[i] = LST[nxt];
            CNT[i] = CNT[nxt] + 1;
        }
        else {
            LST[i] = i;
            CNT[i] = 1;
        }
    }
    while (M--) {
        int t; ri(t);
        if (t == 0) {
            int i, ai; rii(i, ai); --i;
            upd(i, ai);
        }
        else {
            int i; ri(i); --i;
            ans(i);
        }
    }

    return 0;
}