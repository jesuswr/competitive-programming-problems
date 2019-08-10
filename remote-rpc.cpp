#include <iostream>

using namespace std;

bool arr[10];

bool check(int c)
{
	int aux = c;
	if (aux == 0)
	{
		return !arr[0];
	}
	while( aux>0 ) 
	{
	    if (arr[aux%10])
	    {
	    	return false;
	    }
	    aux = aux/10;
	}
	return true;
}

int abs(int x)
{
	if ( x >= 0 ) return x;
	return -x;
}

int main()
{
	int n;
	scanf("%d", &n);
	int aux;
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &aux);	
		arr[aux] = true;
	}
	int chann;
	scanf("%d", &chann);
	int currentChann = chann;
	int currentChann2 = chann;
	int objChann;
	while(true) 
	{
		
	    if (currentChann<1000 && check(currentChann))
	    {
	    	objChann = currentChann;
	    	break;
	    }
	    if (currentChann2>=0 && check(currentChann2))
	    {
	    	objChann = currentChann2;
	    	break;
	    }
	    currentChann++;
	    currentChann2--;

	}
	int ans = abs(chann-objChann);
	printf("%d\n", ans);

}
