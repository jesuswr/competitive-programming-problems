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
const int maxN = 1001; // CAMBIAR ESTE

// GJNM
map<pii , bool > checked;
map<pii , bool > points;
pii arr[maxN];
int n;

bool check( pii p ){
	FOR(i,0,n){
		bool w;
		pii c = arr[i];
		if (points.find( {c.F + p.F , c.S + p.S }) == points.end() && points.find( {c.F - p.F , c.S - p.S }) == points.end()){
			return false;
		}
	}
	return true;
}

int main()
{
	ri(n);
	int ans = 0;
	FOR(i,0,n){
		int a, b;
		rii(a,b);
		arr[i].F = a;
		arr[i].S = b;
		points[{a,b}] = true;
 	}
 	if ( n == 1 ){
 		printf("0\n");
 		return 0;
 	}
 	pii st = arr[0];

 	FOR(i,1,n){
 		bool w;
 		pii c = {st.F - arr[i].F, st.S - arr[i].S};
 		if ( checked.find(c) == checked.end()){
 			checked[c] = true;
 			w = check( c );
 			if ( w ){
 				ans++;
 			}
 		}
 		if ( checked.find({-c.F,-c.S}) == checked.end()){
 			checked[{-c.F,-c.S}] = true;
 			w = check( {-c.F,-c.S} );
 			if ( w ){
 				ans++;
 			}
 		}

 	}
 	printf("%d\n", ans);
	return 0;
}