#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 5
typedef struct PATIENT{
    int priority;
    long telnum;
    char name[16];
}H_PATIENT;
typedef struct HEAP{
    H_PATIENT *key;
    int tail;
    int mxsz;
}O_HEAP;
int left(int index){
    return 2*index+1;
}
int right(int index){
    return 2*(index+1);
}
int parent(int index){
    return (index-1)/2;
}
void swap(O_HEAP *h,int x,int y){
    H_PATIENT u=h->key[x];
    h->key[x]=h->key[y];
    h->key[y]=u;
}
short isValidIdx(int index,int tail){
    return ((index>=0)&&(index<=tail));
}
short isLeaf(O_HEAP *h,int idx){
    return idx>parent(h->tail)&& idx<= h->tail;
}
short isEmpty(O_HEAP *h){
    return h->tail<0;
}
short isFull(O_HEAP *h){
    return h->tail==h->mxsz-1;
}
int value(O_HEAP *h,int index){
    if(isValidIdx(index,h->tail)){
        return h->key[index].priority;
    }
    else{
        return 0;
    }
}
void resize(O_HEAP *h){
    h->mxsz +=1;
    h->key=(H_PATIENT*)realloc(h->key,sizeof(H_PATIENT) * h->mxsz);
}
int maxBtIndex(O_HEAP *h,int idx){
    if(!isValidIdx(idx,h->tail)){
        return -1;
    }
    int vIdx=value(h,idx);
    int vLeft=value(h,left(idx));
    int vRight=value(h,right(idx));
    if(vIdx>vLeft){
        if(isValidIdx(right(idx),h->tail)){
            if(vIdx<vRight){
                return right(idx);
            }
        }
        return idx;
    }
    else{
        if(isValidIdx(right(idx),h->tail)){
            if(vLeft<vRight){
                return right(idx);
            }
        }
        return left(idx);
    }
}
void initializeQueue(O_HEAP *q,int sz,int typeconfig){
    char names[5][16]={
        "Aurea Melo",
        "Raimundo Correa",
        "Juan Cuevas",
        "Manuel Azevedo",
        "Tiago Eugenio"};
    long telnums[5]={
        988887777,
        695159632,
        975396241,
        965498523,
        963852741};
    q->key=(H_PATIENT*)malloc(sizeof(H_PATIENT) * sz);
    for(int i=0;i<sz;i++){
        int priority=1;
        if (typeconfig==3){
            // sequencial
            priority=i+1;
        }
        else if(typeconfig==2){
            // reverse sequencial
            priority=sz-i;
        }
        else{
            // random by sz
            priority=1+(rand()%(sz-1));
        }
        q->key[i].priority=priority;
        q->key[i].telnum=telnums[i];
        strcpy(q->key[i].name,names[i]);
    }
    q->tail=sz-1;
    q->mxsz=sz;
}

void printPatient(H_PATIENT *p){
    printf(" nome: [%s] tel: [%ld] prioridade: [%d]\n\n",(*p).name,(*p).telnum,(*p).priority);
}
void printQueue(O_HEAP *q){
    int i=0;
    printf("\n|");
    for(i=0;i<= q->tail;i++){
        printf(" nome: [%s] tel: [%ld] prioridade: [%d] |",q->key[i].name,q->key[i].telnum,q->key[i].priority);
        ;
    }
    printf("\n\n");
}
void heapifyUp(O_HEAP *h,int idx){
    int i=idx;
    while((i>0)&&(value(h, parent(i))<value(h,i))){
        swap(h, parent(i),i);
        i=parent(i);
    }
}
void heapify(O_HEAP *h,int idx){
    if (isLeaf(h,idx)||!isValidIdx(idx,h->tail)){
        return;
    }
    int maxIdx=maxBtIndex(h,idx);
    if(maxIdx!=idx){
        swap(h,idx,maxIdx);
        heapify(h,maxIdx);
    }
}
void buildHeap(O_HEAP *h){
    for(int i=parent(h->tail);i>=0;i--){
        heapify(h, i);
    }
}
H_PATIENT xkey(O_HEAP *vt){
    return vt->key[0];
}
H_PATIENT *remMax(O_HEAP *h){
    swap(h,0,h->tail);
    h->tail-=1;
    heapify(h,0);
    return &h->key[h->tail+1];
}
void insertNew(O_HEAP *h,H_PATIENT *p){
    if (h->tail==h->mxsz-1){
        resize(h);
    }
    h->tail++;
    h->key[h->tail]= *p;
    heapifyUp(h,h->tail);
}
void increasePriority(O_HEAP *h,int i,int pri){
    if(value(h,i)>pri){
        printf(" --- ERRO --- : Ja e a maior\n");
    }
    else{
        h->key[i].priority=pri;
        heapifyUp(h,i);
    }
}
void decreasePriority(O_HEAP *h,int i,int pri){
    if(value(h,i)<pri){
        printf(" --- ERRO --- : Ja e a menor\n");
    }
    else{
        h->key[i].priority=pri;
        heapify(h,i);
    }
}
H_PATIENT *scanPatient(){
    H_PATIENT *p=(H_PATIENT *)malloc(sizeof(H_PATIENT));
    printf("Insira o novo paciente...\n name: ");
    scanf("%[^\n]",p->name);
    printf("numero de telefone: ");
    scanf("%ld",&(p->telnum));
    printf("prioridade de atendimento: ");
    scanf("%d",&(p->priority));
    printf("Obrigado, foi armazenado com sucesso\n\n");
    return p;
}
int main(int *argc,char *argv[]){
    O_HEAP hp;
    O_HEAP *h=&hp;
    initializeQueue(h,SZ,1);
    printQueue(h);
    buildHeap(h);
    printQueue(h);
    printf("O hospital vai atender um paciente: ");
    H_PATIENT *p=remMax(h);
    printPatient(p);
    printQueue(h);
    H_PATIENT *np=scanPatient();
    insertNew(h,np);
    printQueue(h);
    return 0;
}
