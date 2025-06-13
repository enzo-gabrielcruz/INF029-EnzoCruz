#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void printer(int a, int b){
    printf("Após troca dos valores entre as variáveis:\n");
    printf("a: %d\nb: %d\n",a,b);
}

int main(){
    int a,b;

    printf("Defina valores inteiros para as seguintes variáveis:\n");
    printf("a: ");
    scanf("%d",&a);
    printf("b: ");
    scanf("%d",&b);

    troca(&a,&b);
    printer(a,b);

    return 0;
}
