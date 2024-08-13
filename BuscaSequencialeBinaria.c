#include<stdio.h>

int buscaBinaria(int vet[], int valor, int tamanho){
    //são as posições, não o valor
    int inicial = 0;
    int fim = tamanho -1; //posicao do vetor vai até 9

    while (inicial <= fim){
          int meio = (inicial + fim)/2;
          //sempre pega a posição inteira 5,5 pega 5;

          if (vet[meio] == valor){
            return meio;
          } else {
                if (vet[meio] < valor){
                    inicial = meio + 1;
                } else {
                    fim = meio + 1;
                }
        }
    }
    return -1;
}




int main(){
    int vet[10]={2,6,7,9,12,15,17,20,23,27};
    int valor = 20;

    //retorno da função
    int indice = buscaBinaria(vet, valor, 10);

    if (indice != -1){
        printf("Valor encontrado no indice: %d\n", indice);
    } else {
        printf("Valor nao encontrado\n");
        }


    return 0;
    }
