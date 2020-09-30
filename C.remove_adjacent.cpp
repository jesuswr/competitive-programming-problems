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
#include <list>

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
list<char> s;

int main() {
    scanf("%d\n", &n);
    s.push_back('?');
    FOR(i, 0, n) {
        char aux; scanf("%c", &aux);
        s.push_back(aux);
    }
    s.push_back('?');
    int ans = 0;
    ROF(i, 25, -1) {
        bool change = true;
        while (change) {
            change = false;
            vector<list<char>::iterator> era;
            for (auto it = s.begin(); it != s.end(); it++) {
                if (*it != 'a' + i)
                    continue;
                auto it_nxt = it; it_nxt++;
                auto it_prev = it; it_prev--;
                if (*it == *it_nxt + 1 || *it == *it_prev + 1) {
                    change = true;
                    ans++;
                    era.push_back(it);
                }
            }
            for (auto it : era) {
                s.erase(it);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}