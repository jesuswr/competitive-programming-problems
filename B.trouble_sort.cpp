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
int A[maxN], B[maxN];

int main(){
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		int one = 0, zero = 0;
		FOR(i,0,n)
			ri(A[i]);
		FOR(i,0,n){
			ri(B[i]);
			if ( B[i] == 1 )
				one++;
			else
				zero++;
		}
		if ( one > 0 && zero > 0 ){
			printf("Yes\n");
			continue;
		}
		bool ord = true;
		FOR(i,0,n-1){
			if ( A[i] > A[i+1] )
				ord = false;
		}
		if ( ord )
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}