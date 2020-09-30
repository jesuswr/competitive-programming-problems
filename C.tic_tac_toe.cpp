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
char s[5][5];

int main() {
    scanf("%s", s[0]);
    scanf("%s", s[1]);
    scanf("%s", s[2]);
    int x = 0, o = 0;
    FOR(i, 0, 3) {
        FOR(j, 0, 3) {
            if (s[i][j] == 'X')
                x++;
            else if (s[i][j] == '0')
                o++;
        }
    }

    if ((x != o) && (x != o + 1)) {
        printf("illegal\n");
        return 0;
    }

    bool win_x = false, win_o = false;

    FOR(i, 0, 3) {
        if (s[i][0] == s[i][1] && s[i][1] == s[i][2]) {
            if (s[i][0] == '0')
                win_o = true;
            if (s[i][0] == 'X')
                win_x = true;
        }

        if (s[0][i] == s[1][i] && s[1][i] == s[2][i]) {
            if (s[0][i] == '0')
                win_o = true;
            if (s[0][i] == 'X')
                win_x = true;
        }
    }

    if (s[0][0] == s[1][1] && s[1][1] == s[2][2]){
        if (s[0][0] == '0')
            win_o = true;
        if (s[0][0] == 'X')
            win_x = true;
    }

    if (s[2][0] == s[1][1] && s[1][1] == s[0][2]){
        if (s[1][1] == '0')
            win_o = true;
        if (s[1][1] == 'X')
            win_x = true;
    }

    if (win_x && win_o){
        printf("illegal\n");
        return 0;
    }
    if (win_x && x == o){
        printf("illegal\n");
        return 0;
    }

    if (win_x){
        printf("the first player won\n");
        return 0;
    }

    if (win_o && x > o){
        printf("illegal\n");
        return 0;
    }

    if (win_o){
        printf("the second player won\n");
        return 0;
    }

    if (x + o == 9){
        printf("draw\n");
        return 0;
    }

    if (o == x){
        printf("first\n");
    }
    else{
        printf("second\n");
    }


    return 0;
}