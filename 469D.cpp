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



int main() {
    int n, a, b; riii(n, a, b);
    makeSet(0, n - 1);
    vi x(n);
    FOR(i, 0, n) ri(x[i]);
    map<int, int> ind;
    FOR(i, 0, n) ind[x[i]] = i;


    FOR(i, 0, n) {
        int a_x_i = (ind.find(a - x[i]) == ind.end() ? -1 : ind[a - x[i]]);
        int b_x_i = (ind.find(b - x[i]) == ind.end() ? -1 : ind[b - x[i]]);
        if (a_x_i != -1 && find(i) != find(a_x_i))
            unio(find(i), find(a_x_i));
        if (b_x_i != -1 && find(i) != find(b_x_i))
            unio(find(i), find(b_x_i));
    }

    vector<bool> can_a(n, true);
    vector<bool> can_b(n, true);

    FOR(i, 0, n) {
        int a_x_i = (ind.find(a - x[i]) == ind.end() ? -1 : ind[a - x[i]]);
        int b_x_i = (ind.find(b - x[i]) == ind.end() ? -1 : ind[b - x[i]]);
        if (a_x_i == -1)
            can_a[find(i)] = 0;
        if (b_x_i == -1)
            can_b[find(i)] = 0;

        if (!can_a[find(i)] && !can_b[find(i)]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    FOR(i, 0, n) {
        if (can_a[find(i)])
            printf("0 ");
        else
            printf("1 ");
    }
    printf("\n");

    return 0;
}