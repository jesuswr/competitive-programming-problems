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
const int maxN = 1e5+10; // CAMBIAR ESTE

// GJNM
char s[maxN];

int main()
{
	int t;
	ri(t);
	while( t-- ){
		scanf("%s",s);
		int n = strlen(s);
		if (s[0]=='?'){	
			if ( s[1] == '?' )
				s[0] ='a';
			else if ( s[1] =='a' )
				s[0] = 'b';
			else
				s[0] = 'a';

		}
		bool ans = true;
		FOR(i,0,n){
			if ( i == n-1 && s[i] == '?'){
				if ( s[i-1] == 'a' )
					s[i] = 'b';
				else 
					s[i] = 'a';
			}
			if ( s[i] == '?' ){
				if ( s[i-1] == 'a' && s[i+1]=='a'){
					s[i] = 'b';
				}
				if ( s[i-1] == 'b' && s[i+1]=='a'){
					s[i] = 'c';
				}
				if ( s[i-1] == 'a' && s[i+1]=='b'){
					s[i] = 'c';
				}
				if ( s[i-1] == 'a' && s[i+1]=='c'){
					s[i] = 'b';
				}
				if ( s[i-1] == 'c' && s[i+1]=='a'){
					s[i] = 'b';
				}
				if ( s[i-1] == 'b' && s[i+1]=='b'){
					s[i] = 'a';
				}
				if ( s[i-1] == 'c' && s[i+1]=='c'){
					s[i] = 'b';
				}
				if ( s[i-1] == 'b' && s[i+1]=='c'){
					s[i] = 'a';
				}
				if ( s[i-1] == 'c' && s[i+1]=='b'){
					s[i] = 'a';
				}
				if ( s[i-1] == 'a' && s[i+1]=='?'){
					s[i] = 'b';
				}
				if ( s[i-1] == 'b' && s[i+1]=='?'){
					s[i] = 'a';
				}
				if ( s[i-1] == 'c' && s[i+1]=='?'){
					s[i] = 'b';
				}				

			}else{
				if ( s[i] == s[i+1] )
					ans = false;
			}
		}
		if ( ans ) printf("%s\n", s);
		else printf("-1\n");
	}
	return 0;
}