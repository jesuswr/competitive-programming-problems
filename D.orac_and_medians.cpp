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
int A[maxN];

int main(){
	int t;
	ri(t);
	while(t--){
		int n,k;
		rii(n,k);
		bool exists = false;
		FOR(i,0,n){
			ri(A[i]);
			if ( A[i] == k )
				exists = true;
		}

		if ( !exists ){
			printf("no\n");
			continue;
		}
		if ( n == 1 ){
			printf("yes\n");
			continue;
		}

		bool ans = false;
		FOR(i,0,n-1){
			if ( A[i] >= k && A[i+1] >= k )
				ans = true;
		}
		FOR(i,0,n-2){
			if ( A[i] >= k && A[i+2] >= k )
				ans = true;
		}
		if ( ans )
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}