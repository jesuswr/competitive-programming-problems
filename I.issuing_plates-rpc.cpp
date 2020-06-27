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
set<string> BAD;

int main(){
	int words, plaques;
	rii(words, plaques);
	FOR(i,0,words){
		string s;
		cin >> s;
		BAD.insert(s);
	}
	FOR(i,0,plaques){
		string s;
		cin >> s;
		int n = s.size();
		FOR(i,0,n){
			if ( s[i] == '0' )
				s[i] = 'O';
			if ( s[i] == '1' )
				s[i] = 'L';
			if ( s[i]== '2' )
				s[i] = 'Z';
			if ( s[i] == '3' )
				s[i] = 'E';
			if ( s[i] == '5' )
				s[i] = 'S';
			if ( s[i] == '6' )
				s[i] = 'B';
			if ( s[i] == '7' )
				s[i] = 'T';
			if ( s[i] == '8' )
				s[i] = 'B';
		}
		bool valid = true;
		for(auto z : BAD){
			if ( s.find(z) != string::npos ){
				valid = false;
				break;
			}
		}
		if ( valid )
			printf("VALID\n");
		else
			printf("INVALID\n");
	}
	return 0;
}