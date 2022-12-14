#include <iostream>
using namespace std;
typedef struct adjacencia{
    int vertice;
    int peso;
    struct adjacencia *prox;
}ADJACENCIA;
typedef struct adjacenciasp{
    int vertice;
    struct adjacenciasp *prox;
}ADJACENCIASP;
typedef struct vertice{
    ADJACENCIA *cad;
    ADJACENCIASP *cadsp;
}VERTICE;
typedef struct grafo{
    int vertices;
    int arestas;
    VERTICE *vrtc;
}GRAFO;
GRAFO* criarGrafo(int v){
    GRAFO* grf=new(GRAFO);
    grf->vertices=v;
    grf->arestas=0;
    grf->vrtc=new VERTICE[v];
    for(int i=0;i<v;i++){
        grf->vrtc[i].cad=NULL;
    }
    return grf;
}
ADJACENCIA* criarAdjacencia(int v, int peso){
    ADJACENCIA* tmp=new(ADJACENCIA);
    tmp->vertice=v;
    tmp->peso=peso;
    tmp->prox=NULL;
    return tmp;
}
ADJACENCIASP* criarAdjacenciasp(int v){
    ADJACENCIASP* tmp=new(ADJACENCIASP);
    tmp->vertice=v;
    tmp->prox=NULL;
    return tmp;
}
bool criarArestaDirP(GRAFO* grf,int vi,int vf,int p){
    if(!grf){
        return false;
    }
    if((vf<0)||(vf>=grf->vertices)){
        return false;
    }
    if((vi<0)||(vi>=grf->vertices)){
        return false;
    }
    ADJACENCIA* novo=criarAdjacencia(vf,p);
    novo->prox=grf->vrtc[vi].cad;
    grf->vrtc[vi].cad=novo;
    grf->arestas++;
    return true;
}
bool criarArestaNDirP(GRAFO* grf,int vi,int vf,int p){
    if(!grf){
        return false;
    }
    if((vf<0)||(vf>=grf->vertices)){
        return false;
    }
    if((vi<0)||(vi>=grf->vertices)){
        return false;
    }
    ADJACENCIA* n1=criarAdjacencia(vf,p);
    n1->prox=grf->vrtc[vi].cad;
    grf->vrtc[vi].cad=n1;
    ADJACENCIA* n2=criarAdjacencia(vf,p);
    n2->prox=grf->vrtc[vi].cad;
    grf->vrtc[vi].cad=n2;
    grf->arestas++;
    return true;
}
bool criarArestaDirSP(GRAFO* grf,int vi,int vf){
    if(!grf){
        return false;
    }
    if((vf<0)||(vf>=grf->vertices)){
        return false;
    }
    if((vi<0)||(vi>=grf->vertices)){
        return false;
    }
    ADJACENCIASP* novo=criarAdjacenciasp(vf);
    novo->prox=grf->vrtc[vi].cadsp;
    grf->vrtc[vi].cadsp=novo;
    grf->arestas++;
    return true;
}
bool criarArestaNDirSP(GRAFO* grf,int vi,int vf){
    if(!grf){
        return false;
    }
    if((vf<0)||(vf>=grf->vertices)){
        return false;
    }
    if((vi<0)||(vi>=grf->vertices)){
        return false;
    }
    ADJACENCIASP* n1=criarAdjacenciasp(vf);
    n1->prox=grf->vrtc[vi].cadsp;
    grf->vrtc[vi].cadsp=n1;
    ADJACENCIASP* n2=criarAdjacenciasp(vf);
    n2->prox=grf->vrtc[vi].cadsp;
    grf->vrtc[vi].cadsp=n2;
    grf->arestas++;
    return true;
}
int grauNo(GRAFO* grf,int no){
    int i=no-1,c=0;
    ADJACENCIA* adj=grf->vrtc[i].cad;
    while(adj){
        c++;
        adj=adj->prox;
    }
    return c;
}
int grauNoEntrada(GRAFO* grf,int no){
    int j=no-1,c=0;
    for(int i=0;i<grf->vertices;i++){
        ADJACENCIA* adj=grf->vrtc[i].cad;
        while(adj){
            if(adj->vertice==j){
                c++;
            }
            adj=adj->prox;
        }
    }
    return c;
}
bool existeAresta(GRAFO* grf,int vi,int vf){
    ADJACENCIA* adj=grf->vrtc[vi].cad;
    while(adj){
        if(adj->vertice==vf){
            return true;
        }
        adj=adj->prox;
    }
    return false;
}
void imprimirP(GRAFO* grf){
    cout<<"Vertices: "<<grf->vertices<<"\tArestas: "<<grf->arestas<<endl;
    for(int i=0;i<grf->vertices;i++){
        cout<<"v"<<i<<": ";
        ADJACENCIA* adj=grf->vrtc[i].cad;
        while(adj){
            cout<<"v"<<adj->vertice<<"("<<adj->peso<<")";
            adj=adj->prox;
        }
        cout<<endl;
    }
}
void imprimirSP(GRAFO* grf){
    cout<<"Vertices: "<<grf->vertices<<"\tArestas: "<<grf->arestas<<endl;
    for(int i=0;i<grf->vertices;i++){
        cout<<"v"<<i<<": ";
        ADJACENCIASP* adj=grf->vrtc[i].cadsp;
        while(adj){
            cout<<"v"<<adj->vertice;
            adj=adj->prox;
        }
        cout<<endl;
    }
}
int main(){
    GRAFO* grf1=criarGrafo(5);
    criarArestaDirP(grf1,0,1,20);
    criarArestaDirP(grf1,1,2,40);
    criarArestaDirP(grf1,2,0,12);
    criarArestaDirP(grf1,2,4,40);
    criarArestaDirP(grf1,3,1,30);
    criarArestaDirP(grf1,4,3,80);
    imprimirP(grf1);
    cout<<endl;
    GRAFO* grf2=criarGrafo(5);
    criarArestaNDirP(grf2,0,1,20);
    criarArestaNDirP(grf2,1,2,40);
    criarArestaNDirP(grf2,2,0,12);
    criarArestaNDirP(grf2,2,4,40);
    criarArestaNDirP(grf2,3,1,30);
    criarArestaNDirP(grf2,4,3,80);
    imprimirP(grf2);
    cout<<endl;
    GRAFO* grf3=criarGrafo(5);
    criarArestaDirSP(grf3,0,1);
    criarArestaDirSP(grf3,1,2);
    criarArestaDirSP(grf3,2,0);
    criarArestaDirSP(grf3,2,4);
    criarArestaDirSP(grf3,3,1);
    criarArestaDirSP(grf3,4,3);
    imprimirSP(grf3);
    cout<<endl;
    GRAFO* grf4=criarGrafo(5);
    criarArestaNDirSP(grf4,0,1);
    criarArestaNDirSP(grf4,1,2);
    criarArestaNDirSP(grf4,2,0);
    criarArestaNDirSP(grf4,2,4);
    criarArestaNDirSP(grf4,3,1);
    criarArestaNDirSP(grf4,4,3);
    imprimirSP(grf4);
    return 0;
}
