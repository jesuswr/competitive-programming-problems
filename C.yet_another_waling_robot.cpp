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
map<pii,int> prevEq;

int main(){
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		scanf("%*c");
		int hor = 0;
		int vert = 0;
		int min1, min2;
		prevEq[ {0,0} ] = 1;
			min2 = INF;
			min1 = -10000;
		FOR(i,0,n){
			char c;
			scanf("%c",&c);
			if (c=='L')
				hor--;
			if (c=='R')
				hor++;
			if (c=='D')
				vert--;
			if (c=='U')
				vert++;

			//printf("hey %d %d %d\n",i+1 , hor, vert);
			if ( prevEq.find( {hor,vert} ) == prevEq.end() )
				prevEq[ {hor,vert} ] = i+2;
			else{
				//printf("hola\n");
				//printf("%d %d\n", i+1 - prevEq[ {hor,vert} ], min2 - min1);
				if ( i+1 - prevEq[ {hor,vert} ] < min2 - min1 ){
					min2 = i+1;
					min1 = prevEq[ {hor,vert} ];
				}
				prevEq[ {hor,vert} ] = i+2;
			}

		}
		if ( min2 == INF )
			printf("-1\n");
		else
			printf("%d %d\n", min1 , min2 );	

		prevEq.clear();	
	}
	return 0;
}