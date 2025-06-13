#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
int inteiro;
int *p_inteiro;
char caracter, palavra[10];
char *p_caracter;

float num_float;
float *p_float;
double num_double;
double *p_double;

p_inteiro = &inteiro;
p_caracter = &caracter;
char *p_string = palavra;
p_float = &num_float;
p_double = &num_double;

printf("VARIÁVEIS PRIMITIVAS: \n");
printf("Digite um número inteiro: ");
scanf("%d",&inteiro);

printf("Digite um caractere: ");
scanf(" %c",&caracter);

printf("Digite uma string: ");
scanf(" %s",palavra);

printf("Digite um número float: ");
scanf("%f",&num_float);

printf("Digite um número double: ");
scanf("%lf",&num_double);

printf("\nInteiro: %d\nCaracter: %c\nString: %s\nFloat: %f\nDouble: %lf\n\n",inteiro,caracter,palavra,num_float,num_double);

printf("-----------------------------------------------\n\n");
printf("UTILIZANDO PONTEIRO: ");

printf("Digite um número inteiro: ");
scanf("%d",p_inteiro);

printf("Digite um caractere: ");
scanf(" %c",p_caracter);

printf("Digite uma string: ");
scanf(" %s",p_string);

printf("Digite um número float: ");
scanf("%f",p_float);

printf("Digite um número double: ");
scanf("%lf",p_double);

printf("Inteiro: %d\nCaracter: %c\nString: %s\nFloat: %f\nDouble: %lf\n",*p_inteiro,*p_caracter,p_string,*p_float,*p_double);


return 0;
    
}