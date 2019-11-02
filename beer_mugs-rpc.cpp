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
const int maxN = 1e5; // CAMBIAR ESTE
const int maxS = 1 << 20;

// GJNM
char w[3*maxN + 5];
pii arr[maxS];

int main()
{
	FOR(i,0,maxS){
		arr[i].F = INF;
		arr[i].S = -2;
	}
	int n;
	ri(n);
	scanf("%s",w);
	int aux = 0;
	arr[0].F = 0;
	FOR(i,0,n){
		aux = aux ^ ( 1<<(int)(w[i]-'a'));
		arr[aux].F = min(arr[aux].F,i);
		arr[aux].S = max(arr[aux].S,i);
	}
	int ans = 1;
	if ( arr[0].S != INF){
		ans = max(ans,arr[0].S-arr[0].F+1);
	}
	FOR(i,0,maxS){
		if ( arr[i].S != -1 ){			
				ans = max( ans , arr[i].S - arr[i].F );
				FOR(j,0,20){
					if (i&(1<<j)){
						if ( arr[i - (1<<j)].F != -1){
							if (i - (1<<j) == 0)ans = max( ans , max(arr[i].S - arr[i - (1<<j)].F+1,arr[i - (1<<j)].S-arr[i].F+1));
							else ans = max( ans , max(arr[i].S - arr[i - (1<<j)].F,arr[i - (1<<j)].S-arr[i].F));
						}
					}
				
			}
		} 
	}
	printf("%d\n", ans);
	return 0;
}