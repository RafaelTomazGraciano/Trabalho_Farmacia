#include <stdio.h>


// Tipo que define o medicamento
typedef struct Medicamento Medicamento;

// Tipo que define a lista
typedef struct Lista Lista ;

/*Le arquivo e define o que sera realizado*/
void le_arquivo();

/*Cria lista*/
Lista *CriaLista();

/* Cria um novo medicamento */
Medicamento *CriaMedicamento(char *nome ,int codigo , float valor ,int *data_de_validade );

/* Insere um medicamento em uma lista */
Lista *InsereListaMedicamento (FILE *fp , Lista *l , Medicamento *m );

/* Retira um medicamento de uma determinada lista */
Lista * RetiraListaMedicamento (FILE *fp , Lista *l , int id_medicamento);

/* Imprime todos os medicamentos de uma lista */
void ImprimeListaMedicamentos (FILE *fp, Lista *p);

/* Atualiza Preco do produto */
void AtualizaPreco (FILE *fp, Lista *p, int id_medicamento, float preco);

/* Verifica se existe um medicamento vencido em uma determinada lista */
void VerificaListaValidade (FILE *fp , Lista *p , int *data);

/* Verifica se um medicamento está presente em uma determinada lista */
void VerificaListaMedicamento (FILE *fp , Lista *p , int id_medicamento);

/* Ordena Lista pelo valor do medicamento */
Lista *OrdenaListaValor (Lista *p);

/* Ordena Lista pela data de vencimento do medicamento */
Lista *OrdenaListaVencimento (Lista *p);

/* Libera*/
void fim(Lista *l);