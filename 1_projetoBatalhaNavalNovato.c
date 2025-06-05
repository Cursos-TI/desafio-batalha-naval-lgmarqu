#include<stdio.h>

int main(){

    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tamanho = sizeof(linha); // feito um size of para percorrer o array linha de modo que imprima todas as letras. 
    int tabuleiro[10][10];
// criado um for para imprmir todas as letras
    printf(" ");
    printf(" ");
    printf(" ");

    for(int i = 0; i < tamanho; i++){
        printf(" %c", linha[i]);
    }

printf("\n");

    // criado 'for' aninhado para criar as linha e colunas com valores 0
    for(int i = 0; i < 10; i++ ){
            for(int j = 0; j < 10; j++){
                tabuleiro[i][j] = 0;
                if (i == 2 && (j == 4 || j == 5 || j == 6)){ // posicionamneto horizontalmente 
                    tabuleiro [i][j] = 3;
            }
                if(j == 1 && (i == 1 || i == 2 || i == 3)){ // posicionamento vertical
                    tabuleiro[i][j] = 3;
                }    
        }       
    }
    
    // criado 'for' aninhado para representar o talebeiro na tela
        for(int i = 0; i < 10; i++ ){
            printf("%d   ", i);
            for(int j = 0; j < 10; j++){
                printf("%d ", tabuleiro[i][j]);    
            }
    printf("\n");
        }

return 0;
}