#include <iostream>
using namespace std;
typedef struct grafo{
    int vertices;
    int arestas;
    int **adj;
}GRAFO;
GRAFO* criarGrafo(int v){
    GRAFO* grf=new(GRAFO);
    grf->vertices=v;
    grf->arestas=0;
    grf->adj=new int* [v];
    for(int i=0;i<v;i++){
         grf->adj[i]=new int [v];
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
             grf->adj[i][j]=0;
        }
    }
    return grf;
}
bool criarAresta(GRAFO* grf,int vi,int vf){
    if(!grf){
        return false;
    }
    if((vf<0)||(vf>=grf->vertices)){
        return false;
    }
    if((vi<0)||(vi>=grf->vertices)){
        return false;
    }
    if(grf->adj[vi][vf]==0){
        grf->adj[vi][vf]=1;
        grf->arestas++;
    }
    return true;
}
bool apagarAresta(GRAFO* grf,int vi,int vf){
    if(!grf){
        return false;
    }
    if((vf<0)||(vf>=grf->vertices)){
        return false;
    }
    if((vi<0)||(vi>=grf->vertices)){
        return false;
    }
    if(grf->adj[vi][vf]==1){
        grf->adj[vi][vf]=0;
        grf->arestas--;
    }
    return true;
}
void imprimirGrafo(GRAFO* grf){
    for(int i=0;i<grf->vertices;i++){
        cout<<endl<<"Vertice: "<<i<<": ";
        for(int j=0;j<grf->vertices;j++){
            cout<<" "<<grf->adj[i][j];
        }
    }
}
void imprimirArestas(GRAFO* grf){
    for(int i=0;i<grf->vertices;i++){
        for(int j=0;j<grf->vertices;j++){
            if(grf->adj){
                cout<<"("<<i<<","<<j<<")";
            }
        }
    }
}
int main(){
    GRAFO* grf=criarGrafo(5);
    imprimirGrafo(grf);
    cout<<endl;
    criarAresta(grf,1,0);
    criarAresta(grf,1,2);
    criarAresta(grf,2,0);
    criarAresta(grf,2,4);
    criarAresta(grf,3,1);
    criarAresta(grf,4,3);
    imprimirGrafo(grf);
    cout<<endl;
    apagarAresta(grf,3,1);
    imprimirGrafo(grf);
    cout<<"\nArestas"<<endl;
    imprimirArestas(grf);
    return 0;
}
