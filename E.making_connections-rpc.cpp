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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM

int father[MAXN], siz[MAXN];
ll cnt[MAXN];
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
        cnt[x] = cnt[x] + cnt[y];
    }
    else {
        father[x] = y;
        cnt[y] = cnt[x] + cnt[y];
        if ( siz[x] == siz[y] ) siz[y]++;
    }
}


int main() {
    int n, m;
    rii(n, m);
    ll sm = n, comp = n;
    makeSet(1, n);
    FOR(_, 0, m) {
        int type; ri(type);
        if (type == 1) {
            int a, b; rii(a, b); a = find(a); b = find(b);
            if (a == b)
                continue;
            sm -= cnt[a] * cnt[a];
            sm -= cnt[b] * cnt[b];
            comp--;
            unio(a, b);
            a = find(a);
            sm += cnt[a] * cnt[a];
        }
        else {
            ll sm2 = sm, comp2 = comp;
            ll gcdd = __gcd(sm2, comp2);
            sm2 = sm2 / gcdd;
            comp2 = comp2 / gcdd;
            printf("%lld/%lld\n", sm2, comp2);
        }
    }

    return 0;
}