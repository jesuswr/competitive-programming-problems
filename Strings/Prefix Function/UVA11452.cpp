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
vi pf(const string &s) {
    int n = SZ(s);
    vi pi(n);
    FOR(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j + 1;
    }
    return pi;
}

int main() {
    int t; ri(t);
    while (t--) {
        string s; cin >> s;
        int n = SZ(s);
        vi pi = pf(s);

        int l = n >> 1;
        while (true) {
            bool good = false;
            int k = pi[2 * l - 1];
            while (k > l) k = pi[k - 1];
            if (k == l) {
                int need = n - 2 * l;
                int aux = pi[n - 1];
                while (aux > need) aux = pi[aux - 1];
                if (aux == need) {
                    FOR(i, 0, 8) printf("%c", s[(n + i) % l]);
                    printf("...\n");
                    good = true;
                }
            }
            if (good) break;
            else l--;
        }


    }

    return 0;
}