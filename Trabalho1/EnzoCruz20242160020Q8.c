#include <stdio.h>

void TabuleiroPrinter (char tabuleiro[3][3]){
    printf("   1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%c ", 'A' + i);  // A, B, C
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  ---+---+---\n");
    }
}
    
void limparTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';
}
int validarVencedor(char tabuleiro[3][3]) {
    // Verifica linhas e colunas
    for (int i = 0; i < 3; i++) {
        // Verifica linhas
        if (tabuleiro[i][0] != ' ' &&
            tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2]) {
                //se for verdadeiro return 1, se falso return 2
            return (tabuleiro[i][0] == 'X') ? 1 : 2;
        }
        // Verifica colunas
        if (tabuleiro[0][i] != ' ' &&
            tabuleiro[0][i] == tabuleiro[1][i] &&
            tabuleiro[1][i] == tabuleiro[2][i]) {
            return (tabuleiro[0][i] == 'X') ? 1 : 2;
        }
    }

    // Verifica diagonais
    if (tabuleiro[0][0] != ' ' &&
        tabuleiro[0][0] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][2]) {
        return (tabuleiro[0][0] == 'X') ? 1 : 2;
    }

    if (tabuleiro[0][2] != ' ' &&
        tabuleiro[0][2] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][0]) {
        return (tabuleiro[0][2] == 'X') ? 1 : 2;
    }

    // Verifica se ainda há espaços vazios
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] == ' ')
                return 0; // Jogo em andamento

    return 3; // Empate
}

int main() {
char tabuleiro[3][3];
char linha,validador_linha;
int coluna,validador_coluna;
int jog1 = 1,jog2 = 2;
int jogadas = 0;
int lin,col;

limparTabuleiro(tabuleiro);

while(validarVencedor(tabuleiro) == 0 && jogadas <= 9){
    TabuleiroPrinter(tabuleiro);
    validador_coluna = 0;
    validador_linha = 0;

    printf("Jogador 1,informe sua jogada: ");
    while(validador_linha == 0 && validador_coluna == 0){
        scanf(" %c%d",&linha,&coluna);
         lin = linha - 'A';
         col = coluna - 1;
       if(lin < 0 || lin > 2){
        printf("Célula Inválida, tente novamente.\n");
        }
        else validador_linha = 1;

         if(col < 0 || col > 2){
            printf("Célula Inválida, tente novamente.\n");
        }
        else validador_coluna = 1;

        if(tabuleiro[lin][col] != ' '){
            printf("Posição já ocupada, tente novamente!.\n");
            validador_coluna = 0;
            validador_linha = 0;
        }
    }
    tabuleiro[lin][col] = 'X';
    jogadas++;

    TabuleiroPrinter(tabuleiro);
    validador_coluna = 0;
    validador_linha = 0;

    if(validarVencedor(tabuleiro)==1){
        printf("Jogador 1 VENCEDOR!!!\n\n");
        break;
    }

    if(validarVencedor(tabuleiro)==3){
        break;
    }

    

    printf("Jogador 2,informe sua jogada: ");
    while(validador_linha == 0 && validador_coluna == 0){
        scanf(" %c%d",&linha,&coluna);
         lin = linha - 'A';
         col = coluna - 1;
        if(lin < 0 || lin > 2){
        printf("Célula Inválida, tente novamente.\n");
        }
        else validador_linha = 1;

        if(col < 0 || col > 2){
            printf("Célula Inválida, tente novamente.\n");
        }
        else validador_coluna = 1;

        if(tabuleiro[lin][col] != ' '){
            printf("Posição já ocupada, tente novamente!.\n");
            validador_coluna = 0;
            validador_linha = 0;
        }
    }
    tabuleiro[lin][col] = 'O';
    jogadas++;
    
    TabuleiroPrinter(tabuleiro);

       if(validarVencedor(tabuleiro)==2){
        printf("Jogador 2 VENCEDOR!!!\n\n");
        break;
    }
    
    if(validarVencedor(tabuleiro)==3){
        break;
    }

}

   if(validarVencedor(tabuleiro)==3){
        printf("EMPATE !!!\n\n");
    }

return 0;
}



