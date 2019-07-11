#include <string>
#include <iostream>
#include <queue>
#include <map>

using namespace std;


int n,m;
string s;

map<string,bool> visited;

void bfs(string str)
{
	queue<string> q;
	q.push(str);

	string aux, aux2;
	int cont=0, price=0;
	visited[aux] = 1;
	while( !q.empty() && cont<m) 
	{
		aux = q.front();
		q.pop();
		cont++;
		price = price + n - aux.size();

		//cout << aux<<endl;

		for (int i = 0; i < aux.size(); ++i)
		{

			aux2 = aux.substr(0,i)+aux.substr(i+1,aux.size());
			if ( !visited[aux2] ) 
			{
				q.push(aux2);
				visited[aux2] = 1;
			}
		}

	}
	if (cont<m-1)
	{
		printf("-1\n");
		return;
	}
	if (cont == m-1)
	{
		price += n;
	}
	printf("%d\n",price );
}





int main()
{
	scanf("%d %d",&n,&m);
	cin>>s;
	bfs(s);
}
