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
ll arr[maxN+10];
ll arr2[maxN+10];

int main(){
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		FOR(i,0,n)
			rl(arr[i]);

		arr2[n-1] = arr[n-1];
		ROF(i,n-2,-1)
			arr2[i] = min(arr[i],arr2[i+1]);

		ll max_dif = 0;
		FOR(i,0,n-1)
			max_dif = max(max_dif, arr[i]-arr2[i+1]);

		int time = 0;
		while(max_dif>0){
			max_dif -= (1<<time);
			time++;
		}
		printf("%d\n",time );
	}
	return 0;
}