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
const int maxN = 1e4+10; // CAMBIAR ESTE

// GJNM
int arr[maxN];

int main(){
	int n;
	while(ri(n), n>0){
		FOR(i,0,n)
			ri(arr[i]);

		int ans = 0;
		int sum = 0;
		FOR(i,0,n){
			sum += arr[i];
			ans = max(ans, sum);
			if ( sum < 0 )
				sum = 0;
		}
		if ( ans<=0 )
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n",ans );

	}
	return 0;
}