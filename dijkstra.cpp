#include <iostream>
using namespace std;
typedef struct adjacencia{
    int vertice;
    int peso;
    struct adjacencia *prox;
}ADJACENCIA;
typedef struct vertice{
    ADJACENCIA *cad;
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
int procura_no(float d[],bool v[],int vrtcs){
    float min_dist=1000000;
    int min_no=-1;
    for(int i=0;i<vrtcs;i++){
        if((v[i]==false)&&(min_dist>d[i])){
            min_dist=d[i];
            min_no=i;
        }
    }
    return min_no;
}
void dijkstra(GRAFO *grf,int no){
    float dist[grf->vertices];
    bool visit[grf->vertices];
    int pred[grf->vertices];
    int no_trab;
    for(int i=0;i<grf->vertices;i++){
        dist[i]=1000000;
        visit[i]=false;
    }
    dist[no]=0;
    pred[no]=no;
    no_trab=procura_no(dist,visit,grf->vertices);
    while(no_trab!=-1){
        visit[no_trab]=true;
        ADJACENCIA *adj=grf->vrtc[no_trab].cad;
        cout<<no_trab;
        while(adj){
            if((visit[adj->vertice]==false)&&((dist[no_trab]+adj->peso)<dist[adj->vertice])){
                dist[adj->vertice]=dist[no_trab]+adj->peso;
                pred[adj->vertice]=no_trab;
            }
            adj=adj->prox;
        }
        no_trab=procura_no(dist,visit,grf->vertices);
    }
    imprimirP(grf);
}
int main(){
    GRAFO* grf=criarGrafo(5);
    criarArestaDirP(grf,0,1,20);
    criarArestaDirP(grf,1,2,40);
    criarArestaDirP(grf,2,0,12);
    criarArestaDirP(grf,2,4,40);
    criarArestaDirP(grf,3,1,30);
    criarArestaDirP(grf,4,3,80);
    imprimirP(grf);
    cout<<endl;
    dijkstra(grf,2);
    return 0;
}
