#include <stdio.h>
#include <stdlib.h>
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

        if(!strcmp("MEDICAMENTO", informacao)){

            fscanf(arch_entrada, "%s %d %f %d %d %d", medicamentotemp.nome, &medicamentotemp.codigo, &medicamentotemp.valor, &medicamentotemp.data[0], &medicamentotemp.data[1], &medicamentotemp.data[2]);
            med = CriaMedicamento(medicamentotemp.nome, medicamentotemp.codigo, medicamentotemp.valor, medicamentotemp.data);
            lst = InsereListaMedicamento(arch_saida, lst, med);

        }

        else if(!strcmp("RETIRA", informacao)){

            fscanf(arch_entrada, "%d", &medicamentotemp.codigo);
            lst = RetiraListaMedicamento (arch_saida , lst , medicamentotemp.codigo);

        }

        else if(!strcmp("IMPRIME_LISTA", informacao)){
            ImprimeListaMedicamentos (arch_saida, lst);
        }

        else if(!strcmp("ATUALIZA_PRECO", informacao)){

            fscanf(arch_entrada, "%d %f", &medicamentotemp.codigo, &medicamentotemp.valor);
            AtualizaPreco(arch_saida, lst, medicamentotemp.codigo, medicamentotemp.valor);

        }

        else if (!strcmp("VERIFICA_VALIDADE", informacao)){
            fscanf(arch_entrada, "%d %d %d", &medicamentotemp.data[0], &medicamentotemp.data[1], &medicamentotemp.data[2]);
            VerificaListaValidade(arch_saida , lst , medicamentotemp.data);
        }

        else if(!strcmp("VERIFICA_LISTA", informacao)){
            fscanf(arch_entrada, "%d", &medicamentotemp.codigo);
            VerificaListaMedicamento(arch_saida, lst, medicamentotemp.codigo);
        }

        else if (!strcmp("ORDENA_LISTA_VALOR", informacao)){
            lst = OrdenaListaValor (lst);
        }

        else if (!strcmp("ORDENA_LISTA_VALIDADE", informacao)){
            lst = OrdenaListaVencimento (lst);
        }

        else if(!strcmp("FIM", informacao)){
            fim(lst);
        }

        else{
            fprintf(arch_saida, "INFORMACAO NAO CONHECIDA\n");
        }
    }
    
    fclose(arch_entrada);
    fclose(arch_saida);
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
    fprintf(fp, "MEDICAMENTO %s %d ADICIONADO\n", m->nome, m->codigo);//escreve no arquivo de saida

    Lista *novo = (Lista*) malloc(sizeof(Lista));//cria lista

    novo->m = m;
    novo->prox = l;
    return novo;
}

Lista * RetiraListaMedicamento (FILE *fp , Lista *l , int id_medicamento){
    Lista *ant = NULL;
    Lista *p = l;
    
    while(p != NULL && p->m->codigo != id_medicamento){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){//Nao encontrou retorna a lista
        fprintf(fp, "MEDICAMENTO RETIRA NAO ENCONTRADO\n");
        return l;
    }
    //verifica se achou elemento
    if(ant == NULL){
        l = p->prox; //retira do inicio
    }
    else{
        ant->prox = p->prox; //retira do meio ou fim
    }

    fprintf(fp, "MEDICAMENTO %s %d RETIRADO\n", p->m->nome , id_medicamento);

    free(p->m); //libera a struct do medicamento retirado
    free(p); //libera a lista retirada
    return l;
}

void ImprimeListaMedicamentos (FILE *fp, Lista *p){

    for(Lista *aux = p; aux != NULL; aux = aux->prox){
        fprintf(fp, "%s %d %.1f %d %d %d\n", aux->m->nome, aux->m->codigo, aux->m->valor, aux->m->data[0], aux->m->data[1], aux->m->data[2]);
    }

}

void AtualizaPreco (FILE *fp, Lista *p, int id_medicamento, float preco){
    int encontrou = 0;
    for(Lista *aux = p; aux != NULL; aux = aux->prox){
        if(aux->m->codigo == id_medicamento){
            aux->m->valor = preco;
            fprintf(fp, "PRECO ATUALIZADO %s %d %.2f\n", aux->m->nome, aux->m->codigo, aux->m->valor);
            encontrou = 1;
        }
    }

    if(encontrou == 0){
        fprintf(fp, "MEDICAMENTO ATUALIZAR PRECO NAO ENCONTRADO\n");
    }
}

void VerificaListaValidade (FILE *fp , Lista *p , int *data){
    int encontrou = 0;
    for(Lista *aux = p; aux != NULL; aux = aux->prox){
        if(aux->m->data[2] < data[2]){
            fprintf(fp, "MEDICAMENTO %s %d VENCIDO\n", aux->m->nome, aux->m->codigo);
            encontrou = 1;
        }
        if(aux->m->data[2] == data[2] && aux->m->data[1] < data[1]){
            fprintf(fp, "MEDICAMENTO %s %d VENCIDO\n", aux->m->nome, aux->m->codigo);
            encontrou = 1;
        }
        if(aux->m->data[2] == data[2] && aux->m->data[1] == data[1] && aux->m->data[0] < data[0]){
            fprintf(fp, "MEDICAMENTO %s %d VENCIDO\n", aux->m->nome, aux->m->codigo);
            encontrou = 1;
        }
    }
    if(encontrou == 0){
        fprintf(fp, "MEDICAMENTO VENCIDO NAO ENCONTRADO NA LISTA\n");
    }
}

void VerificaListaMedicamento (FILE *fp , Lista *p , int id_medicamento){
    int encontrou = 0;
    for(Lista *aux = p; aux != NULL; aux = aux->prox){
        if(aux->m->codigo == id_medicamento){
            fprintf(fp, "MEDICAMENTO ENCONTRADO %s %d %.2f %d %d %d", aux->m->nome, aux->m->codigo, aux->m->valor, aux->m->data[0], aux->m->data[1], aux->m->data[2]);
            encontrou = 1;
        }
    }
    if(encontrou == 0){
        fprintf(fp, "MEDICAMENTO NAO ENCONTRADO NA LISTA\n");
    }
}

Lista *OrdenaListaValor (Lista *p){ //Bubble sort
    for(Lista *i = p; i != NULL; i = i->prox){
        for(Lista *j = p; j != NULL; j = j->prox){
            if(i->m->valor < j->m->valor){
                //valor do medicamento
                float val = i->m->valor;
                i->m->valor = j->m->valor;
                j->m->valor = val;
                // nome do emdicamento
                char nome[20];
                strcpy(nome, i->m->nome);
                strcpy(i->m->nome, j->m->nome);
                strcpy(j->m->nome, nome);
                //codigo do medicamento
                int cod = i->m->codigo;
                i->m->codigo = j->m->codigo;
                j->m->codigo = cod;
                //dia
                int dia = i->m->data[0];
                i->m->data[0] = j->m->data[0];
                j->m->data[0] = dia;
                //mes
                int mes = i->m->data[1];
                i->m->data[1] = j->m->data[1];
                j->m->data[1] = mes;
                //ano
                int ano = i->m->data[2];
                i->m->data[2] = j->m->data[2];
                j->m->data[2] = ano;

            }
        }
    }
    return p;
}

Lista *OrdenaListaVencimento (Lista *p){ //Bubble sort
    for(Lista *i = p; i != NULL; i = i->prox){
        for(Lista *j = p; j != NULL; j = j->prox){
            if(i->m->data[2] < j->m->data[2]){ //analisa pelo ano
                //valor do medicamento
                float val = i->m->valor;
                i->m->valor = j->m->valor;
                j->m->valor = val;
                // nome do emdicamento
                char nome[20];
                strcpy(nome, i->m->nome);
                strcpy(i->m->nome, j->m->nome);
                strcpy(j->m->nome, nome);
                //codigo do medicamento
                int cod = i->m->codigo;
                i->m->codigo = j->m->codigo;
                j->m->codigo = cod;
                //dia
                int dia = i->m->data[0];
                i->m->data[0] = j->m->data[0];
                j->m->data[0] = dia;
                //mes
                int mes = i->m->data[1];
                i->m->data[1] = j->m->data[1];
                j->m->data[1] = mes;
                //ano
                int ano = i->m->data[2];
                i->m->data[2] = j->m->data[2];
                j->m->data[2] = ano;
            }

            if(i->m->data[2] == j->m->data[2] && i->m->data[1] < j->m->data[1]){//analisa o ano e mes
                //valor do medicamento
                float val = i->m->valor;
                i->m->valor = j->m->valor;
                j->m->valor = val;
                // nome do emdicamento
                char nome[20];
                strcpy(nome, i->m->nome);
                strcpy(i->m->nome, j->m->nome);
                strcpy(j->m->nome, nome);
                //codigo do medicamento
                int cod = i->m->codigo;
                i->m->codigo = j->m->codigo;
                j->m->codigo = cod;
                //dia
                int dia = i->m->data[0];
                i->m->data[0] = j->m->data[0];
                j->m->data[0] = dia;
                //mes
                int mes = i->m->data[1];
                i->m->data[1] = j->m->data[1];
                j->m->data[1] = mes;
                //ano
                int ano = i->m->data[2];
                i->m->data[2] = j->m->data[2];
                j->m->data[2] = ano;
            }

            if(i->m->data[2] == j->m->data[2] && i->m->data[1] == j->m->data[1] && i->m->data[0] < j->m->data[0] ){//analisa o ano, mes e dia
                //valor do medicamento
                float val = i->m->valor;
                i->m->valor = j->m->valor;
                j->m->valor = val;
                // nome do emdicamento
                char nome[20];
                strcpy(nome, i->m->nome);
                strcpy(i->m->nome, j->m->nome);
                strcpy(j->m->nome, nome);
                //codigo do medicamento
                int cod = i->m->codigo;
                i->m->codigo = j->m->codigo;
                j->m->codigo = cod;
                //dia
                int dia = i->m->data[0];
                i->m->data[0] = j->m->data[0];
                j->m->data[0] = dia;
                //mes
                int mes = i->m->data[1];
                i->m->data[1] = j->m->data[1];
                j->m->data[1] = mes;
                //ano
                int ano = i->m->data[2];
                i->m->data[2] = j->m->data[2];
                j->m->data[2] = ano;
            }

        }
    }
    return p;
}

void fim(Lista *l){
    Lista *aux;
    Lista *p = l;
    while(p != NULL){
        aux = p->prox; // guarda referencia para o proximo elemento
        free(p->m); //libera memoria apontada para medicamentos
        free(p); // libera memoria apontada para p
        p = aux; // faz aponta p para o proximo
    }
}