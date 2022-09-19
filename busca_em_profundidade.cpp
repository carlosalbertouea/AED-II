#include <iostream>
using namespace std;
typedef struct grafo{
    int vertices;
    int arestas;
    int **adj;
}GRAFO;
typedef struct ax{
    int vertice;
    ax *prox;
}ELEMENTO;
typedef struct{
    ELEMENTO* topo;
}PILHA;
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
void busca_dfs_recursiva(GRAFO* grf,int no,bool v[],int t){
    v[no]=true;
    cout<<"No "<<no+1<<" visitado"<<endl;
    int pilha=no;
    for(int j=0; j<t;j++){
        if((grf->adj[pilha][j]!=0)&&(v[j]==false)){
            dfs_busca_recursiva(grf,j,v,t);
        }
    }
    cout<<"Terminou com o no "<<no+1<<endl;
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
void iniciaPilha(PILHA* p){
    p->topo=NULL;
}
int tamanhoPilha(PILHA* p){
    int t=0;
    ELEMENTO* i=p->topo;
    while(i!=NULL){
        t++;
        i=i->prox;
    }
    return t;
}
bool inserirVertice(PILHA* p, int v){
    ELEMENTO* i;
    i=new ELEMENTO;
    i->vertice=v;
    i->prox=p->topo;
    p->topo=i;
    return true;
}
bool excluirVertice(PILHA* p){
    if(p->topo==NULL){
        return false;
    }
    ELEMENTO* i=p->topo;
    p->topo=p->topo->prox;
    delete(i);
    return true;
}
int main(){
    int t=5;
    int arvores=0;
    GRAFO* grf=criarGrafo(t);
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
    bool visitados[t];
    for(int i=0;i<t;i++){
        visitados[i]=false;
    }
    for(int i=0;i<t;i++){
        if(visitados[i]==false){
            dfs_busca_recursiva(grf,i,visitados,t);
            arvores++;
        }
        i++;
    }
    cout<<"Arvores: "<<arvores<<endl;
    return 0;
}
