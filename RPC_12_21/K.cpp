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
const int MAXA = 1e6 + 10;
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int A, M;
int P2[MAXA];

void pre() {
    P2[0] = 1;
    FOR(i, 1, MAXA) {
        P2[i] = P2[i - 1] + P2[i - 1];
        if (P2[i] >= MOD)
            P2[i] -= MOD;
    }
}


int get_h(int x) {
    int ret = 0;
    while (x > 0) {
        ret++;
        x >>= 1;
    }
    return ret;
}

map<int, int> D;



int main() {
    pre();
    rii(A, M);

    while (M--) {
        int v; ri(v);
        int lev = get_h(v);

        int del = (P2[A - lev] - D[v] + MOD);
        if (del >= MOD)
            del -= MOD;
        while (v >= 0) {
            D[v] = (D[v] + del);
            if (D[v] >= MOD)
                D[v] -= MOD;
            if (lev == 0)
                break;
            v -= P2[lev - 1];
            lev = get_h(v);
        }

        printf("%d\n", del);
    }



    return 0;
}