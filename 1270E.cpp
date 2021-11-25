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
const int MAXN = 1e3 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
pii P[MAXN];
int CNT[2][2];

int get_cnt() {
    FOR(i, 0, 2) FOR(j, 0, 2) CNT[i][j] = 0;
    FOR(i, 0, N) ++CNT[P[i].F & 1][P[i].S & 1];
    int ret = 0;
    FOR(i, 0, 2) FOR(j, 0, 2) ret += (CNT[i][j] > 0);
    return ret;
}

void add(pii x) {
    FOR(i, 0, N) {
        P[i].F += x.F;
        P[i].S += x.S;
    }
}
void divide() {
    FOR(i, 0, N) {
        P[i].F >>= 1;
        P[i].S >>= 1;
    }
}

vi ANS;
void add(int x, int y) {
    FOR(i, 0, N) if (P[i].F % 2 == x && P[i].S % 2 == y)
        ANS.pb(i);
}


int main() {
    ri(N);
    FOR(i, 0, N) {
        rii(P[i].F, P[i].S);
        P[i].F += 1e6;
        P[i].S += 1e6;
    }
    while (get_cnt() == 1) {
        if (CNT[0][0]) divide();
        else if (CNT[0][1]) add({0, 1});
        else if (CNT[1][0]) add({1, 0});
        else add({1, 1});
    }

    if ( (CNT[0][0] + CNT[1][1]) > 0 && (CNT[1][0] + CNT[0][1]) > 0 ) {
        add(0, 0);
        add(1, 1);
    }
    else if (CNT[0][0] + CNT[1][1] > 0)
        add(0, 0);
    else
        add(1, 0);

    printf("%d\n", SZ(ANS));
    for (auto i : ANS) printf("%d ", i + 1);
    printf("\n");

    return 0;
}