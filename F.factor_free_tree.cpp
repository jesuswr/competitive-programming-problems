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
const int MAXN = 1e7 + 10; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN];

int father[MAXN];
int min_div[MAXN];
vi divs[MAXN]; // here divs[i] has the indexes of numbers such that a[j] % i == 0
vi divs2[MAXN]; // here are the divisors of a[i]

void precompute_sieve() {
    FOR(i, 0, MAXN) {
        divs[i].pb(-1);
        min_div[i] = 1e8;
    }

    FOR(i, 2, MAXN) {
        if (min_div[i] != 1e8)
            continue;
        int j = i;
        while (j < MAXN) {
            min_div[j] = min(min_div[j], i);
            j += i;
        }
    }
}


bool valid(int l, int r, int i) {
    for (auto p : divs2[i]) {
        auto it_l = lower_bound(all(divs[p]), i);
        it_l--;
        auto it_r = upper_bound(all(divs[p]), i);
        if (*it_l >= l || *it_r <= r)
            return false;
    }
    return true;
}


bool f(int l, int r, int dad) {
    if (l > r)
        return true;

    int tpl = l, tpr = r;
    while (tpl <= tpr) {
        if (valid(l, r, tpl)) {
            father[tpl] = dad;
            return f(l, tpl - 1, tpl) && f(tpl + 1, r, tpl);
        }
        if (valid(l, r, tpr)) {
            father[tpr] = dad;
            return f(l, tpr - 1, tpr) && f(tpr + 1, r, tpr);
        }
        tpl++;
        tpr--;
    }
    return false;
}

int main() {
    precompute_sieve();

    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
        int aux = a[i];
        while (aux > 1) {
            int aux2 = min_div[aux];
            divs[aux2].pb(i);
            divs2[i].pb(aux2);
            while (aux % aux2 == 0)
                aux /= aux2;
        }
    }
    FOR(i, 0, MAXN) {
        divs[i].pb(INF);
    }

    if (f(0, n - 1, -1)) {
        FOR(i, 0, n) {
            printf("%d ", father[i] + 1);
        }
        printf("\n");
    }
    else
        printf("impossible\n");

    return 0;
}