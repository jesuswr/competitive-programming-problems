#include <iostream>
#include <string>
#include <cstring>


using namespace std;

char word1[int(1e6)+1];
char word2[int(1e6)+1];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) 
	{
	    scanf("%s", word1);
	    scanf("%s", word2);
	    bool ans = true;
	    int size1 = strlen(word1);
	    int size2 = strlen(word2);
	    if (size2<size1 || word1[0]!=word2[0])
	    {
	    	ans = false;
	    }
	    else
	    {
	    	int i = 0, j = 0;

	    	while(i < size1 && j < size2) 
	    	{
	    	    if (word1[i] == word2[j]){i++; j++;}
	    	    else if (word1[i-1]!=word2[j]){ans = false; break;}
	    	    else j++;
	    	}
	    	if (ans)
	    	{
	    		for (int k = j; k < size2; ++k)
	    		{
	    			//printf("%c %c\n", word2[k], word1[i-1]);
	    			if (word2[k] != word1[i-1]) {ans = false; break;}
	    		}
	    	}
	    	if (i<size1) ans = false;
	    }
	    if (ans) printf("YES\n");
	    else printf("NO\n");
	}
}
