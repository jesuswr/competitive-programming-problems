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
string s;

int solve(int l, int r, int first, int last) {
    //printf("quiero que de %d a %d empiece con %d\n", l, r, first);
    int aux = first;
    while (l < r && s[l] == '0' + aux) {
        l++;
        aux = 1 - aux;
    }
    if (l >= r)
        return 0;

    int aux2 = last;
    while (r >= 0 && s[r] == '0' + aux2) {
        r--;
        aux2 = 1 - aux2;
    }
    if (r < l)
        return 0;

    return 1 + solve(l + 1, r - 1, aux, aux2);
}

int main() {
    int t;
    ri(t);
    while (t--) {
        int n;
        ri(n);
        cin >> s;
        int sad = 0;
        int sad2 = 0;
        FOR(i, 1, n) {
            sad += (s[i] == '1' && s[i - 1] == '1');
            sad2 += (s[i] == '0' && s[i - 1] == '0');
        }
        printf("%d\n", max(sad, sad2));
    }

    return 0;
}