#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct structPrincipal{
    int * vetorDinamico; // responsável por guardar os valores inteiros solicitados na posicação especfícica da struct.
    int tamanhoDinamico;
    int capacidade;
}structPrincipal;

structPrincipal vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho){
    posicao = posicao - 1;
    // realizar condições para verificar qual será o retorno da função.

    if (posicao < 0 || posicao > 9)// verifica se é uma posição válida no vetorPrincipal
        return POSICAO_INVALIDA; // se posição é um valor válido {entre 1 e 10}
    else{
        if (tamanho < 1) // tamanho inválido
            return TAMANHO_INVALIDO; // o tamanho nao pode ser menor que 1
        else if (tamanho > 20)
            return SEM_ESPACO_DE_MEMORIA; // o tamanho ser muito grande
        else if (vetorPrincipal[posicao].vetorDinamico != NULL)
            return JA_TEM_ESTRUTURA_AUXILIAR;  // a posicao pode já existir estrutura auxiliar
        else{
            // deu tudo certo, crie
            vetorPrincipal[posicao].capacidade = tamanho;
            vetorPrincipal[posicao].tamanhoDinamico = 0;
            vetorPrincipal[posicao].vetorDinamico = malloc (tamanho * sizeof(int)); // definindo o tamanho da minha estrutura auxiliar (vetor secundario) 
            return SUCESSO;
        }
    } 
    return SEM_ESTRUTURA_AUXILIAR;
}// Função Validada e está OK!

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar 
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
    posicao = posicao - 1;
    if (posicao >= 0 && posicao <= 9){
        
        if (vetorPrincipal[posicao].vetorDinamico != NULL){// se existe estrutura auxiliar
            if (vetorPrincipal[posicao].tamanhoDinamico != vetorPrincipal[posicao].capacidade){ // se tem espaço
                // insere
                // INSERIR NUMERO NA ESTRUTURA, DE ACORDO COM A POSICAO DEFINIDA PELO USUÁRIO.
                vetorPrincipal[posicao].vetorDinamico[vetorPrincipal[posicao].tamanhoDinamico] = valor;
                vetorPrincipal[posicao].tamanhoDinamico++; 
                return SUCESSO;
            }
            else return SEM_ESPACO;
        }
    else return SEM_ESTRUTURA_AUXILIAR;
}
    return POSICAO_INVALIDA;
} // Função Validada e está OK!

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int i;
    posicao--;
    if (posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao].vetorDinamico == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else if (vetorPrincipal[posicao].tamanhoDinamico > 0){ // tem dado para ser excluido
        for (i = 0; i < vetorPrincipal[posicao].capacidade - 1 && vetorPrincipal[posicao].vetorDinamico[i] >= vetorPrincipal[posicao].tamanhoDinamico ;i++){
            vetorPrincipal[posicao].vetorDinamico[i] = vetorPrincipal[posicao].vetorDinamico[i+1];
        }
        vetorPrincipal[posicao].tamanhoDinamico--;
        return SUCESSO;
    }   
    else
        return ESTRUTURA_AUXILIAR_VAZIA;
} // função validada e está OK!

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{   
    int i,j;
    posicao--;
    int encontrado = 0;
    if (posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao].vetorDinamico == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else if(vetorPrincipal[posicao].tamanhoDinamico > 0){
        for (i = 0; i < vetorPrincipal[posicao].tamanhoDinamico;i++){
            if (vetorPrincipal[posicao].vetorDinamico[i] == valor){
                for(j = i; j < vetorPrincipal[posicao].tamanhoDinamico - 1;j++)
                    vetorPrincipal[posicao].vetorDinamico[j] = vetorPrincipal[posicao].vetorDinamico[j+1];
                vetorPrincipal[posicao].tamanhoDinamico--;
                encontrado = 1;
                return SUCESSO;
            }
        }
    }
    else
        return ESTRUTURA_AUXILIAR_VAZIA;

    if (encontrado == 0)
        return NUMERO_INEXISTENTE;
    
} // função validada e está OK!

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;
    int i;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao].vetorDinamico == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else{ 
        for (i=0; i < vetorPrincipal[posicao].tamanhoDinamico;i++)
            vetorAux[i] = vetorPrincipal[posicao].vetorDinamico[i];
        return SUCESSO;
    }
} // FUNÇÃO VALIDADA OK!

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;
    int i,j,aux;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao].vetorDinamico == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else{ 
        for (i = 0; i < vetorPrincipal[posicao].tamanhoDinamico; i++) {
            vetorAux[i] = vetorPrincipal[posicao].vetorDinamico[i];
        }

        // Insertion sort em vetorAux (até tamanhoDinamico)
        for (i = 1; i < vetorPrincipal[posicao].tamanhoDinamico; i++) {
            int chave = vetorAux[i];
            j = i - 1;
            while (j >= 0 && vetorAux[j] > chave) {
                vetorAux[j + 1] = vetorAux[j];
                j--;
            }
            vetorAux[j + 1] = chave;
        }
            
        return SUCESSO;
    }
} // FUNÇÃO VALIDADA OK!

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i,j,k;
    int verificador_estrutura = 0;
    k = 0;
    for(i=0;i < TAM; i++){
        if (vetorPrincipal[i].vetorDinamico != NULL && vetorPrincipal[i].tamanhoDinamico > 0){
            verificador_estrutura = 1;
            break;
        }
            
    }
    if (verificador_estrutura == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        for(i=0; i < TAM; i++)
            for(j = 0; j < vetorPrincipal[i].tamanhoDinamico; j++){
                vetorAux[k] = vetorPrincipal[i].vetorDinamico[j];
                k++;         
            }                
    }
    
    return SUCESSO;
} // função validada OK!

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i,j,k,aux;
    int verificador_estrutura = 0;
    k = 0;
    for(i=0;i < TAM; i++){
        if (vetorPrincipal[i].vetorDinamico != NULL && vetorPrincipal[i].tamanhoDinamico > 0){
            verificador_estrutura = 1;
            break;
        }
    }
    if (verificador_estrutura == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        for(i=0; i < TAM; i++)
            for(j = 0; j < vetorPrincipal[i].tamanhoDinamico; j++){
                vetorAux[k] = vetorPrincipal[i].vetorDinamico[j];
                k++;         
            }                
    }

    for (i = 1; i < k; i++) {
    aux = vetorAux[i];
    j = i - 1;

    while (j >= 0 && vetorAux[j] > aux) {
        vetorAux[j + 1] = vetorAux[j];
        j--;
    }
    vetorAux[j + 1] = aux;
}
    return SUCESSO;
} // Função validada OK!

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    posicao--;
    int * PonteiroVetor;
    int tamanhoAtual = novoTamanho + vetorPrincipal[posicao].capacidade;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if(tamanhoAtual > 20)
        return SEM_ESPACO_DE_MEMORIA;
    else if(tamanhoAtual < 1)
        return NOVO_TAMANHO_INVALIDO;
    else if(vetorPrincipal[posicao].vetorDinamico == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else{
        //realocar o vetor dinâmico para o tamanho passado pelo usuário
        PonteiroVetor = realloc(vetorPrincipal[posicao].vetorDinamico, tamanhoAtual * sizeof(int)); // necessário corrigir o realloc pois está dando erro.
        if (PonteiroVetor == NULL)
            return SEM_ESPACO_DE_MEMORIA;
        vetorPrincipal[posicao].vetorDinamico = PonteiroVetor;
        vetorPrincipal[posicao].capacidade = tamanhoAtual;
        if (vetorPrincipal[posicao].tamanhoDinamico > tamanhoAtual)
            vetorPrincipal[posicao].tamanhoDinamico = tamanhoAtual;
        return SUCESSO;
    }
        
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao--;
    int num;
    if (posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao].vetorDinamico == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else if (vetorPrincipal[posicao].tamanhoDinamico == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;
    else
      return vetorPrincipal[posicao].tamanhoDinamico;
} //

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote(Lista *Lista) {
    int i, j;
    Lista->inicio = NULL;
    No *ultimo = NULL;

    int temElemento = 0;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < vetorPrincipal[i].tamanhoDinamico; j++) {
            No *novo = malloc(sizeof(No));
            novo->conteudo = vetorPrincipal[i].vetorDinamico[j];
            novo->prox = NULL;

            if (Lista->inicio == NULL) {
                Lista->inicio = novo;
            } else {
                ultimo->prox = novo;
            }

            ultimo = novo;
            temElemento = 1;
        }
    }

    if (!temElemento) {
        return NULL;
    }

    return Lista->inicio;
}


/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int i = 0;
    while (inicio!=NULL){
       vetorAux[i] = inicio->conteudo;
        i++;
        inicio = inicio->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual = *inicio;
    No *proximo;

    while (atual != NULL){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    int i;
    for (i=0 ; i < TAM;i++){
        vetorPrincipal[i].vetorDinamico = NULL;   
        vetorPrincipal[i].tamanhoDinamico = 0;
        vetorPrincipal[i].capacidade = 0;   
    }   
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    int i;
    for (i=0 ; i < TAM;i++){
        if (vetorPrincipal[i].vetorDinamico != NULL){
             free(vetorPrincipal[i].vetorDinamico);
             vetorPrincipal[i].vetorDinamico = NULL;
        }   
        vetorPrincipal[i].tamanhoDinamico = 0;
        vetorPrincipal[i].capacidade = 0;   
    }
}

