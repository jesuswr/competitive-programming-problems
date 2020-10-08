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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN];

int query(int i, int j) {
    printf("? %d %d\n", i + 1, j + 1);
    fflush(stdout);
    int ret;
    ri(ret);
    return ret;

}

int main() {
    ri(n);
    if (n == 1) {
        printf("! 1\n");
        fflush(stdout);
        return 0;
    }

    int i = 0, j = 1;
    int cnt = n;
    while (cnt > 1) {
        while (i < n && (a[i] != 0 || i == j))
            i++;
        while (j < n && (a[j] != 0 || i == j))
            j++;

        int aij = query(i, j);
        int aji = query(j, i);
        if (aij > aji)
            a[i] = aij;
        else
            a[j] = aji;
        cnt--;
    }
    if (a[i] == 0)
        a[i] = n;
    if (a[j] == 0)
        a[j] = n;
    printf("! ");
    FOR(i, 0, n) {
        printf("%d ", a[i]);
    } printf("\n");
    fflush(stdout);

    return 0;
}