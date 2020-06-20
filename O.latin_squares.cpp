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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		char M[40][40];
		set<char> rows[40], cols[40];

		FOR(i,0,n)
			scanf("%s", M[i]);

		bool isLatin = true, isOrder = true;

		FOR(i,0,n){
			FOR(j,0,n){
				rows[i].insert(M[i][j]);
				cols[j].insert(M[i][j]);
			}
		}

		FOR(i,0,n){
			if ( rows[i].size() != n || cols[i].size() != n )
				isLatin = false;
		}

		FOR(i,0,n-1){
			if ( M[0][i+1] < M[0][i] || M[i+1][0] < M[i][0] )
				isOrder = false;
		}

		if ( isOrder && isLatin )
			printf("Reduced\n");
		else if ( isLatin )
			printf("Not Reduced\n");
		else
			printf("No\n");
	}
	return 0;
}