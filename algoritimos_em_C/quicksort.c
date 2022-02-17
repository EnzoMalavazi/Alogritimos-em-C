#include<stdio.h>
#include <stdlib.h>
#include <time.h>


int *gera_Vetor(int K){

  int *v=(int *)calloc(K, sizeof(int));

    int i = 0, igual;
    
    srand(time(NULL));
    
    while(i < K){

      v[i] = rand() % (3*K); 
      igual = 0;

      for(int j = 0; j < i; j++){ 
        if(v[j] == v[i])
          igual = 1;
      }

      if(igual == 0)
        i++; 
    }
    return v;
}

void mostra (int *v, int n){
  for (int i=0; i<n; i++){
    printf("%d\t", v[i]);
  }
  printf("\n");
}


void quicksort(int *v,int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(v[i]<=v[pivot]&&i<last)
            i++;
         while(v[j]>v[pivot])
            j--;
         if(i<j){
            temp=v[i];
            v[i]=v[j];
            v[j]=temp;
         }
      }

      temp=v[pivot];
      v[pivot]=v[j];
      v[j]=temp;
      quicksort(v,first,j-1);
      quicksort(v,j+1,last);
   }
}


void mostrar(int v[], int n){
  for (int i = 0; i < n; i++){
    printf("\neee:%d ", v[i]);
  }
}


int main(){
   int i, K=10000, *v;
   clock_t begin = clock();
   v= gera_Vetor(K);
   quicksort(v,0,K-1);
   mostrar(v,K);
 clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo de programa: %lf",time_spent);
  free(v);
   return 0;
}
