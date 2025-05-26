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
        for(int j = i; texto[j] != '\0';j++){
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
    int Tam_Busca,Tam_Texto,i,j,k;
    int Verificador_Acento = 0;
    int encontrou,posicao;
    char aux;

        
    Tam_Busca = strlen(strBusca);
    Tam_Texto = strlen(strTexto);
 
    // verificar se busca possui acento
    for(i=0;i < Tam_Busca;i++){
      if(strBusca[i] == -61){
        Verificador_Acento = 1;
        break;
      }
    }
    //retirando -61 da busca e do texto para que o código realize a verificação corretamente.
    // Retirar o byte -61 de strBusca
    for(i = 0; strBusca[i] != '\0'; i++) {
        if(strBusca[i] == -61) {
            for(j = i; strBusca[j] != '\0'; j++) {
                strBusca[j] = strBusca[j + 1];
            }
            i--; // Volta uma posição para reavaliar o próximo caractere
        }
    }
  

    // Retirar o byte -61 de strTexto
    for(i = 0; strTexto[i] != '\0'; i++) {
        if(strTexto[i] == -61) {
            for(j = i; strTexto[j] != '\0'; j++) {
                strTexto[j] = strTexto[j + 1];
            }
            i--;
        }
    }

    Tam_Busca = strlen(strBusca);
    Tam_Texto = strlen(strTexto);

    // iniciando processo de comparação da busca com texto
    j = 0;
    k = 0;
    for(i=0; i <= Tam_Texto - Tam_Busca;i++){
        encontrou = 1;
        posicao = i;
        for(j = 0;j < Tam_Busca; j++){
          if(strTexto[i+j]!=strBusca[j]){
            encontrou = 0;
            break;
          }
        }
        if(encontrou == 1){
          qtdOcorrencias++;
          posicoes[k] = posicao + 1;
          k++;
          posicoes[k] = posicao + Tam_Busca;
          k++;
        }      
    }
    return qtdOcorrencias;
}

void testQ4()
{
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 5);
    printf("%d\n", posicoes[1] == 8);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 37);

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "mui");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n", posicoes[0] == 16);
    printf("%d\n", posicoes[1] == 18);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 36);
    printf("%d\n", posicoes[4] == 52);
    printf("%d\n", posicoes[5] == 54);
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
    int qtdOcorrencias = 0;
    int Tam_Busca,Tam_numero,i,divisor,numero_decrementado;
    int multiplicador_busca = 1;
    int multiplicador_numero = 1;
    char convert_int[200];

    sprintf(convert_int, "%d", numerobusca);
    Tam_Busca = strlen(convert_int);

    sprintf(convert_int, "%d", numerobase);
    Tam_numero = strlen(convert_int);

    for(i=0; i < Tam_Busca; i++){
      // coleta o tamanho do numero buscado para que assim, possa ser quebrado o numero base corretamente
      multiplicador_busca = multiplicador_busca * 10;
    }

    for(i=0; i < Tam_numero; i++){
    // coleta o tamanho do numero buscado para que assim, possa ser quebrado o numero base corretamente
    multiplicador_numero = multiplicador_numero * 10;
    }
    multiplicador_numero = multiplicador_numero/multiplicador_busca;

   numero_decrementado = numerobase;
    while (numero_decrementado != 0)
    {
      if (multiplicador_numero == 0)
            break;
      divisor = numero_decrementado/multiplicador_numero;
      numero_decrementado = numero_decrementado%multiplicador_numero;
       if (multiplicador_busca != 0)
        multiplicador_numero = multiplicador_numero / multiplicador_busca;
    else
        break;

      if(divisor == numerobusca){
        qtdOcorrencias++;
      }
    }
    return qtdOcorrencias;
    // voce vai verificar o numero que voce quer verificar a repetição. A partir dai voce precisa identificar se o numero é unidade, dezena, centena, etc. e a partir dai começar a quebra do mumero principal dividindo o numero pelo vaor unitário do numero que voce quer verificar repetição, e pegar o percent da divisão

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

 int q7(char matriz[8][10], char palavra[6])
 {
     int achou,contador,hor_esquerda,hor_direita;
     int Tam_Busca;
     int i,j,k;
    
     achou = 0;
     Tam_Busca = strlen(palavra);
     contador = 0;
     k = 0;
     hor_esquerda = 0;
     // verificando a partir da horizontal, iniciando da direita para esquerda da linha
     for (i=0;i < 8;i++){
      for(j = 9; j >= Tam_Busca - 1; j--){
        if(palavra[k] == matriz[i][j]){
          k++;
          contador++;
        }
        else{
         if (palavra[0] == matriz[i][j]) {
          k = 1;
          contador = 1;
          } 
          else {
            k = 0;
            contador = 0;
          }
        }
       }
       if(contador == Tam_Busca){
        hor_esquerda = 1;
        break;
       }
    k = 0;
    contador = 0;
     }
  //-------------------------------------------------------------------------------------------------------   
     contador = 0;
     k = 0;
     hor_direita = 0;
     // verificando a partir da horizontal, iniciando da esquerda para direita da linha
     for(i=0; i<8; i++){
        for(j = 0; j <= 10 - Tam_Busca; j++){
          if(palavra[k] == matriz[i][j]){
            k++;
            contador++;
          }
          else{
            if (palavra[0] == matriz[i][j]) {
              k = 1;
              contador = 1;
            } 
              else {
                k = 0;
                contador = 0;
              }
        }
        }
        if(contador == Tam_Busca){
          hor_direita = 1;
          break;          
        }
        k = 0;
        contador = 0;
     }
//-------------------------------------------------------------------------------------------------------
     int vert_cima = 0;
     contador = 0;
     k = 0;
     // verificando a partir da vertical , iniciando de cima para baixo
     for(j=0;j<10;j++){
        for(i = 0; i <= 8 - Tam_Busca; i++){
          if(palavra[k]==matriz[i][j]){
            k++;
            contador++;
          }
          else{
            if (palavra[0] == matriz[i][j]) {
              k = 1;
              contador = 1;
              } 
              else {
                k = 0;
                contador = 0;
              }
          } 
        }
        if(contador == Tam_Busca){
          vert_cima = 1;
          break;
        }
        k = 0;
        contador = 0;
     }
//-------------------------------------------------------------------------------------------------------
     int vert_baixo = 0;
     contador = 0;
     k = 0;
     // verificando a partir da vertical , iniciando de baixo para cima
     for(j=0;j<10;j++){
        for(i = 7; i >= Tam_Busca - 1; i--){
          if(palavra[k]==matriz[i][j]){
            k++;
            contador++;
          }
          else{
            if (palavra[0] == matriz[i][j]) {
              k = 1;
              contador = 1;
              } 
              else {
                k = 0;
                contador = 0;
              }
          } 
        }
        if(contador == Tam_Busca){
          vert_baixo = 1;
          break;
        }
        k = 0;
        contador = 0;
     }
//-------------------------------------------------------------------------------------------------------
     int diag_sup_esquerda = 0;
     contador = 0;
     k = 0;
    // verificando a partir da diagonal superior, da esquerda para direita
    for(i=0;i<8;i++){
      for(j=0;j<10;j++){
        if(i!=j) continue;
        if(palavra[k] == matriz[i][j]){
          contador++;
          k++;
        }
          else{
            if (palavra[0] == matriz[i][j]) {
              k = 1;
              contador = 1;
              } 
              else {
                k = 0;
                contador = 0;
              }
          } 
        }
      if(contador == Tam_Busca){
        diag_sup_esquerda = 1;
        break;
      }
      k = 0;
      contador = 0;
    }
  //-------------------------------------------------------------------------------------------------------
    int diag_sup_direita = 0;
    contador = 0;
    k = 0;
  // verificando a partir da diagonal superior, da direita para esquerda
    for(i=0;i<8;i++){
      for(j=9;j>=0;j--){
          if(i!=j)continue;

          if(palavra[k]==matriz[i][j]){
            k++;
            contador++;
          }
          else{
            if (palavra[0] == matriz[i][j]) {
              k = 1;
              contador = 1;
              } 
              else {
                k = 0;
                contador = 0;
              }
          } 
      }
      if(contador == Tam_Busca){
        diag_sup_direita = 1;
        break;
      }
      k = 0;
      contador = 0;
    }
//-------------------------------------------------------------------------------------------------------
   // verificando a partir da diagonal inferior, da esquerda para direita
   int diag_inf_esquerda = 0;
   contador = 0;
   k = 0;
   for(i=7;i>=0;i--){
      for(j=0;j<10;j++){
        if(i!=j) continue;

        if(palavra[k]==matriz[i][j]){
          k++;
          contador++;
        }
        else{
            if (palavra[0] == matriz[i][j]) {
              k = 1;
              contador = 1;
              } 
              else {
                k = 0;
                contador = 0;
              }
          } 
      }
      if(contador == Tam_Busca){
        diag_inf_esquerda = 1;
        break;
      }
      k = 0;
      contador = 0;
   }
//-------------------------------------------------------------------------------------------------------
   // verificando a partir da diagonal inferior, da direita para esquerda
   int diag_inf_direita = 0;
   k = 0;
   contador = 0;
   for(i=7;i>=0;i--){
      for(j=9;j>=0;j--){
        if(i!=j) continue;

        if(palavra[k]==matriz[i][j]){
          k++;
          contador++;
        }
        else{
            if (palavra[0] == matriz[i][j]) {
              k = 1;
              contador = 1;
              } 
              else {
                k = 0;
                contador = 0;
              }
          } 
      }
      if(contador == Tam_Busca){
        diag_inf_direita = 1;
        break;
      }
      k = 0;
      contador = 0;
   }

   if(diag_inf_direita == 1 || diag_inf_esquerda == 1 || diag_sup_direita == 1 || diag_sup_esquerda == 1){
    achou = 1;
   }
  if(hor_direita == 1 || hor_esquerda == 1 || vert_baixo == 1 || vert_cima == 1){
    achou = 1;
  }

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


void testQ6()
{
    printf("%d\n", q6(34567368, 3) == 2);
    printf("%d\n", q6(34567368, 4576) == 0);
    printf("%d\n", q6(3539343, 3) == 4);
    printf("%d\n", q6(3539343, 39) == 1);
}


void testQ7()
{
    char matrix[8][10] = {
        { 'Q', 'M', 'J', 'D', 'L', 'A', 'Z', 'F', 'C', 'R' },
        { 'N', 'B', 'Y', 'G', 'P', 'S', 'K', 'H', 'E', 'X' },
        { 'V', 'O', 'W', 'U', 'T', 'I', 'Z', 'A', 'L', 'C' },
        { 'M', 'Q', 'B', 'D', 'N', 'F', 'R', 'J', 'G', 'E' },
        { 'H', 'S', 'K', 'T', 'U', 'X', 'W', 'O', 'P', 'Y' },
        { 'C', 'Z', 'A', 'I', 'L', 'M', 'V', 'G', 'N', 'B' },
        { 'D', 'F', 'E', 'H', 'S', 'K', 'J', 'Q', 'R', 'T' },
        { 'U', 'X', 'Y', 'W', 'V', 'O', 'P', 'N', 'M', 'L' }
    };
    char stringBusca [6] = { 'F', 'E', 'H', 'S', 'K'};
    printf("%d\n", q7(matrix, stringBusca) == 1);
    strcpy(stringBusca, "KJQRT");
    printf("%d\n", q7(matrix, stringBusca) == 1);
    strcpy(stringBusca, "AATOK");
    printf("%d\n", q7(matrix, stringBusca) == 0);
    strcpy(stringBusca, "LTBON");
    printf("%d\n", q7(matrix, stringBusca) == 1);

}


int main(){
printf("QUESTÃO 1:\n");
testQ1();
printf("\n\nQUESTÃO 2:\n");
calculaEImprimeDiferenca();
printf("\nQUESTÃO 3:\n");
testQ3();
printf("\nQUESTÃO 4:\n");
testQ4();
printf("\nQUESTÃO 5:\n");
testQ5();
printf("\nQUESTÃO 6:\n");
testQ6();
printf("\nQUESTÃO 7:\n");
testQ7();
printf("\n");

return 0;

}


