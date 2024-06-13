#include <stdio.h>
#include <string.h>
#include "estoque.h"


struct Medicamento{
    char nome[20];
    int codigo;
    float valor;
    int data[3];
};

struct Lista{
    Medicamento *m;
    Lista *prox;
};

void le_arquivo(){
    Lista  *lst = CriaLista(); //cria lista
    Medicamento *med =  NULL, medicamentotemp; // cria medicamento
    char informacao[20];
    FILE *arch_entrada = fopen("entrada.txt", "r");//abre arquivo de entrada para leitura
    FILE *arch_saida = fopen("saida.txt", "w");//abre arquivo de saida para escrita

    if(arch_entrada == NULL){
        printf("O arquivo entrada.txt nao existe");
        exit(1);
    }

    if(fgetc(arch_entrada) ==  EOF){
        printf("O arquivo esta vazio");
        exit(1);
    }

    rewind(arch_entrada);

    while (1){
        if(feof(arch_entrada)){
            break;
        }

        fscanf(arch_entrada, "%s", informacao);
        printf("%s\n",informacao);

        if(!strcmp("MEDICAMENTO", informacao)){

            fscanf(arch_entrada, "%s %d %f %d %d %d", medicamentotemp.nome, &medicamentotemp.codigo, &medicamentotemp.valor, &medicamentotemp.data[0], &medicamentotemp.data[1], &medicamentotemp.data[2]);
            med = CriaMedicamento(medicamentotemp.nome, medicamentotemp.codigo, medicamentotemp.valor, medicamentotemp.data);
            lst = InsereListaMedicamento(arch_saida, lst, med);

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

Lista *CriaLista(){
    return NULL;
}

Medicamento *CriaMedicamento(char *nome ,int codigo , float valor ,int *data_de_validade ){
    Medicamento *novo = (Medicamento*) malloc(sizeof(Medicamento));
    strcpy(novo->nome, nome);
    novo->codigo = codigo;
    novo->valor = valor;
    for(int i = 0; i < 3; i++){
        novo->data[i] = data_de_validade[i];
    }
    return novo;
}

Lista *InsereListaMedicamento (FILE *fp , Lista *l , Medicamento *m ){
    fprintf(fp, "MEIDACAMENTO %s %d ADICIONADO\n", m->nome, m->codigo);//escreve no arquivo de saida

    Lista *novo = (Lista*) malloc(sizeof(Lista));//cria lista
    novo->m = m;
    novo->prox = l;
    return novo;
}
