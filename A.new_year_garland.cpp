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
int arr[3];

int main()
{
	int t;
	ri(t);
	while( t-- ){
		riii(arr[0],arr[1],arr[2]);
		sort(arr,arr+3);
		if ( arr[0] + arr[1] > arr[2] ){
			int diff = arr[1] - arr[0];
			arr[2] -= diff;
			arr[1] -= diff;
			if ( arr[2] > 0 ){
				printf("YES\n");
			}
		}
		else{
			if ( arr[2] >= arr[1] + arr[0] + 2){
				printf("NO\n");
			}
			else{
				printf("YES\n");
			}
		}
	}
	return 0;
}