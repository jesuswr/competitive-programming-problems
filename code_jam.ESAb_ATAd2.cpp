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
const int maxN = 1005; // CAMBIAR ESTE

// GJNM
char s[maxN];
int t, n, queryN;
int lft, rght;
pii dif, same;

void rev(){
	int l = 0, r = n-1;
	while( l < r ){
		swap(s[l], s[r]);
		l++;
		r--;
	}
}

void swp(){
	FOR(i,0,n){
		if ( s[i] == '1' )
			s[i] = '0';
		else
			s[i] = '1';
	}
}

int query_begin(){
	printf("%d\n", lft);
	fflush(stdout);
	cin >> s[lft-1];
	lft++;
	queryN++;
	return lft-2;
}

int query_end(){
	printf("%d\n", rght);
	fflush(stdout);
	cin >> s[rght-1];
	rght--;
	queryN++;
	return rght;
}

void waste_query(){
	printf("%d\n", 1);
	fflush(stdout);
	char aux;
	cin >> aux;
	queryN++;
}

void check_change(){
	if ( dif.f != -1 && same.f != -1){
		int ind1, ind2;
		if ( s[dif.f] == s[same.f] ){
			ind1 = dif.f;
			ind2 = same.f;
		}
		else{
			ind1 = dif.s;
			ind2 = same.s;
		}

		printf("%d\n", ind1+1);
		fflush(stdout);
		char aux1;
		cin >> aux1;

		printf("%d\n", ind2+1);
		fflush(stdout);
		char aux2;
		cin >> aux2;

		queryN += 2;

		if ( s[ind1] == s[ind2] ){
			if ( aux2 == aux1 && aux2 == s[ind2] )
				return;
			if ( aux2 == aux1 && aux2 != s[ind2] )
				swp();
			else if ( aux2 != aux1 ){
				if ( aux2 != s[ind2] )
					swp();
				rev();
			}
		}
	}
	else if ( dif.f != -1 ){
		int ind = dif.f;
		printf("%d\n", ind+1);
		fflush(stdout);
		char aux;
		cin >> aux;
		queryN++;
		if ( aux != s[ind] )
			rev();
	}
	else if ( same.f != -1 ){
		int ind = same.f;
		printf("%d\n", ind+1);
		fflush(stdout);
		char aux;
		cin >> aux;
		queryN++;
		if ( aux != s[ind] )
			swp();
	}
}

int main(){
	rii(t,n);
	while(t--){
		queryN = 1;
		lft = 1;
		rght = n;
		dif.f = -1;
		same.f = -1;
		for (int i = 0; i < n; i += 2){
			int l,r;

			if ( queryN%10 == 1 )
				check_change();
			
			if ( queryN%10 == 2 && queryN > 2)
				waste_query();
			
			l = query_begin();
			
			r = query_end();

			

			if ( s[l] == s[r] )
				same = {l, r};
			else
				dif = {l, r};
		}

		s[n] = '\0';
		printf("%s\n", s);

		char x;
		cin >> x;
		if ( x == 'N' )
			return 0;
	}

	return 0;
}