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
int place, my_score, min_score;

bool chck(int x){
	int i = (x/50)%475;
	FOR(k,0,25){
		i = (i*96 + 42) % 475;
		if ( i+26 == place )
			return true;
	}
	return false;
}

int main(){
	riii(place,my_score,min_score);
	int aux = my_score;
	if ( chck(aux) ){
		printf("0\n");
		return 0;
	}
	while( aux - 50 >= min_score ){
		aux -= 50;
		if ( chck(aux) ){
			printf("0\n");
			return 0;
		}
	}
	aux = my_score;
	int add = 1;
	while(1){
		if ( chck( my_score + add*100 ) || chck( my_score + add*100 - 50 ) ){
			printf("%d\n",add);
			return 0;
		}
		add++;
	}
	return 0;
}