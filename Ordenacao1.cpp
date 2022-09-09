#include <iostream>
#define T 6
using namespace std;
void insertion(int *lis){
	int temp,i,j;
	for(i=0;i<T;i++){
		temp= *(lis+i);
		j=i-1;
		while((*(lis+j)>temp)&&(j>=0)){
			*(lis+j+1)=*(lis+j);
			*(lis+j)=temp;
			j--;
		}
	}
}
void insertionD(int *lis){
	int temp,i,j;
	for(i=0;i<T;i++){
		temp= *(lis+i);
		j=i-1;
		while((*(lis+j)<temp)&&(j>=0)){
			*(lis+j+1)=*(lis+j);
			*(lis+j)=temp;
			j--;
		}
	}
}
void selection(int *lis){
	int i,j,min,temp;
	for(i=0;i<T-1;i++){
		min=i;
		for(j=i+1;j<T;j++){
		    if(*(lis+j)<*(lis+min)){
		        min=j;
		    }
		}
		temp=*(lis+min);
		*(lis+min)=*(lis+i);
		*(lis+i)=temp;
	}
}
void selectionD(int *lis){
	int i,j,min,temp;
	for(i=0;i<T-1;i++){
		min=i;
		for(j=i+1;j<T;j++){
		    if(*(lis+j)>*(lis+min)){
		        min=j;
		    }
		}
		temp=*(lis+min);
		*(lis+min)=*(lis+i);
		*(lis+i)=temp;
	}
}
void bubble(int *lis){
	int i,j,temp;
	for(i=0;i<T-1;i++){
		for(j=0;j<T-i-1;j++){
		    if(*(lis+j)>*(lis+j+1)){
		        temp=*(lis+j);
		        *(lis+j)=*(lis+j+1);
		        *(lis+j+1)=temp;
		    }
		}
	}
}
void bubbleD(int *lis){
	int i,j,temp;
	for(i=0;i<T-1;i++){
		for(j=0;j<T-i-1;j++){
		    if(*(lis+j)<*(lis+j+1)){
		        temp=*(lis+j);
		        *(lis+j)=*(lis+j+1);
		        *(lis+j+1)=temp;
		    }
		}
	}
}
void mostrarLista(int lis[T]){
	for(int i=0;i<T;i++){
		printf("%d\t",lis[i]);
	}
}
int main(){
	int l[T]={34,12,15,21,5,88};
	int temp,i,j;
	mostrarLista(l);
	insertion(l);
	cout<<endl;
	mostrarLista(l);
	selection(l);
	cout<<endl;
	mostrarLista(l);
	bubble(l);
	cout<<endl;
	mostrarLista(l);
	insertionD(l);
	cout<<endl;
	mostrarLista(l);
	selectionD(l);
	cout<<endl;
	mostrarLista(l);
	bubbleD(l);
	cout<<endl;
	mostrarLista(l);
	return 0;
}
