#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}no;

void inicializar_lista (no ** Lista){
    *Lista = NULL;
}

void inserir_inicio (no ** Lista, int num){
    no * novo = malloc (sizeof(no));
    novo->valor = num;
    novo->proximo = *Lista;
    *Lista = novo; 
}

void inserir_fim (no ** Lista, int num){
    no * novo = malloc (sizeof(no));
    novo->valor = num;

    if(*Lista == NULL){
        novo->proximo = NULL;
        *Lista = novo;
    }
    else{
        no * aux = *Lista;
        while (aux->proximo != NULL)
            aux = aux->proximo;
        novo->proximo = NULL;
        aux->proximo = novo;
    }
}

void inserir_ordenado (no** Lista, int num){
    no * novo = malloc (sizeof(no));
    novo->valor = num;
    if(*Lista == NULL){
        novo->proximo = NULL;
        *Lista = novo;
    }
    else if ((*Lista)->valor > num){
        novo->proximo = *Lista;
        *Lista = novo;
    }
    else{
        no * aux = *Lista;
        while (aux->proximo != NULL && aux->proximo->valor < num)
            aux = aux->proximo;
        if(aux->proximo == NULL){
            novo->proximo = NULL;
            aux->proximo = novo;
        }
        else{
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }

    }

}

void remover_elemento (no ** Lista, int num){
    no * remove = NULL;

    if (*Lista == NULL){
        printf ("Lista vazia.\n\n");
        return;
    }
   else if((*Lista)->valor == num){
    remove = *Lista;
    (*Lista) = remove->proximo;
    free(remove);
   }
   else{
    no * aux = * Lista;
    while (aux->proximo != NULL && aux->proximo->valor != num)
        aux = aux->proximo;
    if (aux->proximo == NULL)
        printf ("Numero inexistente na lista.\n\n");
    else{
        remove = aux->proximo;
        aux->proximo = remove->proximo;
        free(remove);
    }
   } 

}

void printar (no * Lista){
    no * aux;
    aux = Lista;
    while(aux != NULL){
        printf("%d -> ",aux->valor);
        aux = aux->proximo;
    }
    printf("\n\n");
}

int main(){
int valor,key;
no * Lista;

inicializar_lista(&Lista);

printf("\t\tCriação de Lista:\n");
printf("0 - SAIR\t\t1 - Adicionar no Inicio\t\t 2 - Adicionar no Fim\t\t3 - Inserir Ordenado\t\t4 - Excluir Elemento\t\t5 - Listar ");
scanf("%d",&key);

while(key!=0){
    switch (key){
        case 1:
            printf("Digite o número: ");
            scanf("%d",&valor);
            inserir_inicio(&Lista,valor);
            break;
        case 2:
            printf("Digite o número: ");
            scanf("%d",&valor);
            inserir_fim(&Lista,valor);
            break;
         case 3:
            printf("Digite o número: ");
            scanf("%d",&valor);
            inserir_ordenado(&Lista,valor);
            break;
        case 4:
            printf("Digite o número que deseja remover da lista: ");
            scanf("%d",&valor);
            remover_elemento(&Lista,valor);
            break;
        case 5:
            printar(Lista);
            break;
        case 0:
            break;
        default:
            printf("Opção Inválida.\n");
            break;
        }
        printf("0 - SAIR\t\t1 - Adicionar no Inicio\t\t 2 - Adicionar no Fim\t\t3 - Inserir Ordenado\t\t4 - Excluir Elemento\t\t5 - Listar ");
        scanf("%d",&key);
}


return 0;
}