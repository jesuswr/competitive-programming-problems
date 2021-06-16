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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int father[MAXN], siz[MAXN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m) {
    for (int i = n; i <= m; ++i) {
        father[i] = -1;
        siz[i] = 0;
    }
}
int find(int x) {
    if (father[x] == -1) // -1 significa que es el representante del set
        return x;
    return father[x] = find(father[x]);
}
void unio(int x, int y) { // x y y tienen que ser los representantes
    if (siz[x] > siz[y])
        father[y] = x;
    else {
        father[x] = y;
        if ( siz[x] == siz[y] ) siz[y]++;
    }
}

int A[MAXN];
int B[MAXN];

bool comp(int a, int b) {
    return A[a] < A[b];
}

void solve() {
    int n; ri(n); ll p; rl(p);
    makeSet(0, n - 1);
    FOR(i, 0, n) ri(A[i]);
    FOR(i, 0, n) B[i] = i;
    sort(B, B + n, comp);

    int cc = n;
    ll cst = 0;
    FOR(j, 0, n) {
        int i = B[j];
        if (A[i] >= p) break;
        int l = i, r = i;
        while (l > 0 && A[l - 1] % A[i] == 0 && find(l - 1) != find(i)) {
            unio(find(l - 1), find(i));
            cst += A[i];
            --l;
            --cc;
        }
        while (r + 1 < n && A[r + 1] % A[i] == 0 && find(r + 1) != find(i)) {
            unio(find(r + 1), find(i));
            cst += A[i];
            ++r;
            --cc;
        }
    }
    printf("%lld\n", cst + (cc - 1) * p);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}