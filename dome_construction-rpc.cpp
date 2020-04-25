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

int main(){
	int n,k;
	rii(n,k);
	priority_queue< long double > pq;
	FOR(i,0,n){
		long double x,y,z;
		scanf("%Lf %Lf %Lf",&x,&y,&z);		
		//printf("%Lf %Lf %Lf\n",x,y,z );
		long double insrt = x*x + y*y + z*z;
		if (pq.size()>=k){
			if ( insrt<pq.top()){
				pq.pop();
				pq.push(insrt);
			}
		}
		else
			pq.push(insrt);
	}
	long double anss = sqrt(pq.top());
	printf("%Lf\n", anss);
	return 0;
}