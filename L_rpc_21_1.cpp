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

using namespace std;

typedef long long ll;
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

// GJNM
int father[MAXN], siz[MAXN], cnt[MAXN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m) {
    for (int i = n; i <= m; ++i) {
        father[i] = -1;
        siz[i] = 0;
        cnt[i] = 1;
    }
}
int find(int x) {
    if (father[x] == -1) // -1 significa que es el representante del set
        return x;
    return father[x] = find(father[x]);
}
void unio(int x, int y) { // x y y tienen que ser los representantes
    if (siz[x] > siz[y]) {
        father[y] = x;
        cnt[x] += cnt[y];
    }
    else {
        father[x] = y;
        if ( siz[x] == siz[y] ) siz[y]++;
        cnt[y] += cnt[x];
    }
}
int N, P;

int main() {
    while (scanf("%d %d", &N, &P) != EOF) {
        makeSet(1, N);
        FOR(_, 0, P) {
            int a, b;
            rii(a, b);
            if (find(a) != find(b)) unio(find(a), find(b));
        }
        vii out;
        FOR(i, 1, N + 1) {
            int fat = find(i);
            if (siz[fat] != -1) {
                out.pb({i, cnt[fat]});
                siz[fat] = -1;
            }
        }
        for(auto p : out) printf("%d %d\n", p.F, p.S);
    }
    return 0;
}