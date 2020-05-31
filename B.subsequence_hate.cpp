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

// GJNM
char S[maxN];

int BIT[maxN];
// suma de rangos [0,n-1]
void updBIT(int p, int val){ 
    p++;	// esto es porque el bit esta indexado desde 1
    for(; p < maxN; p += p&-p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
    	BIT[p] += val;
}
int sumBIT(int p){
    p++;
    int ret = 0;
    for(; p; p -= p&-p) 
    	ret += BIT[p];
    return ret;
}

int main(){
	int t;
	ri(t);
	while(t--){
		FOR(i,0,maxN)
			BIT[i] = 0;
		scanf("%s", S);
		int n = strlen(S);
		FOR(i,0,n)
			updBIT(i,S[i]-'0');
		
		int ans = INF;
		FOR(i,0,n){
			int left = i+1-sumBIT(i);
			int right = sumBIT(n) - sumBIT(i);
			ans = min(ans, left+right);
		}

		FOR(i,0,n){
			int left = sumBIT(i);
			int right = n-i-1 - (sumBIT(n)-sumBIT(i));
			ans = min(ans, left+right);
		}

		int z = 0;
		int o = 0;
		FOR(i,0,n){
			z += abs(S[i]-'0');
			o += abs(S[i]-'1');
		}
		ans = min(ans, min(z,o));
		printf("%d\n", ans);



	}
	return 0;
}