// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: ENZO GABRIEL CALADO DA CRUZ
//  email:
//  Matrícula: 20242160020
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "EnzoCruz20242160020.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;
  int maxDias;
  DataQuebrada dq = quebraData(data);

  if (dq.valido == 0){
    return 0;
  }

  if (dq.iMes < 1 || dq.iMes > 12){
    return 0;
  }

  switch (dq.iMes){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:  maxDias = 31;break;
    case 4: case 6: case 9: case 11: maxDias = 30; break;
    case 2: 
      if((dq.iAno % 4 == 0 && dq.iAno % 100 != 0) || (dq.iAno % 400 == 0))
      {
        maxDias = 29;
      }
      else{
        maxDias = 28;
      }
      break;
      
    default:
    return 0;
  }

  if (dq.iDia > maxDias || dq.iDia < 1){
    return 0;
  }

return 1;

}
void testQ1()
{
    char str[11];
    strcpy(str, "29/02/2015");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "29/02/2012");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "9/13/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "45/4/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "/9/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "1a/9/2014");
    printf("%d\n", q1(str) == 0);
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    DataQuebrada dq_Inicial = quebraData(datainicial);
    DataQuebrada dq_Final = quebraData(datafinal);
    int maxDias_inicio;

    switch (dq_Inicial.iMes){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:  maxDias_inicio = 31;break;
    case 4: case 6: case 9: case 11: maxDias_inicio = 30; break;
    case 2: 
      if((dq_Final.iAno % 4 == 0 && dq_Final.iAno % 100 != 0) || (dq_Final.iAno % 400 == 0))
      {
        maxDias_inicio = 29;
      }
      else{
        maxDias_inicio = 28;
      }
      break;
    default:
    break;
  }

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      if(dq_Final.iAno < dq_Inicial.iAno)
      {
        dma.retorno = 4;
        return dma;
      }


    }

      //calcule a distancia entre as datas
      dma.qtdAnos = dq_Final.iAno - dq_Inicial.iAno;
      dma.qtdMeses = dq_Final.iMes - dq_Inicial.iMes;
      dma.qtdDias = dq_Final.iDia - dq_Inicial.iDia;
      
      // se o mes for positivo, consequentemente não será necessário decrementar ano.
      // se dia, mes e ano for maior ou igual a zero, não é necessário realizar verificação
      // se mes for negativo, necessário comparar com os dias para que possamos incrementar 

      if (dma.qtdMeses < 0 ){
        dma.qtdAnos--;
        dma.qtdMeses = 12 + dma.qtdMeses;
      }
      if (dma.qtdDias < 0){
        dma.qtdMeses--;
        dma.qtdDias = dma.qtdDias + maxDias_inicio;
      }

      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }

   void calculaEImprimeDiferenca() {
    // Datas fixas
    char datainicial[] = "12/11/2002";
    char datafinal[] = "22/05/2025";

    DiasMesesAnos resultado = q2(datainicial, datafinal);

    switch (resultado.retorno) {
        case 1:
            printf("Diferença: %d ano(s), %d mes(es), %d dia(s)\n",
                   resultado.qtdAnos, resultado.qtdMeses, resultado.qtdDias);
            break;
        case 2:
            printf("Data inicial inválida.\n");
            break;
        case 3:
            printf("Data final inválida.\n");
            break;
        case 4:
            printf("Data final é menor que a data inicial.\n");
            break;
        default:
            printf("Erro desconhecido ao calcular diferença entre as datas.\n");
            break;
    }
}
    

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int i,j;
    isCaseSensitive = 1;
    // função para remover acentos de vogais
    for(i = 0; texto[i] != '\0';i++){
      if (texto[i] == -61){
        // verificando se o acento está na vogal a;
          if ((texto[i+1] <= -125 && texto[i+1] >= -127) || (texto[i+1] <= -93 && texto[i+1] >= -95)){
            if(texto[i+1] <= -125 && texto[i+1] >= -127){
              texto[i+1] = 'A';
            }
            else texto[i+1] = 'a';
          }
          //verificando se o acento está na vogal e;
          if((texto[i+1] <= -118 && texto[i+1] >= -119) || (texto[i+1] <= -86 && texto[i+1] >= -87)){          
            if(texto[i+1] <= -118 && texto[i+1] >= -119){
              texto[i+1] = 'E';
            }
            else texto[i+1] = 'e';
          }
          // verificando se o acento está na vogal i;
          if((texto[i+1] <= -114 && texto[i+1] >= -115) || (texto[i+1] <= -82 && texto[i+1] >= -83)){          
            if(texto[i+1] <= -114 && texto[i+1] >= -115){
              texto[i+1] = 'I';
            }
            else texto[i+1] = 'i';
          }
          //verificando se o acentto está na vogal o;
          if((texto[i+1] <= -108 && texto[i+1] >= -109) || (texto[i+1] <= -76 && texto[i+1] >= -77)){          
            if(texto[i+1] <= -108 && texto[i+1] >= -109){
              texto[i+1] = 'O';
            }
            else texto[i+1] = 'o';
          }

          if((texto[i+1] <= -101 && texto[i+1] >= -102) || (texto[i+1] <= -69 && texto[i+1] >= -70)){          
            if(texto[i+1] <= -101 && texto[i+1] >= -102){
              texto[i+1] = 'U';
            }
            else texto[i+1] = 'u';
          }
      }
    }
    //retirando a posicao -61, referente ao identificador da vogal com acento
    char aux;
    for(i=0; texto[i] != '\0';i++){
      if(texto[i] == -61){
        for(int j = i; texto[j] != '\0';i++){
          aux = texto[j];
          texto[j] = texto[j+1];
        }
        texto[j-1] = '\0';
      }
    }


    // definindo que se não for case sensitive o programa irá colocar todos os caracteres para maiúsculo
    if(isCaseSensitive != 1){
      for(i = 0; texto[i] != '\0'; i++)
      {
        if(texto[i] >= 97 && texto[i] <= 122)
        {
          texto[i] = texto[i] - 32;
        }
        else continue;
      }
      for(i=0; texto[i]!= '\0';i++){
        if (texto[i]== c){
          qtdOcorrencias = qtdOcorrencias + 1;
        }
      }
    }

    else{
      for(i=0; texto[i]!= '\0';i++){
        if (texto[i]== c){
          qtdOcorrencias = qtdOcorrencias + 1;
        }
      }
    }
    return qtdOcorrencias;
}

void testQ3()
{
    char str[250];
    strcpy(str, "Renato Lima Novais");
    printf("%d\n", q3(str, 'a', 0) == 3);
    printf("%d\n", q3(str, 'b', 0) == 0);
    printf("%d\n", q3(str, 'l', 1) == 0);
    printf("%d\n", q3(str, 'l', 0) == 1);
    printf("%d\n", q3(str, 'L', 0) == 1);
}



/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int Tamanho,multiplicador,PrimeiroNumero,NumSeparado[100],auxDivisao,total,i;
    char convert_int[100];
    // convertendo num para string para verificar quantidade de digitos
    sprintf(convert_int, "%d", num);
    Tamanho = strlen(convert_int);

    multiplicador = 1;
    for(int i=0; i<Tamanho-1;i++){
      multiplicador = 10*multiplicador;
    }
    auxDivisao = num;
    for (i=0; i< Tamanho;i++)
    {
      NumSeparado[i] = auxDivisao % 10; 
      auxDivisao = auxDivisao / 10;
    }
    total = 0;
    for(i=0; i< Tamanho;i++){
      total = (NumSeparado[i]*multiplicador) + total;
      multiplicador = multiplicador/10;
    } 


    return total;
}

void testQ5()
{
    printf("%d\n", q5(345) == 543);
    printf("%d\n", q5(78) == 87);
    printf("%d\n", q5(3) == 3);
    printf("%d\n", q5(5430) == 345);
}


/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
     int achou;
     return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i,key,verificador_int; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

 key = 1;
    for (i = 0; sDia[i] != '\0'; i++) {
        if (sDia[i] < '0' || sDia[i] > '9') key = 0;
    }
    if (!key) return dq;
    dq.iDia = atoi(sDia);

 key = 1;
    for (i = 0; sMes[i] != '\0'; i++) {
        if (sMes[i] < '0' || sMes[i] > '9') key = 0;
    }
    if (!key) return dq;
    dq.iMes = atoi(sMes);

  key = 1;
    for (i = 0; sAno[i] != '\0'; i++) {
        if (sAno[i] < '0' || sAno[i] > '9') key = 0;
    }
  if (!key) return dq;
  dq.iAno = atoi(sAno);
  dq.valido = 1;
  return dq;
}


int main(){
printf("QUESTÃO 1:\n");
testQ1();
printf("\n\nQUESTÃO 2:\n");
calculaEImprimeDiferenca();
printf("\nQUESTÃO 3:\n");
testQ3();
printf("\nQUESTÃO 5:\n");
testQ5();
return 0;

}
