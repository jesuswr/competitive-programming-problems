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

int main() {
    int n, m;
    rii(n, m);
    vector<char> ans;
    FOR(i, 1, n) {
        ans.pb('U');
    }
    FOR(i, 1, m) {
        ans.pb('L');
    }

    int curr_r = 0, curr_c = 0;
    while (curr_r < n) {
        if (curr_c == 0) {
            while (curr_c < m - 1) {
                ans.pb('R');
                curr_c++;
            }
        }
        else {
            while (curr_c > 0) {
                ans.pb('L');
                curr_c--;
            }
        }
        curr_r++;
        if (curr_r < n)
            ans.pb('D');
    }
    printf("%d\n",(int)ans.size() );
    for(auto c : ans){
        printf("%c", c);
    }printf("\n");



    return 0;
}