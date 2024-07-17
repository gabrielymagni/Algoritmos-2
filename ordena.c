//compara cada elemento com o próximo, se é > ou < ele troca
//a posição de ambos
//bubble sort

#include <stdio.h>

#define tamanho  5

int main(){
    int vetor[]= {7, 5, 3, 1, 15};
    int i, j, temp;

    printf("Vetor original:\n");

    for(i=0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    };

    for(i=0; i<tamanho-1; i++){
       for(j=0; j<tamanho-i-1; j++){   //ou j<i
            if(vetor[j] > vetor[j+1]){
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }

    printf("Vetor ordenado:\n");
    for(i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }
    return 0;
}
