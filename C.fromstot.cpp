#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;
int let[26];
char s[101],s1[101],s2[101];
unordered_map<char,int> mp;
int j,k;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
	    
	    cin>>s;
	    cin>>s1;
		cin>>s2;
		if (strlen(s)>strlen(s1))
		{
			printf("NO\n");
			continue;
		}
		for (int i = 0; i<strlen(s2);i++){
			if (mp.find(s2[i])==mp.end()) mp[s2[i]] = 1;
			else mp[s2[i]]++;
			
		}
		bool cond = true;
		j=0;
		k=0;
		while(k<strlen(s1) && cond) {
		    if (s[j]==s1[k] && j<strlen(s)){
		    	j++;
		    	k++;
		    	
		    }
		    else
		    {
		    	
		    	if (mp.find(s1[k])==mp.end()) {cond = false;}
		    	else if(mp[s1[k]]<=0) {cond = false;}
		    	else if(mp[s1[k]]>0) {mp[s1[k]]--;k++;}
		    }
		}
		if (j<strlen(s)) cond = false;
	    if (cond) printf("YES\n");
	    else printf("NO\n");
		mp.clear();

	}
}
