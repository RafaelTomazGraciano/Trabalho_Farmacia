#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

struct medicamento {
    char nome [20];
    int codigo;
    float valor;
    int data [3];
};

struct arvore {
    Medicamento *m;
    Arvore *esquerda;
    Arvore *direita;
};

Arvore *CriaArvore(){
    return NULL;
}


Medicamento *CriaMedicamento(char *nome ,int codigo , float valor ,int *data_de_validade ){//cria medicamento na struct
    Medicamento *novo = (Medicamento*) malloc(sizeof(Medicamento));

    strcpy(novo->nome, nome);
    novo->codigo = codigo;
    novo->valor = valor;
    for(int i = 0; i < 3; i++){
        novo->data[i] = data_de_validade[i];
    }

    return novo;
}

Arvore *InsereArvoreMedicamento(FILE *fp, Arvore *a , Medicamento *m){//insere medicamento na arvore
    if(a == NULL){
        a = (Arvore *) malloc(sizeof(Arvore));
        a->m = (Medicamento *) malloc(sizeof(Medicamento));
        a->m = m;
        a->esquerda = a->direita = NULL; 
        fprintf(fp, "MEDICAMENTO %s %d ADICIONADO\n", m->nome, m->codigo);//escreve no arquivo de saida
    }
    else if(m->codigo < a->m->codigo){
        a->esquerda = InsereArvoreMedicamento(fp, a->esquerda, m);
    }
    else if(m-> codigo > a->m->codigo){
        a->direita = InsereArvoreMedicamento(fp, a->direita, m);
    }
    else{
        fprintf(fp, "MEDICAMENTO COM CODIGO %d JA ADICIONADO\n", m->codigo);//escreve no arquivo de saida
    }
    return a;
}

Arvore *RetiraArvoreMedicamento(FILE *fp, Arvore *a, int id_medicamento){
    if(a == NULL){
        fprintf(fp, "MEDICAMENTO RETIRA NAO ENCONTRADO\n");
        return NULL;
    }
    else if(id_medicamento < a->m->codigo){
        a->esquerda = RetiraArvoreMedicamento(fp, a->esquerda, id_medicamento);
    }
    else if(id_medicamento > a->m->codigo){
        a->direita = RetiraArvoreMedicamento(fp, a->direita, id_medicamento);
    }
    else{//achou o no para remover
        
        //no sem filhos
        if(a->esquerda == NULL && a->direita ==NULL){
            fprintf(fp, "MEDICAMENTO %s %d RETIRADO\n", a->m->nome , a->m->codigo);
            free(a->m); // Liberar a memória do medicamento
            free(a);    // Liberar a memória do nó
            a = NULL;
        }
        // no tem filho a direita
        else if(a->esquerda == NULL){
            fprintf(fp, "MEDICAMENTO %s %d RETIRADO\n", a->m->nome , a->m->codigo);
            Arvore *temp = a;
            printf("%d", temp->m->codigo);
            a = a->direita;
            free(temp->m); // Liberar a memória do medicamento
            free(temp);    // Liberar a memória do nó
        }
        //no tem filho a esquerda
        else if(a->direita == NULL){
            fprintf(fp, "MEDICAMENTO %s %d RETIRADO\n", a->m->nome , a->m->codigo);
            Arvore *temp = a;
            printf("%d", temp->m->codigo);
            a = a->esquerda;
            free(temp->m); // Liberar a memória do medicamento
            free(temp);    // Liberar a memória do nó
        }
        //no tem os dois filhos
        else{
            Arvore *temp = a->esquerda;
            while(temp->direita != NULL){
                temp = temp->direita;
            }
            a->m = temp->m; //troca as informacoes
            //temp->m->codigo = id_medicamento;
            a->esquerda = RetiraArvoreMedicamento(fp, a->esquerda, temp->m->codigo);
        }
    }
    return a;
}

Arvore *AtualizaPreco(FILE *fp, Arvore *a, int id_medicamento, float preco){

}

int VerificaArvoreMedicamento(FILE *fp, Arvore *a , int id_medicamento){

}

int VerificaArvoreValidade(FILE *fp, Arvore *a , int *data){

}

void ImprimeArvoreMedicamentos(FILE *fp, Arvore *a){
    if(a != NULL){
        ImprimeArvoreMedicamentos(fp, a->esquerda);
        fprintf(fp, "%s %d %.1f %d %d %d\n", a->m->nome, a->m->codigo, a->m->valor, a->m->data[0], a->m->data[1], a->m->data[2]);
        ImprimeArvoreMedicamentos(fp, a->direita);
    }
}