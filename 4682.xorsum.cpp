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
#define pb push_back

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM

vector<vi> trie;

void add_node()
{
	trie.pb(vector<int>(2,-1));
}

void ins( int num )
{
	int ind = 0;
	int l;
	for (int i = 31; i >= 0; --i)
	{
		l = ( num & ( 1 << i ) ) >= 1;
		if ( trie[ind][l] == -1 )
		{
			trie[ind][l] = trie.size();
			add_node();
		}
		ind = trie[ind][l];
	}
}

int sear( int num )
{
	int ind = 0, ret = 0;
	int l;
	for (int i = 31; i >= 0; --i)
	{
		l = ( num & ( 1 << i ) ) >= 1;
		l = 1 - l;
		if ( trie[ind][l] == -1 )
		{
			ind = trie[ind][1-l];
		}
		else
		{
			ret = ret ^ ( 1 << i );
			ind = trie[ind][l];
		}
	}
	return ret;
}

int main()
{
	int t;
	ri(t);
	int n;
	while(t--) 
	{
		trie.clear();
	    ri(n);
	    int aux;
	    int mx = 0;
	    int curr = 0;
	    add_node();
	    ins(0);
	    for (int i = 0; i < n; ++i)
	    {
	    	ri(aux);
	    	curr = curr ^ aux;
	    	ins(curr);
	    	mx = max( mx , sear(curr) );
	    }
	    printf("%d\n",mx);	   	
	}
}