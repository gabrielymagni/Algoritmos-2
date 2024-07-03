//first-in-first-out
//precisa ter um ponyeiro pro primeiro elem, e pro último
//o mais antigo é atendido

#include<stdio.h>
#include<stdlib.h>


//pra remover eu uso a estrutura
struct lista{
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

struct fila{
    Lista* fim;
    Lista* inicio;
};
typedef struct fila Fila;

Fila* cria (void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insere(Fila* f, int v){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;

    novo->prox = NULL;

    //VERIFICA SE A LISTA NÃO ESTÁ VAZIA NO FIM
    if(f->fim != NULL){
        f->fim->prox = novo; //atualiza o proximo da lista, o penultimo que aponstava pra NULL agora aponta po novo que entrou
    }
    else{
        f->inicio = novo;
    }

    f->fim = novo; //sempre que inserir um novo nó o final da fila vai pra esse novo nó
}

int remover(Fila* f){
    int v;
    Lista* temp;

    if(f->inicio == NULL){
            printf("Fila vazia\n");
            exit(1);
    }
        temp = f->inicio;
        v = temp->info; //auxiliar aponta pro numero(conteudo);
        f->inicio = temp->prox; //agora o inicio vai ser o auxiliar setando prox. e prox aponta pra 18;

        if(f->inicio == NULL){
            f->fim = NULL;
        }

        free(temp);
        return v; //pega o valor que foi removido pra mostrar
}

void fila_libera(Fila* f){
    Lista* temp = f->inicio;
    while(temp != NULL){
        Lista* temp2 = temp->prox;
        free(temp); // libera cada nó da fila
        temp = temp2; //move para o proximo nó
    }
    free(f); //libera a estrutura da fila
}

void imprime(Fila* f){
    Lista* temp;
    for(temp = f->inicio; temp != NULL; temp = temp->prox){
        printf("Info: %d\n", temp->info);
    }
}

int main(){
    Fila* fila;
    fila = cria();
    insere(fila, 1);
    insere(fila, 2);
    insere(fila, 3);
    //imprime(fila);
    printf("Inicio da fila: %d \n", fila->inicio->info);

    remover(fila);
    printf("Inicio da fila: %d \n", fila->inicio->info);

    return 0;

}



