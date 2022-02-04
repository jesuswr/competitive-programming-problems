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
const int MAXN = 1e6; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int father[MAXN], siz[MAXN], COL[MAXN];
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

int REP[MAXN];


int main() {
    memset(REP, -1, sizeof(REP));
    int q; ri(q);
    makeSet(0, q);
    int i = 0;
    while (q--) {
        int t; ri(t);
        if (t == 1) {
            int a; ri(a);
            COL[i] = a;
            if (REP[a] != -1)
                unio(find(REP[a]), i);
            else
                REP[a] = i;
            ++i;
        }
        else {
            int from, to; rii(from, to);
            if (from == to)
                continue;
            if (REP[from] == -1)
                continue;
            else if (REP[to] == -1) {
                REP[to] = find(REP[from]);
                REP[from] = -1;
                COL[REP[to]] = to;
            }
            else {
                unio(find(REP[from]), find(REP[to]));
                COL[find(REP[from])] = to;
                REP[from] = -1;
            }
        }
    }
    FOR(j, 0, i) {
        printf("%d ", COL[find(j)] );
    }
    printf("\n");
    return 0;
}