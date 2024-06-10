#include <stdio.h>
#include <stdlib.h>


// Tipo que define o medicamento
typedef struct medicamento medicamento;

// Tipo que define a lista
typedef struct lista lista ;

/*Le arquivo e define o que sera realizado*/
void le_arquivo();

/* Cria um novo medicamento */
medicamento *CriaMedicamento(FILE *arch , char *nome ,int codigo , float valor ,int *data_de_validade );

lista *CriaLista();

/* Insere um medicamento em uma lista */
lista *InsereListaMedicamento (FILE *fp , lista *l , medicamento *m );

/* Retira um medicamento de uma determinada lista */
lista * RetiraListaMedicamento ( FILE * fp , lista * l , int id_medicamento );

/* Verifica se um medicamento está presente em uma determinada lista */
int VerificaListaMedicamento ( FILE * fp , lista * p , int id_medicamento );

/* Verifica se existe um medicamento vencido em uma determinada lista */
int VerificaListaValidade ( FILE * fp , lista * p , int * data );

/* Imprime todos os medicamentos de uma lista */
void ImprimeListaMedicamentos ( FILE * fp , lista * p );

/* Ordena Lista pelo valor do medicamento */
lista *OrdenaListaValor ( lista * p );

/* Ordena Lista pela data de vencimento do medicamento */
lista *OrdenaListaVencimento ( lista * p );
