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
int n,k;
ll arr[maxN+10];

int main(){
	int t = 1;
	int t2;
	ri(t2);
	while(t<=t2){
		rii(n,k);
		FOR(i,0,n){
			rl(arr[i]);
		}
		priority_queue< pair< ll , pair<ll,ll> > > pq;
		FOR(i,0,n-1)
			pq.push( { arr[i+1] - arr[i] , {1,arr[i+1]-arr[i]} } );

		ll ans;
		// this problem is equivalent to creating subsegments in each segment
		// given, you just order by the biggest subsegment of each segment and divide that
		// and add it to the priority queue, you need to save how many subsegments
		// you have in that segment so next time you know how many you will have
		while(k>0){
			auto x = pq.top();
			if (x.f==1)
				break;
			pq.pop();
			int or_diff = x.s.s;
			int times_div = x.s.f + 1;
			int new_diff = (or_diff + times_div - 1)/times_div;
			pq.push({ new_diff , {times_div,or_diff} });
			k--;
		}

		ans = pq.top().f;
		printf("Case #%d: %lld\n", t, ans);

		t++;
	}
	return 0;
}