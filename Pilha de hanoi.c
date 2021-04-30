#include <stdio.h>
#include <stdlib.h>

//struct com identificador e ponteiro
typedef struct no{
    int id;
    struct no *prox;
}NO;

//NO "topo" da pilha
NO *topo = NULL;
int tam = 0;

/*  Fun��o adicionar que forma os n�s da pilha.
    Os n�s v�o ser os "discos" da torre de han�i.
*/
void adicionar(int id){

    NO *novo = malloc(sizeof(NO));
    novo->id = id;
    novo->prox = topo;
    topo = novo;
    tam++;
}

/*  Fun��o que vai imprimir os n�s da pilha.
    Imprimir um identificador a baixo do outro.
*/
void imprimir(){

    NO* aux = topo;
    printf("\nImprimindo torre de hanoi...\n");
    for(int i=0; i<tam; i++){
        printf("|%d|\n", aux->id);
        aux = aux->prox;
    }
}

/*  Fun��o que calcula a quantidade de movimentos
    para construir a torre de acordo com a quantidade de discos.
*/
int hanoi(int discos){

    if(discos == 1){
        return 1;
    }
    else{
        return 2*hanoi(discos-1) + 1;
    }

}

//Fun��o principal que recebe do usuario a quantidade de discos que quer na pilha
int main(void){

   int discos;

    printf("Digite a quantidade de discos que voc� quer empilhar: ");
    scanf("%d", &discos);

    for(int i=discos; i>=1; i--){ //ordena��o da pilha e chamada da fun��o adicionar
        adicionar(i);
    }
    imprimir(); //chamada da fun��o imprimir

    printf("\n� necessario %d movimentos para se fazer essa torre com %d discos!\n", hanoi(discos), discos);

}
