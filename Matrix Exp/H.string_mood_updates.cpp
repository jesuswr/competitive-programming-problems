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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
const ll mod = 1000000007;

// GJNM
int mat_of[100];
int mats[5][2][2] = {{{0, 1}, {0, 1}}, {{1, 0}, {1, 0}}, {{0, 1}, {1, 0}}, {{1, 0}, {0, 1}}, {{19, 7}, {6, 20}}};

void precomp() {
    FOR(i, 'A', 'Z' + 1) {
        mat_of[i - '?'] = 3;
    }
    mat_of['S' - '?'] = mat_of['D' - '?'] = 0;
    mat_of['H' - '?'] = 1;
    mat_of['A' - '?'] = mat_of['E' - '?'] = mat_of['I' - '?'] = mat_of['O' - '?'] = mat_of['U' - '?'] = 2;
    mat_of['?' - '?'] = 4;
}

// Todos los rangos son semi-abiertos [a,b)
char A[MAXN];
int N;
struct STN {
    ll mat[2][2];
    void merge(STN& L, STN& R) {
        FOR(i, 0, 2) FOR(j, 0, 2) {
            mat[i][j] = 0;
        }

        FOR(k, 0, 2) FOR(i, 0, 2) FOR(j, 0, 2) {
            mat[i][j] += L.mat[i][k] * R.mat[k][j];
        }
        FOR(i, 0, 2) FOR(j, 0, 2) {
            mat[i][j] %= mod;
        }
    }
    void operator=(char a) {
        int aux = mat_of[a - '?'];
        FOR(i, 0, 2) {
            FOR(j, 0, 2) {
                mat[i][j] = mats[aux][i][j];
            }
        }
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = A[l];
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, char x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int main() {
    precomp();
    int q;
    rii(N, q);
    scanf("%s\n", A);
    STB();
    printf("%lld\n", ST[1].mat[0][0]);
    FOR(i, 0, q) {
        int pos;
        char c;
        scanf("%d %c", &pos, &c);
        STU(pos - 1, c);
        printf("%lld\n", ST[1].mat[0][0]);
    }
    return 0;
}