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
const int maxN = 2e5; // CAMBIAR ESTE

// GJNM
int arr[maxN+10];
int peaks[maxN+10];

int main(){
	int t;
	ri(t);
	while(t--){
		int n,k;
		rii(n,k);
		FOR(i,0,n)
			ri(arr[i]);

		FOR(i,1,n-1)
			if ( arr[i] > arr[i-1] && arr[i] > arr[i+1] )
				peaks[i] = 1;
			else
				peaks[i] = 0;
		
		FOR(i,1,n)
			peaks[i] += peaks[i-1];

		

		int mn = -1000;
		int ind = INF;
		FOR(i,0,n-k+1){
			if ( mn < peaks[k+i-2] - peaks[i] ){
				ind = i+1;
				mn = peaks[k+i-2] - peaks[i];
			}		
		}
		printf("%d %d\n",mn+1, ind );

	}
	return 0;
}