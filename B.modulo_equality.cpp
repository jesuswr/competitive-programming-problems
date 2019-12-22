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
map<ll,ll> mp;
map<ll,ll> mp2;
ll a[2005];
set<ll> st;

int main()
{
	int n, m;
	ll aux;
	rii(n,m);
	ll mn = LLINF;
	FOR(i,0,n){
		rl(a[i]);
		mn = min( mn , a[i] );
	}
	FOR(i,0,n){
		rl(aux);
		if ( mp.find(aux) != mp.end() ){
			mp[aux]++;
		}
		else{
			mp[aux] = 1;
		}
	}
	for( auto p : mp ){
		if ( p.f >= mn ) st.insert( p.f-mn );
		else st.insert(m-mn+p.f);
	}
	while( true ){
		bool cond;
		for( auto sum : st){
			mp2.clear();
			cond = true;
			FOR(i,0,n){
				if ( mp2.find(( a[i] + sum )% m ) != mp2.end() ){
					mp2[(a[i] + sum )% m]++;
				}
				else{
					mp2[(a[i] + sum )% m] = 1;
				}
				if ( mp.find((a[i] + sum )% m) == mp.end() ){
					cond = false;
				}
				else if ( mp[(a[i] + sum )% m] < mp2[(a[i] + sum )% m] ){
					cond = false;
				}
				if (!cond ) break;
			}
			if ( cond ){
				printf("%lld\n", sum);
				return 0;
			}

		}
	}


	return 0;
}