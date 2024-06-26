//pilha, o ultimo elemento inserido vai ser o primeiro retirado, n�o pode pegar o valor do meio
//usado em compiladores
// last in, first out LIFO
//push empilha e pop desempilha

#include <stdio.h>

//mesma estrutura da lista
struct lista{
    int info; //valor
    struct lista* prox; //ponteiro prox para o elemento tipo lista
};
typedef struct lista Lista; //dessde modo posso chamar s� a Lista

struct pilha{
    int info;
    struct lista* topo; //� um ponteiro do tipo lista
};
typedef struct pilha Pilha;

//fun��o que retorna um ponteiro do tipo pilha
Pilha* cria (void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));//Pilha em Mai�sculo � o tipo
    p->topo = NULL; //O VALOR DO MEU TOPO � NULO
    return p;
}
//novo � o endee�o de memoria que aponta para info e prox
void push(Pilha* p, int v){// (elemento que � o topo da lista, valor que quero inserir)
    Lista* novo = (Lista*) malloc(sizeof(Lista));  //aloca a memoria para o tipo Lista
    novo->info = v;
    novo->prox = p->topo; //recebe o conteudo da pilha atual, o topo
    p->topo = novo;//atualizar o topo da pilha
}

void pop(Pilha* p){
    Lista* t; //ponteiro temporario
    if (p->topo==NULL){
        printf("Pilha vazia");
        exit(1);
    }
    t = p -> topo;
    p -> topo = t->prox;
    free
    (t);
}

void pilha_libera(Pilha* p){
    Lista* aux = p-> topo; //todo o cnteudo � passado pro auxiliar
    while(aux != NULL){
        Lista* temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(p);
}


int main (){
    Pilha* pilha;  //criei um ponteiro que aponta pro topo da minha pilha
    pilha = cria();
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    printf("Topo da pilha: %d \n", pilha->topo->info);

    pop(pilha);
    printf("Topo da pilha: %d ", pilha->topo->info);

    return 0;



}



