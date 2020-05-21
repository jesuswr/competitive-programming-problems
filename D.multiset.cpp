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
const int maxN = 1e6+10; // CAMBIAR ESTE

// GJNM
int n,q;
ll A[maxN];

ll BIT[maxN];
void updBIT(int p, ll val){ 
    for(; p < maxN; p += p&-p) 
    	BIT[p] += val;
}
ll sumBIT(int p){
    ll ret = 0;
    for(; p; p -= p&-p) 
    	ret += BIT[p];
    return ret;
}

void ins(int p){
	updBIT(p,1);
	A[p]++;
}

int bit_search(int v){
	int sum = 0;
	int pos = 0;
	
	for(int i=20; i>=0; i--){
		if(pos + (1 << i) < maxN and sum + BIT[pos + (1 << i)] < v){
			sum += BIT[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
}

void del(int k){
	int ans = bit_search(k);
	updBIT(ans,-1);
	A[ans]--;
}



int main(){
	rii(n,q);
	FOR(i,0,n){
		int aux;
		ri(aux);
		A[aux]++;
		updBIT(aux,1);
	}
	FOR(i,0,q){
		int aux;
		ri(aux);
		if ( aux > 0 ){
			ins(aux);
		}
		else{
			del(-aux);
		}
	}
	FOR(i,1,1e6+1){
		if ( A[i] ){
			printf("%d\n",i );
			return 0;
		}
	}
	printf("0\n");
	return 0;
}