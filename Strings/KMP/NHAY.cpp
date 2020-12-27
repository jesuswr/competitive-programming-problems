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
void prefix_f(string &s) {
    int n = SZ(s);
    vi pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j + 1;
    }
    s.pb('$');

    char c; dadsadasda = scanf("%*c");
    int last = 0;
    int i = 0;
    while (dadsadasda = scanf("%c", &c), c != '\n') {
        int j = last;
        int curr = 0;
        while (j > 0 && c != s[j]) j = pi[j - 1];
        if (c == s[j]) curr = j + 1;

        if (curr == n) printf("%d\n", i - n + 1);
        last = curr;
        i++;
    }
}

int main() {
    int n;
    while (scanf("%d\n", &n) != EOF) {
        string s;
        cin >> s;
        prefix_f(s);
        printf("\n");
    }
    return 0;
}