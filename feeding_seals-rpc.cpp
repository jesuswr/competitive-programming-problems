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
const int maxN = 1e5+10; // CAMBIAR ESTE

// GJNM
vi arr;
bool ready[maxN];

int main(){
	int n,c;
	rii(n,c);
	FOR(i,0,n){
		int aux;
		ri(aux);
		arr.pb(aux);
	}
	sort(arr.begin(),arr.end());
	int need = 0;

	ROF(i,n-1,-1){
		if ( ready[i] )
			continue;

		need++;
		ready[i] = true;

		auto it = lower_bound(arr.begin(), arr.end(), c-arr[i]);
		while(it>=arr.begin()){
			if (*it <= c-arr[i] && !ready[it-arr.begin()]){
				ready[it-arr.begin()] = true;
				break;
			}
			it--;
		}
	}
	printf("%d\n", need);
	return 0;
}