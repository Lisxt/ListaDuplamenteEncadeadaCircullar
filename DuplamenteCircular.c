#include <stdio.h>
#include <stdlib.h>
#include "DuplamenteCircular.h"

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista* inicializa (void){
    return NULL;
}

/* inser��o no in�cio: retorna a lista atualizada */
Lista* insere_inicio (Lista* l, int cod, int nota){
    Lista* novoNO = (Lista*) malloc(sizeof(Lista));
    novoNO->codAluno = cod;
    novoNO->nota = nota;
    if(l == NULL) {
        novoNO->prox = novoNO;
        novoNO->ant= novoNO;
        l = novoNO;
    } else {
        Lista* ultimo = l->ant;
        novoNO->prox = l;
        novoNO->ant = ultimo;
        l->ant = novoNO;
        ultimo->prox = novoNO;
        l = novoNO;
    }
    return l;
}


/* fun��o imprime: imprime valores dos elementos */
void imprime (Lista* l){
    if(l == NULL) {
        printf("Lista Vazia.\n");
        return;
    }
    Lista* p = l;
    do
    {
      printf("\nAluno = %d\n", p->codAluno);
      printf("\nNota = %d\n", p->nota);
      printf("-------------fim-------------");
      p = p->prox;

    } while (p != l);

}

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int vazia (Lista* l){
    return (l == NULL);
}

/* fun��o busca: busca um elemento na lista */
Lista* busca (Lista* l, int cod){
    Lista* p = l;
    do {
    if (p->codAluno == cod){
        //printf("Nota = %d\n", p->nota);
        return p;
    }
        p = p->prox;
    }while(p != l);
    return NULL; /* n�o achou o elemento */
}
//ALTERAR
/* fun��o retira: retira elemento da lista */
/*Lista* retira (Lista* l, int cod) {
    Lista* ant = NULL; //ponteiro para elemento anterior 
    Lista* p = l; //ponteiro para percorrer a lista
    //procura elemento na lista, guardando anterior
    while (p != NULL && p->codAluno != cod) {
        ant = p;
        p = p->prox;
    }
    //verifica se achou elemento
    if (p == NULL)
    return l;  //n�o achou: retorna lista original
    //retira elemento
    if (ant == NULL) {
    //retira elemento do inicio
        l = p->prox;
    }else{
        //retira elemento do meio da lista
        ant->prox = p->prox;
    }
    free(p); //libera o n� da mem�ria
    return l;
}*/
//ALTERAR
/*void libera (Lista* l){
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox; //guarda refer�ncia para o pr�ximo elemento
          //libera a mem�ria apontada por p
        p = t; //faz p apontar para o pr�ximo
    }
}*/
/* fun��o auxiliar: cria e inicializa um n� */
Lista* cria (int cod, int nota){
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->codAluno = cod;
    p->nota = nota;
    return p;
}

Lista* insere_ordenado (Lista* l, int cod, int nota){
    Lista* novoNO = cria(cod, nota); //cria novo n� 
    if (novoNO == NULL) {
        return l;
    }

    if(l == NULL) {
        novoNO->prox = novoNO;
        novoNO->ant= novoNO;
        l = novoNO;
    }

    Lista* p = l;

    //procura posi��o de inser��o 
    while (p->prox != l && p->prox->codAluno < cod) {
        p = p->prox;
    }
        novoNO->prox = p->prox;
        novoNO->ant = p;
        p->prox->ant= novoNO;
        p->prox = novoNO;
    
        return l;
}
