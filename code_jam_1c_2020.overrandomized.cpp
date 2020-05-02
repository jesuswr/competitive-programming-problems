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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
char query[20], ans[20];
int roof[30];
bool active[30];
char ret[10];
int cnt[30];
bool notzero[30];

int main(){
	int t;
	ri(t);
	FOR(w,1,t+1){
		printf("Case #%d: ", w);
		int u;
		ri(u);
		FOR(i,0,30){
			active[i] = false;
			roof[i] = INF;
			cnt[i] = 0;
			notzero[i] = false;
		}
		bool case3 = false;
		FOR(i,0,10000){
			scanf("%s %s", query, ans);
			int n = strlen(query);
			int m = strlen(ans);
			FOR(j,0,m)
				active[ ans[j] - 'A' ] = true;
			
			if(query[0] == '-'){
				case3 = true;
				FOR(j,0,1){
					notzero[ ans[j] - 'A' ] = true;
					cnt[ ans[j] - 'A']++;
				}
				continue;
			}

			if ( n == m ){
				int ind = ans[0] - 'A';
				roof[ind] = min(roof[ind], query[0]-'0');
				if ( query[0] == '1' ){
					int aux = 1;
					int ind;
					while(aux < n){
						ind = ans[aux] - 'A';
						roof[ind] = min(roof[ind], query[aux]-'0');
						if (ans[aux] == '1')
							aux++;
						else
							break;
					} 
				}
			}
			else{
				FOR(j,0,m){
					int ind = ans[j] - 'A';
					roof[ind] = min(roof[ind], 9);
				}
			}
			
		}

		if ( case3 ){
			set< pair<int,char > > st;
			FOR(i,0,30){
				if ( !active[i] )
					continue;

				if ( active[i] && notzero[i] == false){
					st.insert({-INF,i+'A'});
					continue;
				}

				st.insert( {-cnt[i],i+'A'});
			}
			for(auto p : st){
				printf("%c",p.s );
			}
			printf("\n");
			continue;
		}

		FOR(i,0,30){
			if ( !active[i] )
				continue;
			if ( roof[i] == INF || roof[i] == 0){
				ret[0] = i+'A';
			}
			else{
				ret[roof[i]] = i+'A';
			}
		}
		FOR(i,0,10){
			printf("%c",ret[i] );
		}
		printf("\n");
	}
	return 0;
}