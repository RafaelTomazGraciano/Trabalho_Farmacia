#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

int main() {
    Arvore  *arv = CriaArvore(); // cria arvore
    Medicamento *med = NULL;
    char informacao[20];
    FILE *arch_entrada = fopen("entrada.txt", "r"); // abre arquivo de entrada para leitura
    FILE *arch_saida = fopen("saida.txt", "w"); // abre arquivo de saída para escrita

    //variaveis para guardar valores lidos
    char nome [20];
    int codigo;
    float valor;
    int data [3];

    if (arch_entrada == NULL) { // verifica se o arquivo existe
        printf("O arquivo entrada.txt nao existe");
        exit(1);
    }

    if (fgetc(arch_entrada) == EOF) { // verifica se o arquivo não está vazio
        printf("O arquivo está vazio");
        exit(1);
    }

    rewind(arch_entrada); // volta para o início do arquivo

    while (1) {
        if (feof(arch_entrada)) { // quando chega no fim do arquivo, para o loop
            break;
        }

        fscanf(arch_entrada, "%s", informacao); // lê a informação

        if (!strcmp("MEDICAMENTO", informacao)) { // registra medicamento
            fscanf(arch_entrada, "%s %d %f %d %d %d", nome, &codigo, &valor, &data[0], &data[1], &data[2]);
            med = CriaMedicamento(nome,codigo, valor, data);
            arv = InsereArvoreMedicamento(arch_saida, arv, med);

        } 
        
        else if (!strcmp("RETIRA", informacao)) { // retira medicamento
            fscanf(arch_entrada, "%d", &codigo);
            arv = RetiraArvoreMedicamento(arch_saida, arv, codigo);
        }

        else if(!strcmp("IMPRIME_ARVORE", informacao)){ //imprime arvore
            ImprimeArvoreMedicamentos(arch_saida, arv);
        }

        else if(!strcmp("ATUALIZA_PRECO", informacao)){ // atualiza preco
            fscanf(arch_entrada, "%d %f", &codigo, &valor);
            AtualizaPreco(arch_saida, arv, codigo, valor);
        }

        else if(!strcmp("VERIFICA_VALIDADE", informacao)){ // verifica validade
            fscanf(arch_entrada, "%d %d %d", &data[0], &data[1], &data[2]);
            int encontrou = 0;
            VerificaArvoreValidade(arch_saida, arv, data, &encontrou);
            if(encontrou == 0){
                fprintf(arch_saida, "MEDICAMENTO VENCIDO NAO ENCONTRADO NA ARVORE\n");
            }
        }
        
        else if(!strcmp("VERIFICA_ARVORE", informacao)){ // verifica arvore
            fscanf(arch_entrada, "%d", &codigo);
            VerificaArvoreMedicamento(arch_saida, arv, codigo);
        }

        else if(!strcmp("FIM", informacao)){ //fim
            fim(arv);
        }
    }

    fclose(arch_entrada);
    fclose(arch_saida);

    return 0;
}