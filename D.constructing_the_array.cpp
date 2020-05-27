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
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
int A[maxN];

int main(){
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		priority_queue< pair< int, pair< int, int > > > pq;
		pq.push({n,{0,n-1}});
		int curr = 1;
		while (!pq.empty()){

			int len = pq.top().F;
			int left = -pq.top().S.F, right = pq.top().S.S;
			pq.pop();
			if ( len <= 0 )
				break;

			if ( len&1 ){
				int mid = (left+right)/2;
				A[mid] = curr++;
				pq.push({ mid-1 - left + 1 , {-left,mid-1} });
				pq.push({ right - (mid+1) +1 , {-(mid+1),right} });
			}
			else{
				int mid = (left+right-1)/2;
				A[mid] = curr++;
				pq.push({ mid-1 - left + 1 , {-left,mid-1} });
				pq.push({ right - (mid+1) +1 , {-(mid+1),right} });
			}
		}

		FOR(i,0,n)
			printf("%d ",A[i] );
		printf("\n");
	}
	return 0;
}