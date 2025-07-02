#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char *texto = "ÁáÃãÂâ ÉéÊê ÍíÎî ÓóÔô ÚúÛû";

for(int i = 0; texto[i] != '\0';i++){
    printf("Letra: %c   ,  valor numerico: %i \n",texto[i],texto[i]);
}



    int numero = 12345;
    char buffer[20];

    sprintf(buffer, "%d", numero);
    int qtd_digitos = strlen(buffer);

    printf("Quantidade de dígitos: %d\n", qtd_digitos);
    return 0;


}