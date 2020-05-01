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
int arr[101];

int main(){
	int t;
	ri(t);
	while(t--){
		int n,k;
		rii(n,k);
		set<int> unq;
		FOR(i,0,n){
			ri(arr[i]);
			unq.insert(arr[i]);
		}
		if ( unq.size()>k){
			printf("-1\n");
			continue;
		}
		printf("%d\n", n*k);
		FOR(i,0,n){
			for(int x : unq)
				printf("%d ",x );
			int j = unq.size();
			while(j<k){
				printf("1 ");
				j++;
			}
		}
		printf("\n");
	}
	return 0;
}