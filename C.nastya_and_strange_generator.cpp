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
map<int,int> mp;

int main(){
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		FOR(i,0,n){
			int aux;
			ri(aux);
			mp[aux] = i+1;
		}

		bool ans = true;
		int sz = n;
		int i = 1;
		while(i<=n){
			int j = i;
			sz = n-i+1;
			while( mp[j] != sz ){
				if ( mp[j] + 1 == mp[j+1] )
					j++;
				else{
					ans = false;
					break;
				}
			}
			i = j;
			i++;
			if ( ! ans )
				break;
		}
		if ( ans )
			printf("Yes\n");
		else
			printf("No\n");

		mp.clear();
	}
	return 0;
}