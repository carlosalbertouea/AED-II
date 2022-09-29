#include <iostream>
#define MAX_NOS 4
#define INF 999999
using namespace std;
typedef struct arco{
    int origem;
    int destino;
    int peso;
}ARCO;
bool bellmanFord(int G[][MAX_NOS],int ordem,int s,int Custo[]){
    ARCO* a= new(ARCO[ordem*ordem]);
    int n_Arcos=0;
    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            if(G[i][j]){
                a[n_Arcos].origem=i;
                a[n_Arcos].destino=j;
                a[n_Arcos].peso = G[i][j];
                n_Arcos++;
            }
        }
    }
    for(int i=0;i<ordem;i++){
        Custo[i]=INF;
    }
    Custo[s]=0;
    bool trocou;
    for (int i=0;i<ordem;i++){
        trocou=false;
        for(int j=0;j<n_Arcos;j++){
            if(Custo[a[j].destino]>Custo[a[j].origem]+a[j].peso){
                Custo[a[j].destino]=Custo[a[j].origem]+a[j].peso;
                trocou=true;
            }
        }
        if(!trocou){
            break;
        }
    }
    for(int i=0;i<n_Arcos;i++){
        if(Custo[a[i].destino]>Custo[a[i].origem]+a[i].peso){
            return false;
        }
    }
    return true;
}
void imprimeGrafo(int vetor[],int t){
    cout<<"{";
    int i;
    for(i=0;i<t-1;i++){
        cout<<vetor[i]<<", ";
    }
    cout<<vetor[i]<< "}"<<endl;
}
int main(){
    int Custo1[MAX_NOS];
    int Custo2[MAX_NOS];
    bool grafo1;
    bool grafo2;
    int G[MAX_NOS][MAX_NOS]{
        {0, 100, 1, 0 },
        {100, 0, 0, 200},
        {1, 0, 0, 2},
        {0, 200, 2, 0},
    };
    int G2[MAX_NOS][MAX_NOS]{
        {0, 100, -1, 0 },
        {100, 0, 0, 200},
        {-1, 0, 0, 2},
        {0, 200, 2, 0},
    };
    grafo1=bellmanFord(G,MAX_NOS,0,Custo1);
    grafo2=bellmanFord(G2,MAX_NOS,0,Custo2);
    cout<<"Vetor Custo do grafo 1: ";
    imprimeGrafo(Custo1,MAX_NOS);
    if(!grafo1){
        cout<<"Existe ciclo negativo no grafo 1"<<endl;
    }
    else{
        cout<<"Nao existe ciclo negativo no grafo 1"<<endl;
    }
    cout<<"\n";
    cout<<"Vetor Custo do grafo 2: ";
    imprimeGrafo(Custo2, MAX_NOS);
    if(!grafo2){
        cout<<"Existe ciclo negativo no grafo 2"<<endl;
    }
    else{
        cout<<"Nao existe ciclo negativo no grafo 2"<<endl;
    }
    return 0;
}
