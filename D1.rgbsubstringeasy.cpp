#include <iostream>
#include <string>

using namespace std;

char word[int(2e5+5)];

int getMinMoves(int ind, int size, char start)
{
	char aux = start;
	int count = 0;
	if (aux!=word[ind]) count++;
	for (int i = ind+1; i < ind+size; ++i)
	{
		if (aux=='R')
		{
			if (word[i]!='G')
			{
				count++;
			}
			aux = 'G';
		}
		else if(aux=='G')
		{
			if (word[i]!='B')
			{
				count++;
			}
			aux = 'B';
		}
		else if(aux=='B')
		{
			if (word[i]!='R')
			{
				count++;
			}
			aux = 'R';
		}
	}
	return count;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) 
	{
	    int n,k;
	    scanf("%d %d", &n, &k);
	    
	    scanf("%s", word);
	    if (k==1)
	    {
	    	
	    	printf("0\n");
	    	continue;
	    }
	    
	    int minm = 10000000;
	    for (int i = 0; i < n-k+1; ++i)
	    {
	    	minm = min(minm, getMinMoves(i,k,'R'));
	    	minm = min(minm, getMinMoves(i,k,'G'));
	    	minm = min(minm, getMinMoves(i,k,'B'));
	    	if (minm==0)
	    	{
	    		break;
	    	}
	    }
	    
	    printf("%d\n", minm);
	}
}