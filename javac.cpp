#include <iostream>
#include <string>

using namespace std;

bool java(string words){

    if (words[0]<='Z'){
        return false;
    }

    for(int i = 0; i < words.length(); i++)
    {
        if (words[i]=='_'){
            return false;
        }
    }    

    return true;
    
}

bool cWord(string words){

    if (words[0]=='_' || words[words.length()-1]=='_'){
        return false;
    }
    

    for(int i = 0; i < words.length(); i++)
    {
        if ((words[i]<'a') && words[i]!='_'){
            return false;
        }

        if (words[i]=='_' && words[i+1]=='_'){
            return false;
        }
    }

    return true;

}

void javaToC(string words){
    for(int i = 0; i < words.length(); i++)
    {
        if (words[i]<='Z'){
            words.insert(i,"_");
            words[i+1]=words[i+1] + 32;
        }
    }
    cout << words;
}

void cToJava(string words){
    for(int i = 0; i < words.length(); i++)
    {
        if (words[i]=='_'){
            words.erase(i,1);
            words[i]=words[i]-32;
        }
    }
    cout << words;
}


int main(){

    string word;
    while (getline(cin,word)){
        if (java(word)){
            javaToC(word);
            printf("\n");
        }
        else if (cWord(word))
        {
            cToJava(word);
            printf("\n");
        }
        else{
            printf("Error!");
            printf("\n");
        }
        
        
    }
}