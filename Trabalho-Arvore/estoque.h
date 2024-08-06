#include <stdio.h>


// Tipo que define o medicamento
typedef struct medicamento Medicamento;

// Tipo que define a arvore
typedef struct arvore Arvore ;

/* Cria uma arvore vazia */
Arvore *CriaArvore();

/* Cria um novo medicamento */
Medicamento *CriaMedicamento(char * nome, int codigo, float valor, int* data_de_validade );

/* Insere um medicamento pelo codigo na arvore */
Arvore *InsereArvoreMedicamento(FILE *fp, Arvore *a , Medicamento *m);

/* Retira um medicamento de uma determinada arvore */
Arvore *RetiraArvoreMedicamento(FILE *fp, Arvore *a, int id_medicamento);

/* Atualiza preco de um medicamento de uma determinada arvore */
Arvore *AtualizaPreco(FILE *fp, Arvore *a, int id_medicamento, float preco);

/* Verifica se um medicamento esta presente em uma determinada arvore */
void VerificaArvoreMedicamento(FILE *fp, Arvore *a , int id_medicamento);

/* Verifica se existe um medicamento vencido em uma determinada arvore */
void VerificaArvoreValidade(FILE *fp, Arvore *a , int *data, int *encontrou);

/* Imprime em ordem pelo codigo todos os medicamentos de uma arvore (em ordem )*/
void ImprimeArvoreMedicamentos(FILE *fp, Arvore *a);

/* libera memoria */
void fim(Arvore *a);