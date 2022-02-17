#include <stdio.h>
#include<time.h>
#include <stdlib.h>

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

void troca(int v[], int i, int j){
  int aux = v[i];
  v[i]= v[j];
  v[j]= aux;
}

void insertion_sort(int v[], int n){
  int j;
  int comparacao = 0, cont = 0;
  for (int i = 1; i < n; i++){
    for (j = i; j >= 1 && v[j] < v[j-1]; j--){ 
     comparacao++;
      troca(v, j, j-1);
     
    } 
    cont++;
         
  }
  printf(" N de comparacoes: %d\n ", comparacao);
  printf("N de trocas: %d\n ", cont);
}

void mostrar(int v[], int n) {
  for (int i = 0; i < n; i++) {
    printf("\neee: %d ", v[i]);
  }
  printf("\n");
}

int main() {
  int *v, K, escolha;
  clock_t begin = clock();
  //10.000, 50.000, 100.000, 500.000, 1.000.000, 5.000.000
printf("Escolha o seu K\n 1: K=10.000\n 2: K=50.000,\n3: K= 100.000,\n4: K=500.000,\n5: K= 1.000.000, \n6: K=5.000.000\n");
scanf("%d",&escolha);
  switch(escolha){
    case 1:
    K = 10000;
    break;
    case 2:
    K = 50000;
    break;
    case 3:
    K = 100000;
    break;
    case 4:
    K = 500000;
    break;
    case 5:
    K = 1000000;
    break;  
    case 6:
    K = 5000000;
    break;
  }
    
  v= gera_Vetor(K);

  insertion_sort(v, K);
 

  free(v);

  clock_t end = clock();

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo de programa: %lf",time_spent);

  
  return 0;
}