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
int arr[maxN];
int arr2[maxN];

int main(){
	int n,k1,k2;
	riii(n,k1,k2);
	FOR(i,0,n){
		ri(arr[i]);
	}
	FOR(i,0,n){
		ri(arr2[i]);
	}
	priority_queue<ll> pq;
	FOR(i,0,n){
		pq.push(abs(arr[i]-arr2[i]));
	}
	int k = k1+k2;
	while(k){
		k--;
		ll aux = pq.top();
		pq.pop();
		pq.push(abs(aux-1));
	}
	ll ans = 0;
	while(!pq.empty()){
		ll aux = pq.top();
		ans += aux*aux;
		pq.pop();
	}
	printf("%lld\n", ans);


	return 0;
}