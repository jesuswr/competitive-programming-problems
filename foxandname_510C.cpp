#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>
#include <cstring>


using namespace std;


char word[100][100];
int n;
vector <int> graph[26];
bool ans;


void checkWord (int i, int j)
{
	int sizeI = strlen(word[i]);
	int sizeJ = strlen(word[j]);
	int minimun = min (sizeI, sizeJ);
	for (int k = 0; k < minimun; ++k)
	{
		if (word[i][k] == word[j][k]) continue;
		graph[word[i][k] - 97].push_back(word[j][k]-97);
		return;
	}
	if (sizeI > sizeJ) ans = false;

}

bool visited[26];
int order[26];
int aux = 25;

void getTopOrder(int x)
{
	visited[x] = true;

	for (int y: graph[x])
	{
		if (!visited[y]) getTopOrder(y);
		if (visited[y] && order[y]==-1) ans = false;
		if (ans == false) return;
	}
	order[x] = aux;
	aux --;
}




int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",word[i]);
	}
	ans = true;
	for (int i = 1; i < n; ++i)
	{
		checkWord(i-1,i);
		if (!ans) break;
	}

	for (int i = 0; i<26;i++) order[i] = -1;

	if (ans)
	{
		for (int i = 0; i<26;i++)
		{
			if (!visited[25-i]) getTopOrder(25-i);
			if (ans == false) break;
		}
	}
	if (ans)
	{
		char printThis[26];
		for (int i = 0; i < 26; ++i)
		{
			printThis[order[i]] = (char)(97+i);
		}
		for (int i = 0; i < 26; ++i)
		{
			printf("%c", printThis[i]);
		}
		printf("\n");

	}
	else printf("Impossible\n");
	
}