#include <iostream>
using namespace std;
void iniciaLista(int lista[],int n){
    for(int i=0;i<n;i++){
        lista[i]=-1;
    }
}
void mostrarLista(int lista[],int n){
    for(int i=0;i<n;i++){
        cout<<lista[i];
    }
    printf("\n");
}
bool valido(int solucao[],int c){
    for(int i=0;i<=c-1;i++){
        if((solucao[i]==solucao[c])||(abs(solucao[i]-solucao[c])==abs(i-c))){
            return false;
        }
    }
    return true;
}
bool rainhas(int solucao[],int j,int n){
    bool sucesso;
    mostrarLista(solucao,n);
    if(j>n-1){
        return false;
    }
    sucesso=false;
    solucao[j]=-1;
    while((!sucesso)&&(solucao[j]<n-1)){
        solucao[j]=solucao[j]+1;
        if(valido(solucao,j)){
            if(j!=n-1){
                sucesso=rainhas(solucao,j+1,n);
            }
            else{
                sucesso=true;
            }
        }
    }
    return sucesso;
}
int main(){
    int n;
    cout<<"Digite o valor de n:"<<endl;
    scanf("%d",&n);
    int prainhas[n];
    iniciaLista(prainhas,n);
    mostrarLista(prainhas,n);
    rainhas(prainhas,0,n);
    cout<<"solucao:"<<endl;
    mostrarLista(prainhas,n);
    return 0;
}
