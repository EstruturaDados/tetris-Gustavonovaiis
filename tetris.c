#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char tipo;
    int id;
} Peca;

#define MAX 5

typedef struct {
   Peca peca[MAX];
   int inicio;
   int final;
   int total;
} FilaDePecas;

void menu(){
    printf("--------------- TETRIS STACK --------------\n");
    printf("1 - jogar uma peca.\n");
    printf("2 - inserir uma peca.\n");
    printf("0 - sair\n");
    printf("--------------------------------------------\n");
    printf("Escolha uma das opcoes acima: \n\n");

}

void iniciarFila(FilaDePecas *f){
    f->final = 0;
    f->inicio = 0;
    f->total = 0;
}

void gerarPecas(FilaDePecas *f, Peca p){
    if(f->total == MAX){
        printf("Fila cheia.\n");
        return;
    }
    f->peca[f->final] = p;
    f->final = (f->final +1) % MAX;
    f->total++;
}

void removerPecas(FilaDePecas *f, Peca *p){
    if(f->total == 0){
        printf("Fila vazia.\n");
        return;
    }
    *p = f->peca[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
}

void mostrarFila(FilaDePecas *f){
    if (f->total == 0){
        printf("Fila de Pecas: (vazia)\n");
        return;
    }
    printf("Fila de Pecas: ");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx+1)%MAX){
        printf("[%c %d] ", f->peca[idx].tipo, f->peca[idx].id);
    }
    printf("\n");
}

int main(){
    FilaDePecas fila;
    iniciarFila(&fila);

    // Sequencia fixa para reproduzir a saida: T,O,L,I,I com ids 0..4
    char seqTipos[] = {'T','O','L','I','I'};
    for (int i = 0; i < MAX; i++){
        Peca p;
        p.tipo = seqTipos[i];
        p.id = i;          // ids 0..4 conforme imagem
        gerarPecas(&fila, p);
    }

    printf("Saida esperada\n\n");
    mostrarFila(&fila);
    menu();
    // (Opcional: implementar loop de interacao se desejar; omitido para apenas mostrar a saida)
    return 0;
}
