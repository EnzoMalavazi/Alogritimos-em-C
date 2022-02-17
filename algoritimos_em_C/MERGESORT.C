#include <stdio.h>
#include <stdlib.h>
#include<time.h>
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


void intercala(int p, int q, int n, int v[]){
  int *aux = (int *) calloc(n - p, sizeof(int));

  int i, j, k;

  for (i = p, j = q, k = 0; i < q && j < n; k++){
    if (v[i] <= v[j]){
      aux[k] = v[i];
      i++;
    } else {
      aux[k] = v[j];
      j++;
    }
  }

  for (;i < q; i++, k++){
    aux[k] = v[i];
  }

  for (;j < n; j++, k++){
    aux[k] = v[j];
  }

  for (i = p; i < n; i++){
    v[i] = aux[i - p];
  }

  free(aux);
}

void mergesort(int v[], int p, int n){
  if (p < n-1){
    int q = (p + n)/2;
    mergesort(v, p, q);
    mergesort(v, q, n);
    intercala(p, q, n, v);
  }
}

void mostrar(int v[], int n){
  for (int i = 0; i < n; i++){
    printf("\neee:%d ", v[i]);
  }
}


int main(void) {
  int *v, K =1000;
 clock_t begin = clock();

 v= gera_Vetor(K);

  mergesort(v, 0, K);
  mostrar( v, K);
  clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo de programa: %lf",time_spent);
  free(v);

  return 0;

}