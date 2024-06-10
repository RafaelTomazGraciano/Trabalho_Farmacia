#include <stdio.h>
#include <string.h>
#include "estoque.h"


struct medicamento{
    char nome[20];
    int codigo;
    float valor;
    int data;
};

struct lista{
    medicamento *m;
    lista *prox;
};

void le_arquivo(){
    char informacao[20];
    FILE *arch;
    arch = fopen("entrada.txt", "r");

    if(arch == NULL){
        printf("O arquivo entrada.txt nao existe");
        exit(1);
    }

    if(fgetc(arch) ==  EOF){
        printf("O arquivo esta vazio");
        exit(1);
    }

    rewind(arch);

    while (1){
        if(feof(arch)){
            break;
        }

        fscanf(arch, "%s", informacao);
        printf("%s\n",informacao);

        if(!strcmp("MEDICAMENTO", informacao)){
            
        }
        else if(!strcmp("RETIRA", informacao)){
            printf("retira\n");
        }
        else if(!strcmp("IMPRIME_LISTA", informacao)){
            printf("imprime\n");
        }
        else if(!strcmp("ATUALIZA_PRECO", informacao)){
            printf("atualiza_preco\n");
        }
        else if (!strcmp("VERIFICA_VALIDADE", informacao)){
            printf("verifica_validade\n");
        }
        else if(!strcmp("VERIFICA_LISTA", informacao)){
            printf("verifica_lista\n");
        }
        else if (!strcmp("ORDENA_LISTA_VALOR", informacao)){
            printf("ordena_lista\n");
        }
        else if(!strcmp("FIM", informacao)){
            printf("fim\n");
        }
        else{
            printf("erro\n");
        }
    }
}

medicamento *CriaMedicamento(FILE *arch , char *nome ,int codigo , float valor ,int *data_de_validade ){

}
