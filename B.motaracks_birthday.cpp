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
const int maxN = 2e5; // CAMBIAR ESTE

// GJNM
int A[maxN];

int main(){
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		vector<int> B;
		FOR(i,0,n){
			ri(A[i]);
			if ( A[i] != -1 )
				B.pb(A[i]);
		}

		if ( B.size() == 1 ){
			printf("%d %d\n", 0, B[0]);
			continue;
		}
		if ( B.size() == 0 ){
			printf("0 1\n");
			continue;
		}
		int mx = -1;
		int mn = 1e9 + 2;
		int ans = -1;

		FOR(i,1,n-1){
			if ( A[i] != -1 && ( A[i-1] == -1 || A[i+1] == -1) ){
				mx = max(mx, A[i]);
				mn = min(mn, A[i]);
			}
			if ( A[i] != -1 && A[i-1] != -1 )
				ans = max(ans, abs(A[i] - A[i-1]));
			if ( A[i] != -1 && A[i+1] != -1 )
				ans = max(ans, abs(A[i] - A[i+1]));
		}

		if ( A[0] != -1 && A[1] == -1 ){
			mx = max(mx, A[0]);
			mn = min(mn, A[0]);
		}
		if ( A[n-1] != -1 && A[n-2] == -1 ){
			mx = max(mx, A[n-1]);
			mn = min(mn, A[n-1]);
		}

		printf("%d %d\n", max((mx-mn+1)/2,ans), (mx+mn)/2);


		
	}
	return 0;
}