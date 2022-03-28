#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i=n; i<(int)m; i++)
#define ROF(i,n,m) for(int i=n; i>(int)m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) ri(a),ri(b)
#define riii(a,b,c) rii(a,b),ri(c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) lri(a),lri(b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define debug true
#define dprintf debug && printf

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e5+5;

int N,Q;
vi G[MAXN];
int A[MAXN];
int X[1010];

vi ST;
bitset<1000001> DP;
void pre_x(){
    DP[0] = 1;
    FOR(i,0,Q) DP = DP | (DP << X[i]);
    FOR(i,0,1000001) if (DP[i]) ST.pb(i);
}

ll ANS;
int go(int u = 0, int f = -1){
    int mx = 0;
    for(auto v : G[u]) if (v != f)
        mx = max(mx, go(v,u));
    int dff = mx - A[u];
    auto it = lb(all(ST), dff);
    if (it == ST.end()){
        printf("-1\n");
        exit(0);
    }
    A[u] += *it;
    ANS += A[u];
    return A[u];
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    rii(N,Q);
    FOR(i,0,N) ri(A[i]);
    FOR(_,1,N){
        int a,b; rii(a,b);
        --a,--b;
        G[a].pb(b);
        G[b].pb(a);
    }
    FOR(i,0,Q) ri(X[i]);
    pre_x();
    go();
    printf("%lld\n", ANS);
    return 0;
}
