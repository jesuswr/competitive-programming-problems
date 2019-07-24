#include <iostream>
#include <string>
#include <set>
#include <cstring>

using namespace std;
char word[1001];
set<int> roots;


int getMask()
{
	int m = strlen(word);
	int a = 0;
	for (int i = 0; i < m; ++i)
	{
		a = a | (1<<(int)(word[i]-'a'));
	}
	return a;
}





int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", word);
		int aux = getMask();
		if (roots.find(aux)==roots.end()) roots.insert(aux);
	}
	int ans = roots.size();
	printf("%d\n", ans);
}