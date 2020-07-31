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
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
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
const int maxN = 3e5; // CAMBIAR ESTE

// GJNM
ll A[maxN];
vi B[maxN];
int DEG[maxN];

int main(){
    int n;
    ri(n);
    FOR(i,0,n)
        rl(A[i]);
    FOR(i,0,n){
        int to;
        ri(to); to--;
        B[i].pb(to);
        if ( to == -2 )
            continue;
        DEG[to]++;
    }
    ll ans = 0;
    queue<int> topo;
    FOR(i,0,n){
        if ( DEG[i] == 0 )
            topo.push(i);
    }
    vi ord, post;
    while( !topo.empty() ){
        int x = topo.front(); topo.pop();
        if ( A[x] >= 0 ){
            ord.pb(x+1);
        }
        else{
            post.pb(x+1);
        }
        ans += A[x];

        for(auto y : B[x]){
            if ( y == -2 )
                continue;
            DEG[y]--;
            if ( DEG[y] == 0 )
                topo.push(y);
            A[y] += max(A[x], 0ll);
        }
    }
    printf("%lld\n", ans);
    for(auto x : ord)
        printf("%d ", x);
    reverse(post.begin(), post.end());
    for(auto x : post)
        printf("%d ", x);
    
    printf("\n");
    return 0;
}