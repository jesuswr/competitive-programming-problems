#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    
    int n,aux,lastCar;
    queue<int> cola;
    stack<int> pila;
    bool cond;

    scanf("%d",&n);
    
    while(n){
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&aux);
            cola.push(aux);
        }
        
        
        pila.push(cola.front());
        cola.pop();
        cond = true;
        lastCar = 0;

        while (cond && lastCar!=n){
            
            if (!cola.empty() && !pila.empty()){
                if (cola.front()==lastCar+1){
                    lastCar++;
                    cola.pop();
                }
                else if(pila.top()==lastCar+1){
                    lastCar++;
                    pila.pop();
                }
                else if(pila.top()>cola.front()){
                    pila.push(cola.front());
                    cola.pop();
                }
                else{
                    cond=0;
                }
            }
            else if(!cola.empty()){
                if (cola.front()==lastCar+1){
                    lastCar++;
                    cola.pop();
                }
                else{
                    pila.push(cola.front());
                    cola.pop();
                }

            }
            else{
                if(pila.top()==lastCar+1){
                    lastCar++;
                    pila.pop();
                }
                else{
                    cond=0;
                }
            }
        }

        if (cond==1){
            printf("yes\n");
        }
        else{
            printf("no\n");
            while(!pila.empty()){
                pila.pop();
            }
            while(!cola.empty()){
                cola.pop();
            }
        }
    scanf("%d",&n);
    }
}