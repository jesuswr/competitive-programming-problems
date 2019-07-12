#include <iostream>
#include <vector>
#include <queue>



using namespace std;

queue<long long> specialNumbers;

int main()
{
	int m;
	long long n,k;
	long long aux;
	scanf("%lld %d %lld",&n,&m,&k);
	for (int i = 0; i < m; ++i)
	{
		scanf("%lld",&aux);
		specialNumbers.push(aux);
	}
	long long startRange;
	long long endRange;
	int deletedElements = 0;
	int deletedElements2 = 0;
	int moves = 0;
	while(!specialNumbers.empty()) {
	    aux = specialNumbers.front() - deletedElements;
	    
	    if (aux%k==0)
	    {
	    	startRange = (long long)aux - k +1 ;
	    	endRange = (long long)aux;
	    }
	    else
	    {
	    	startRange = (long long)k*(aux/k)+1;
	    	endRange = (long long)startRange +k-1;
	    }
	    deletedElements2=0;
	    while(specialNumbers.front()-deletedElements>= startRange && specialNumbers.front()-deletedElements<= endRange) {
	        specialNumbers.pop();
	        deletedElements2++;
	    }
	    deletedElements += deletedElements2;
	    moves++;
	}
	printf("%d\n", moves);
}