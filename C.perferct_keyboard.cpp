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
char s[300];
char ans[300];
int ind[30];

int main(){
	int t;
	ri(t);
	while(t--){
		FOR(i,0,300)
			ans[i] ='0';
		FOR(i,0,30)
			ind[i] = -1;

		scanf("%s",s);
		int n = strlen(s);
		int l = 99, r = 101;
		ind[ s[0] - 'a' ] = 100;
		ans[100] = s[0];
		bool exist = true;
		FOR(i,1,n){
			int aux = s[i] - 'a';
			if ( ind[aux] == -1 ){
				int aux2 = s[i-1] - 'a';
				if ( ind[aux2] == r-1 ){
					ind[aux] = r;
					ans[r] = aux+'a';
					r++;
				}
				else if ( ind[aux2] == l+1 ){
					ind[aux] = l;
					ans[l] = aux+'a';
					l--;
				}
				else{
					exist = false;
					break;
				}
			}
			else{
				int aux2 = s[i-1] - 'a';
				if ( abs( ind[aux] - ind[aux2]) == 1 )
					continue;
				else{
					exist = false;
					break;
				}
			}
		}
		if ( exist ){
			printf("YES\n");
			FOR(i,l+1,r)
				printf("%c", ans[i]);
			FOR(i,0,26){
				char aux = 'a' + i;
				if ( ind[i] == -1 )
					printf("%c", aux);
			}
			printf("\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}