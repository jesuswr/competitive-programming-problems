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
int rc[100];
int cc[100];
int r,c;

bool isCorner( int rr, int cc ){
	if ( rr==0 && cc==0 ) return true;
	if ( rr==0 && cc==c-1 ) return true;
	if ( rr==r-1 && cc==c-1 ) return true;
	if ( rr==r-1 && cc==0 ) return true;
	return false;
}

int main()
{
	int t;
	ri(t);
	while(t--){
		rii(r,c);
		char x;
		FOR(i,0,max(r,c)) rc[i] = cc[i] = 0;
		bool corner = false;
		bool ans = false;
		bool comp = false;
		bool side = false;
		bool sidee = false;
		int cnt = 0;
		scanf("%*c");
		FOR(i,0,r){
			FOR(j,0,c){
				scanf("%c",&x);
				if ( x == 'A' ){
					ans = true;
					cnt++;
					rc[i]++;
					cc[j]++;
					if (( i == 0 || i == r-1)) sidee = true;
					if (( j == 0 || j == c-1)) sidee = true;
					if ( rc[i] == c ) comp = true;
					if ( cc[j] == r ) comp = true;
					if ( rc[i] == c && ( i == 0 || i == r-1)) side = true;
					if ( cc[j] == r && ( j == 0 || j == c-1)) side = true;
					if ( isCorner(i,j) ) 
						corner = true;
				}
			}
			scanf("%*c");
		}
		if ( !ans )
			printf("MORTAL\n");
		else if ( cnt == r*c)
			printf("0\n");
		else if ( side )
			printf("1\n");
		else if ( comp || corner )
			printf("2\n");
		else if ( sidee )
			printf("3\n");
		else
			printf("4\n");

	}
	return 0;
}