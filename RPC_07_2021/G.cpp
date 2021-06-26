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
const int MAXN = 110; // CAMBIAR ESTE

// GJNM
int N, M;
int ORD[MAXN];

int find_i(int x) {
    FOR(i, 0, N) if (ORD[i] == x) return i;
}

int main() {
    rii(N, M);
    FOR(i, 0, N) ORD[i] = i + 1;
    dadsadasda = scanf("%*c");
    FOR(_, 0, M) {
        int a, b; // a le gana a b
        dadsadasda = scanf("T%d T%d\n", &a, &b);
        int ai = find_i(a);
        int bi = find_i(b);
        //printf("%d : %d \n", a, ai);
        //printf("%d : %d \n\n", b, bi);

        if (ai > bi) {
            FOR(i, bi, ai) {
                ORD[i] = ORD[i + 1];
            }
            ORD[ai] = b;
        }
    }
    FOR(i, 0, N) printf("T%d%c", ORD[i], " \n"[i == N - 1]);

    return 0;
}