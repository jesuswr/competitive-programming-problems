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
const int maxN = 3e5; // CAMBIAR ESTE

// GJNM
int father[maxN], siz[maxN], n_elem[maxN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m) {
    for (int i = n; i <= m; ++i) {
        father[i] = -1;
        siz[i] = 0;
        n_elem[i] = 1;
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
        n_elem[x] += n_elem[y];
    }
    else {
        father[x] = y;
        if ( siz[x] == siz[y] ) siz[y]++;
        n_elem[y] += n_elem[x];
    }
}

char a[maxN];


void solve() {
    int n;
    ri(n);
    scanf("%s", a);
    makeSet(0, n);
    FOR(i, 0, n) {
        if ( a[i] == a[(i + 1) % n] && find(i) != find((i + 1) % n)) {
            unio(find(i), find((i + 1) % n));
        }
    }
    ll ans = 0;
    FOR(i, 0, n) {
        if ( find(i) == i ) {
            if ( n_elem[i] == n ) {
                printf("%d\n", (n_elem[i] + 2) / 3);
                return;
            }
            else {
                ans += (n_elem[i]) / 3;
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
    }

    return 0;
}