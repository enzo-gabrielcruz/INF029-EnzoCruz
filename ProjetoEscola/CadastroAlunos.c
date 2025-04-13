#include <stdio.h>


typedef struct{
int matricula;
char nome[50];
char sexo;
int nascimento;
int cpf;  
}alunos;

int main()
{
  alunos ListaAlunos;
  ListaAlunos.matricula = 202500001;
  
  
  printf("Número de Matrícula: ");
  printf(" %d\n",ListaAlunos.matricula);
  
  printf("Nome do Aluno: ");
  fgets(ListaAlunos.nome,sizeof(ListaAlunos.nome),stdin);

  printf("Sexo: ");
  scanf(" %c",&ListaAlunos.sexo);
  
  printf("Data de Nascimento: ");
  scanf("%d",&ListaAlunos.nascimento);
  
  printf("CPF: ");
  scanf("%d",&ListaAlunos.cpf);
  
}
