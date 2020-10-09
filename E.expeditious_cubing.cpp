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
char s[10];
int a[5];
int goal;

int main() {
    FOR(i, 0, 4) {
        scanf("%s", s);
        int j = 0;
        while (s[j] != '\0') {
            if (s[j] == '.') {
                j++;
                continue;
            }
            a[i] = a[i] * 10;
            a[i] += (s[j] - '0');
            j++;
        }
    }
    scanf("%s", s);
    int j = 0;
    while (s[j] != '\0') {
        if (s[j] == '.') {
            j++;
            continue;
        }
        goal = goal * 10;
        goal += (s[j] - '0');
        j++;
    }

    sort(a, a + 4);
    int x = goal * 3 - a[1] - a[2];
    if (x < a[0])
        printf("impossible\n");
    else if (x >= a[3])
        printf("infinite\n");
    else {
        printf("%.2Lf\n", (long double)x / 100 );
    }

    return 0;
}