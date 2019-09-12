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
 
const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE
const double maxD = (double)1e10;
 
// GJNM
long double mat[31][31];
map<string,int> mp;
 
int main()
{
    int v, e;
    int o = 1;
    
    while ( true )
    {
        ri(v);
        if ( v == 0 ) return 0;
        bool ans = false;
        string aux, aux2;
        FOR(i,0,v)
        {
            cin >> aux;
            mp[aux] = i;
        }
        FOR(i,0,v) FOR(j,0,v) 
        {
            mat[i][j] = 0.0;
            if (i==j) mat[i][j] = 1.0;
        }
        ri(e);
        long double d;
        FOR(i,0,e)
        {
            cin >> aux >> d >> aux2;
            mat[ mp[aux] ][ mp[aux2] ] = d;
        }
        FOR(k,0,v) FOR(i,0,v) FOR(j,0,v) mat[i][j] = max(mat[i][j],mat[i][k]*mat[k][j]);
        
        FOR(i,0,v) if ( mat[i][i] > 1.0 ) ans = true;
        if ( ans ) printf("Case %d: Yes\n", o);
        else printf("Case %d: No\n", o);
        o++;
        mp.clear();
    }
    return 0;
} 