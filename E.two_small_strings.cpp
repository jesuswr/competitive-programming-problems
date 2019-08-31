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

#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);
#define rl(a) scanf("%lld", &a);
#define rll(a,b) scanf("%lld %lld", &a, &b);

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
char st1[3] = {'a','b','c'};
char st2[3] = {'b','c','a'};
char st3[3] = {'c','a','b'}; 
char st4[3] = {'b','a','c'};
char st5[3] = {'c','b','a'};
char st6[3] = {'a','c','b'};

char w1[3];
char w2[3];

int n;
unordered_map<char,int> mp;

bool check( char st[3] )
{
	if ( w1[0] == st[0] && w1[1] == st[1] ) return false;
	if ( w1[0] == st[1] && w1[1] == st[2] ) return false;
	if ( w2[0] == st[0] && w2[1] == st[1] ) return false;
	if ( w2[0] == st[1] && w2[1] == st[2] ) return false;
	return true;

}

void syscallalgo( char st[3] )
{
	printf("YES\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%c", st[0]);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%c", st[1]);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%c", st[2]);
	}
	printf("\n");
}

void syscallalgo2( char st[3] )
{
	printf("YES\n");
	for (int i = 0; i < 3*n; ++i)
	{
		printf("%c", st[i%3]);
	}
	printf("\n");
}

int main()
{
	n;
	ri(n);
	scanf("%s",w1);
	scanf("%s",w2);
	if ( w1[0] == w1[1] || w2[0] == w2[1])
	{
		if ( w1[0] == w1[1] && w2[0] == w2[1])
		{
			if (w1[0]!=w2[0])
			{
				st1[0]=w1[0];
				st1[1]=w2[0];
				mp[st1[0]] = true;
				mp[st1[1]] = true;
				if (mp.find('a')==mp.end())
				{
					st1[2] = 'a';
				}
				else if (mp.find('b')==mp.end())
				{
					st1[2] = 'b';
				}
				else  st1[2] ='c';
				syscallalgo2(st1);
				return 0;
			}
			if (w1[0] == w2[0])
			{
				mp[w1[0]] = true;
			}
			if ( mp.find('a') == mp.end())
			{
				st1[0] = 'a';
				mp['a'] = true;
			}
			else if ( mp.find('b') == mp.end())
			{
				st1[0] = 'b';
				mp['b'] = true;
			}
			else
			{
				st1[0] = 'c';
				mp['c'] = true;
			}
			st1[1] = w1[0];
			if ( mp.find('a') == mp.end())
			{
				st1[2] = 'a';
				mp['a'] = true;
			}
			else if ( mp.find('b') == mp.end())
			{
				st1[2] = 'b';
				mp['b'] = true;
			}
			else
			{
				st1[2] = 'c';
				mp['c'] = true;
			}
			syscallalgo2(st1);
			return 0;
		}
		else if ( w1[0] == w1[1] )
		{
			st1[1] = w1[0];
			if (w2[0] == w1[0])
			{
				st1[0] = w2[1];
				mp[w2[1]] = true;
				mp[w1[0]] = true;
				if (mp.find('a') == mp.end())
				{
					st1[2] = 'a';
				}
				else if ( mp.find('b') == mp.end())
				{
					st1[2] = 'b';
				}
				else st1[2] = 'c';
			}
			else if ( w2[1] == w1[0])
			{
				st1[2] = w2[0];
				mp[w2[0]] = true;
				mp[w1[0]] = true;
				if (mp.find('a') == mp.end())
				{
					st1[0] = 'a';
				}
				else if ( mp.find('b') == mp.end())
				{
					st1[0] = 'b';
				}
				else st1[0] = 'c';
			}
			else
			{
				st1[0] = w2[0];
				st1[2] = w2[1];
			}
			syscallalgo2(st1);
			return 0;
		}
		else
		{
			char aux1, aux2;
			aux1 = w1[0];
			aux2 = w1[1];
			w1[0] = w2[0];
			w1[1] = w1[1];
			w2[0] = aux1;
			w2[1] = aux2;

			st1[1] = w1[0];
			if (w2[0] == w1[0])
			{
				st1[0] = w2[1];
				mp[w2[1]] = true;
				mp[w1[0]] = true;
				if (mp.find('a') == mp.end())
				{
					st1[2] = 'a';
				}
				else if ( mp.find('b') == mp.end())
				{
					st1[2] = 'b';
				}
				else st1[2] = 'c';
			}
			else if ( w2[1] == w1[0])
			{
				st1[2] = w2[0];
				mp[w2[0]] = true;
				mp[w1[0]] = true;
				if (mp.find('a') == mp.end())
				{
					st1[0] = 'a';
				}
				else if ( mp.find('b') == mp.end())
				{
					st1[0] = 'b';
				}
				else st1[0] = 'c';
			}
			else
			{
				st1[0] = w2[0];
				st1[2] = w2[1];
			}
			syscallalgo2(st1);
			return 0;
		}
	}
	if ( check(st1))
	{
		syscallalgo(st1);
		return 0;
	}
	if ( check(st2))
	{
		syscallalgo(st2);
		return 0;
	}
	if ( check(st3))
	{
		syscallalgo(st3);
		return 0;
	}
	if ( check(st4))
	{
		syscallalgo(st4);
		return 0;
	}
	if ( check(st5))
	{
		syscallalgo(st5);
		return 0;
	}
	if ( check(st6))
	{
		syscallalgo(st6);
		return 0;
	}
	printf("NO\n");
	return 0;
}