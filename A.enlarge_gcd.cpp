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
const int MAXN = 4e5; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN];
int min_div[15000010];
int cnt[15000010];

int main() {
    FOR(i, 0, 15000010) {
        min_div[i] = INF;
    }
    FOR(i, 2, 15000010) {
        if (min_div[i] != INF)
            continue;
        int j = i;
        while (j < 15000010) {
            min_div[j] = min(min_div[j], i);
            j += i;
        }
    }



    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    int gcd = a[0];
    FOR(i, 1, n) {
        gcd = __gcd(gcd, a[i]);
    }
    FOR(i, 0, n) {
        a[i] = a[i] / gcd;
    }


    FOR(i, 0, n) {
        while (a[i] > 1) {
            int aux = min_div[a[i]];
            cnt[aux]++;
            while (a[i] % aux == 0)
                a[i] /= aux;
        }
    }

    int ans = INF;
    FOR(i, 2, 15000010) {
        if (cnt[i] == 0 || cnt[i] == n)
            continue;
        ans = min(ans, n - cnt[i]);
    }
    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);


    return 0;
}