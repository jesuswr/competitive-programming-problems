#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) 
	{
	    int w, b;
	    scanf("%d %d", &b , &w );
	    int mini, maxi;
	    int aux, aux2;
	    mini = min(w,b);
	    maxi = max(w,b);
	    if (maxi > 3*mini+1)
	    {
	    	printf("NO\n");
	    }
	    else
	    {
	    	printf("YES\n");
	    	if (mini==w)
	    	{
	    		for (int i = 0; i < w; ++i)
	    		{
	    			printf("2 %d\n", 2*(i+1));
	    		}
	    		for (int i = 0; i < w; ++i)
	    		{
	    			printf("2 %d\n", 2*(i+1)+1);
	    		}
	    		aux = b - w;
	    		if (aux!=0)
	    		{
	    			printf("2 1\n");
	    			aux--;
	    		}
	    		for (int i = 0; i < w; ++i)
	    		{
	    			if (aux == 0) break;
	    			printf("3 %d\n", 2*(i+1));
	    			aux--;
	    		}
	    		for (int i = 0; i < w; ++i)
	    		{
	    			if (aux == 0) break;
	    			printf("1 %d\n", 2*(i+1));
	    			aux--;
	    		}
	    	}
	    	else if (mini==b)
	    	{
	    		for (int i = 0; i < b; ++i)
	    		{
	    			printf("2 %d\n", 2*(i+1)+1);
	    		}
	    		for (int i = 0; i < b; ++i)
	    		{
	    			printf("2 %d\n", 2*(i+1));
	    		}
	    		aux = w-b;
	    		if (aux!=0)
	    		{
	    			printf("2 %d\n", 2*(b+1));
	    			aux--;
	    		}
	    		for (int i = 0; i < b; ++i)
	    		{
	    			if (aux == 0) break;
	    			printf("3 %d\n", 2*(i+1)+1);
	    			aux--;
	    		}
	    		for (int i = 0; i < b; ++i)
	    		{
	    			if (aux == 0) break;
	    			printf("1 %d\n", 2*(i+1)+1);
	    			aux--;
	    		}
	    	}
	    }
	}
}
