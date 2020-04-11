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
const int maxN = 1e3; // CAMBIAR ESTE

// GJNM
char s1[maxN];

int main(){
	int t;
	ri(t);
	FOR(k,1,t+1){
		int n;
		ri(n);
		bool ans = true;
		string front, back, middle;
		FOR(j,0,n){
			scanf("%s", s1);
			int n = strlen(s1);
			int cnt = 0;
			FOR(i,0,n)
				if ( s1[i] == '*' )
					cnt++;
				

			if (cnt>1){
				int i = 0;
				int cnt2 = 0;
				while( i < n ){
					if ( s1[i] == '*' ){
						cnt2++;
						i++;
						continue;
					}
					if ( cnt2>0 && cnt2<cnt)
						middle.pb(s1[i]);
					i++;
				}
			}
			int i = 0;
			if ( !ans )
				continue;
			while( s1[i] != '*' ){
				if ( front.size() <= i ){
					front.push_back(s1[i]);
					i++;
					continue;
				}

				if ( s1[i] != front[i] ){
					ans = false;
				}
				i++;
			}

			i = n-1;
			while( s1[i] != '*' ){
				if ( back.size() <= n-1-i ){
					back.push_back(s1[i]);
					i--;
					continue;
				}

				if ( s1[i] != back[n-1-i] ){
					ans = false;
				}
				i--;
			}
		}
		printf("Case #%d: ",k );
		if ( ans ){
			reverse(back.begin(), back.end());
			cout << front << middle << back << endl;
		}
		else{
			printf("*\n");
		}
	}
	return 0;
}