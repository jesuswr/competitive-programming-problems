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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1 << 18; // CAMBIAR ESTE

// GJNM
int b, m;

// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
    int val;
    void merge(STN& L, STN& R, int type) {
        if (type == 1)
            val = L.val | R.val;
        else
            val = L.val ^ R.val;
    }
    void operator=(int a) {
        val = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N, int h = b) {
    if (r - l < 2) {
        ST[id] = A[l];
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m, h - 1); STB(R, m, r, h - 1);
    ST[id].merge(ST[L], ST[R], h & 1);
}
void STU(int p, int x, int id = 1, int l = 0, int r = N, int h = b) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m, h - 1);
    else STU(p, x, R, m, r, h - 1);
    ST[id].merge(ST[L], ST[R], h & 1);
}


int main() {
    rii(b, m);
    N = (1 << b);
    FOR(i, 0, N) {
        ri(A[i]);
    }
    STB();
    FOR(i, 0, m) {
        int p, v; rii(p, v); p--;
        STU(p, v);
        printf("%d\n", ST[1].val);
    }

    return 0;
}