#include<stdio.h>
#define linhas 10
#define colunas 10


void naviosDiagonal(int tabuleiro[linhas][colunas], int linhaInicio, int colunaInicio, int direção){

    for(int k = 0; k <= 2; k++){
        int i = linhaInicio + k;
        int j = (direção == 1) ? (colunaInicio + k) : (colunaInicio - k);

        if(i >= 0 && i < linhas && j >= 0 && j < colunas){
            tabuleiro[i][j] = 3;
        }
    }
}


int main(){
    int tabuleiro[linhas][colunas] = {0};
    char letras[colunas] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; 
    int contador = 0;

for( int i = 4; i <= 6; i++){
    tabuleiro[i][2] = 3;
}
for(int j = 7; j <= 9; j++){
    tabuleiro[2][j] = 3;
}


naviosDiagonal(tabuleiro, 1, 1, 1);
naviosDiagonal(tabuleiro, 6, 5, 2);


printf("   ");
for(int i = 0; i < colunas; i++){
    printf("%c ", letras[i]);
}

printf("\n");

for(int i = 0; i < linhas; i++){
    printf("%2d ", i);
    for(int j = 0; j < colunas; j++){
        if(tabuleiro[i][j] == 3)
        contador++;
        printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
}

return 0;

 }   
   