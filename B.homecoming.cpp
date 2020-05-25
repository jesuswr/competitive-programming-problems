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
    const int maxN = 1e5+10; // CAMBIAR ESTE
     
    // GJNM
    char A[maxN];
    ll cost[maxN];
     
    int main(){
    	int t;
    	ri(t);
    	while(t--){
    		ll a,b,p;
    		rl(a), rll(b,p);
    		scanf("%s", A);
    		int n = strlen(A);
    		vector< pair<int,ll> > aux;
    		aux.pb( { 0, (A[0] == 'A' ? a : b) } );
    		FOR(i,1,n-1){
    			if ( A[i] != A[i-1] ){
    				aux.pb({i, aux[aux.size()-1].S + (A[i] == 'A' ? a : b) }  );
    			}
    		}
     
    		ll tot_c = aux[aux.size()-1].S;
     
    		aux.pb({n-1,LLINF});
     
    		for(auto pp : aux){
    			if ( tot_c - pp.S + (A[pp.F] == 'A' ? a : b) <= p ){
    				printf("%d\n", pp.F+1);
    				break;
    			}
    		}
    	}
    	return 0;
    }